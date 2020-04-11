#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <stdio.h>

int main(int argc, char **argv)
{
ros::init(argc, argv,"demo_pub");

ros::NodeHandle node_obj;

ros::Publisher int_pub;

int_pub = node_obj.advertise<std_msgs::Int32>("/numbers",10);
std_msgs::Int32 msg;
ros::Rate loop_rate(10);

int number_count = 0;

while (ros::ok()){
    std_msgs::Int32 msg;
    msg.data = number_count;
    // ROS_INFO("%d",msg.data);
    int_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++number_count;
}
return 0;
}