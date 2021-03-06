#include "ros/ros.h"
#include "motion/angles_in.h"
#include "motion/angles_out.h"
#include <iostream>
using namespace std;
int motor[10];
void chatterCallback(const motion::angles_in::ConstPtr& msg) //ang_msg object
{
  //ROS_INFO("I heard: [%s]", msg->data.c_str());
  for (int num=0; num<10; num++)
   {
     motor[num] = msg->angle_to_motor_in[num];
   }
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "communicator");
  ros::NodeHandle i;
  ros::NodeHandle o;
  ros::Subscriber sub_ang = i.subscribe("parse_to_motor", 1000, chatterCallback);
  ros::Publisher pub_ang = o.advertise<motion::angles_out>("chatter", 1000);
  ros::Rate loop_rate(50);
  while (ros::ok())
  {
    ros::spinOnce(); //check for incoming messages
    motion::angles_out ang_msg_o;
    
    for (int i=0; i<10; i++)
     {
       ang_msg_o.angle_to_motor_out[i] = motor[i];
     }
    pub_ang.publish(ang_msg_o);
    
    for (int i=0; i<10; i++)
     {
       ROS_INFO("%f",ang_msg_o.angle_to_motor_out[i]);
     }

    loop_rate.sleep();
  }
  return 0;
}

