#include "ros/ros.h"
#include "ros_robot/Active.h"
#include "serial/serial.h"
void chatterCallback(const ros_robot::Active::ConstPtr& msg)
{
  ROS_INFO("listener got: [%d %d]", msg->direction, msg->speed);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("cmd_vel", 1000, chatterCallback);
  ros::spin();

  return 0;
}
