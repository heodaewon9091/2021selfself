#include <ros/ros.h>

#include "global_path_planner/local_path_header.h"

local_path_plan::local_path_plan(): nh(""), pnh("~")
{
private:
  void obstacleCallback(const geometry_msgs::PoseWithCovariance::ConstPtr &msg);
  void traffic_sign_Callback(const std_msgs::StringConstPtr &msg);
  void traffic_light_Callback(const std_msgs::StringConstPtr &msg)
  void laneCallback(const std_msgs::StringConstPtr &msg);


  //publisher 정의
  local_path_pub = nh.advertise<nav_msgs::Path>("local_path", 1);
  region_state_pub = nh.advertise<std_msgs::String>("region_state",1);
  //subscriber 정의
  ros::Subscriber obstacle_sub = nh.subscribe("/state",10,obstacleCallback);
  ros::Subscriber lane_sub = nh.subscribe("/Perception/Localization/LocalPose", 10, laneCallback);//topic 타입 조정 필요
  ros::Subscriber trffic_light_sub = n.subscribe("/perception/Detection/TrafficSign", 10, traffic_sign_Callback);
  ros::Subscriber trffic_region_state_sub = n.subscribe("/traffic_region_state", 10, traffic_light_Callback);


  //parameter ---->pnh노드 핸들러 사용

}



void local_path_plan::obstacleCallback(const sensor_msgs::PointCloud2ConstPtr &scan)
{
  //sensor_msgs/PointCloud2 data 데이터를 pcl/PointCloud데이터로 변환
  pcl::fromROSMsg(*scan, kcity_planner.obstacle_pcl);
}

//trfficstate 저장
void local_path_plan::traffic_sign_Callback(const std_msgs::StringConstPtr &msg)
{
  trffic_state_string = msg->data.c_str();
  kcity_planner.trffic_sign_string = msg->data.c_str();
}

void local_path_plan::traffic_light_Callback(const std_msgs::StringConstPtr &msg)
{
  trffic_state_string = msg->data.c_str();
  kcity_planner.traffic_light_state = msg->data.c_str();
}

void local_path_plan::laneCallback(const std_msgs::StringConstPtr &msg)
{
  //차선 way point 받는 곳
}