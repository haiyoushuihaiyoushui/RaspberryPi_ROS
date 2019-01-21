#include <stdio.h>
#include <string.h>
#include "ros/ros.h"
#include "serial/serial.h"
#include "ros_robot/Active.h"
#include "std_msgs/String.h"

serial::Serial ser;

unsigned char checksum(unsigned char *addr, int count)	//count字节数, 计算8位校验和
{
	short sum = 0;

    while (count > 1)
	{
        sum += *(unsigned char *)addr++;
        count -= 1;
    }   

    if (count > 0)
	{ 
        char left_over[2] = {0};
        left_over[0] = *addr;
        sum += * (unsigned char *)left_over;
    }   
    while (sum >> 8)
	{
		sum = (sum & 0xff) + (sum >> 8);
	}
	
	return ~sum;
}

void send_data(unsigned char *data, int count)
{
    data[count-2] = checksum(data, count);
    ROS_INFO("send %s", data);
    ser.write((char *)data);
}

void write_callback(const ros_robot::Active::ConstPtr &msg)
{
    char data[24] = {0};
    int data_len = 0;
    memset(data, 0, sizeof(data));
    sprintf(data, "K%d%d%d S", msg->direction, msg->speed, msg->ptz);
    data_len = strlen(data);
    data[data_len-2] = 0x00;
    send_data((unsigned char *)data, data_len);
}

int main(int argc, char **argv)
{
    int receive_len = 0;
    ros::init(argc, argv, "ser");
    ros::NodeHandle nh;
    ros::Subscriber write_sub = nh.subscribe("cmd_vel", 1000, write_callback);
    
    ros::Publisher read_pub = nh.advertise<std_msgs::String>("listener", 1000);

    try
    {
        ser.setPort("/dev/serial/by-id/usb-1a86_USB2.0-Serial-if00-port0");
        ser.setBaudrate(115200);
        serial::Timeout to = serial::Timeout::simpleTimeout(1000);
        ser.setTimeout(to);
        ser.open();
    }
    catch (serial::IOException &e)
    {
        ROS_ERROR("Unable to open port");
        return -1;
    }

    if (ser.isOpen())
    {
        ROS_INFO("Serial initialized");
    }
    else
    {
        return -1;
    }
    
    ros::Rate loop_rate(50);
    while (ros::ok())
    {
        ros::spinOnce();
  	
        try
	    {
  	        if (ser.available())
            {
                std_msgs::String resault;
                resault.data = ser.read(ser.available());
                receive_len = resault.data.length(); 
                ROS_INFO("read %s", resault.data.c_str());
                if (0x00 != checksum((unsigned char *)resault.data.c_str(), receive_len))
                {
                    continue;
                }
                else
                {
                    resault.data = resault.data.substr(1, receive_len-3);
                    read_pub.publish(resault);
                }
            }	  
	    }
	    catch (serial::IOException &e)
	    {
	        ROS_ERROR("READ ERROR");
        }
      
        loop_rate.sleep();
    }
}
    


