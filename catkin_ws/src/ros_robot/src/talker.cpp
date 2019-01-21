#include "ros/ros.h"
#include "ros_robot/Active.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<ros_robot::Active>("cmd_vel", 1000);
  
  ros_robot::Active act;
  ros::Rate loop_rate(10);
  int count = 0;
  while (ros::ok())
  {
      act.speed++;
      act.direction++;
      chatter_pub.publish(act);

      ros::spinOnce();
      loop_rate.sleep();
  }

  return 0;
}
