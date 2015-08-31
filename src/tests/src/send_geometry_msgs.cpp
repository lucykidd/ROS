#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "velocitySender");

  ros::NodeHandle n;

  ros::Publisher velocity_pub = n.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 10);

  ros::Rate loop_rate(1);

  while(ros::ok())
  {
    geometry_msgs::Twist velocity;

    velocity.angular.z = 1.5;
    velocity.linear.x = 5;

    velocity_pub.publish(velocity);
  }

}
