/*

g++ talker.cpp -o talker -I /opt/ros/kinetic/include/ -L /opt/ros/kinetic/lib/  -lrosconsole -lroscpp -lroscpp_serialization -lrostime

*/
#include <ros/ros.h>
#include <std_msgs/String.h>

#include<sstream>
#include<iostream>

int main(int argc,char** argv)
{ros::init(argc,argv,"Talker");
ros::NodeHandle n;
ros::Publisher chatter_pub=n.advertise<std_msgs::String>("chatter",1000);
ros::Rate loop_rate(10);
int count=0;
while(ros::ok())
{std_msgs::String msg;
	
	std::stringstream ss;
	ss<<"Hello World"<<count;
	msg.data=ss.str();

	ROS_INFO("%s",msg.data.c_str());
	chatter_pub.publish(msg);
	ros::spinOnce();
loop_rate.sleep();
++count;

}
	

}