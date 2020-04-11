#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <stdio.h>

void number_callback(const std_msgs::Int32::ConstPtr& msg) {
ROS_INFO("Recebido [%d]",msg->data);
}

int main(int argc, char **argv){

ros::init(argc, argv,"demo_sub");

ros::NodeHandle node_obj;

ros::Subscriber int_sub;

int_sub = node_obj.subscribe("/numbers",10,number_callback);

ros::spin();

return 0;

}
