#include "ros/ros.h"
#include "motion/angles_in.h"
#include "Herkulex.h"
#include "std_msgs/Int64.h"
#include "Herkulex.cpp"


int motor;
void chatterCallback(const std_msgs::Int64::ConstPtr& msg) //ang_msg object
{  
  ROS_INFO("YO");
     motor = msg->data;
     ROS_INFO("i received %d",motor);
     
}

int main(int argc, char **argv)
{
 HerkulexClass hc;


  hc.torqueON(19);

  
  ros::init(argc, argv, "communicator");
  ros::NodeHandle i;
  ROS_INFO("hi");
  ros::Subscriber sub_ang = i.subscribe("parse_to_motor", 10, chatterCallback);
  ROS_INFO("RECEI");
  ros::Rate loop_rate(33);
  while (ros::ok())
  {
    ros::spinOnce(); //check for incoming messages
    //motion::angles_out ang_msg_o;
    
       if(motor>100)
{
       ROS_INFO("MOVE");
       hc.moveOne(19, motor, 30, 1);
}
else{ROS_INFO("DIDNT SUB");}     
    //pub_ang.publish(ang_msg_o);
    
    
       ROS_INFO("%d",motor);
     

    loop_rate.sleep();
  }
  return 0;
}

