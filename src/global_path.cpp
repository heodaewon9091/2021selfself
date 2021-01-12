#include <ros/ros.h>

#include "path_planning/global_path.cpp"


global_path_plan::global_path_plan(): nh(""), pnh("~")
{
  void poseCallback(const geometry_msgs::PoseWithCovariance::ConstPtr &msg);
  
  //publisher 정의
  local_path_pub = nh.advertise<nav_msgs::Path>("local_path", 1);
  region_state_pub = nh.advertise<std_msgs::String>("region_state",1);
  //subscriber 정의
  ros::Subscriber region_state_sub = nh.subscribe("/state",10,stateCallback);
  ros::Subscriber pose_sub = nh.subscribe("/Perception/Localization/LocalPose", 10, poseCallback);

  //서비스 파라미터 정의
  ros::ServiceClient map_client1 = nh.serviceClient<nav_msgs::GetMap>("/global_map/static_map");
  nav_msgs::GetMap srv;
  ros::ServiceClient map_client2 = nh.serviceClient<nav_msgs::GetMap>("/plain_map/static_map");
  nav_msgs::GetMap srv_plain;
  ros::ServiceClient map_client3 = nh.serviceClient<nav_msgs::GetMap>("/region_map/static_map");
  nav_msgs::GetMap srv_region;

  //parameter ---->pnh노드 핸들러 사용

  

}

void global_path_plan::poseCallback(const geometry_msgs::PoseWithCovariance::ConstPtr &msg)
{
  kcity_planner.pose_count=1;

  //utm에서 받아온 pose로 현재pose 업데이트
  std::queue<geometry_msgs::PoseWithCovariance::ConstPtr> temp_q;
  temp_q.push(msg);
  currentPose = temp_q.front();
  kcity_planner.carpose.covariance = msg->covariance;
  kcity_planner.carpose.pose = msg->pose;
  kcity_planner.carpose.pose.position.x -= 302533.174487;
  kcity_planner.carpose.pose.position.y -= 4124215.34631;
  
  //gps상태 check
  // if (msg->covariance[0] > 1.0 || msg->covariance[7] > 1.0 || msg-> covariance[14] > 2.0)
  // {
  //   kcity_planner.gps_stable = "unstable";
  //     ROS_INFO("GPS unstable");

  // }
  kcity_planner.gps_stable = "stable";
  kcity_planner.crrX = currentPose->pose.position.x - 302533.174487;
  ;
  kcity_planner.crrY = currentPose->pose.position.y - 4124215.34631;
  ;

  temp_q.pop();
}

//state 저장
void path_plan::stateCallback(const std_msgs::StringConstPtr &msg)
{
  state_string = msg->data.c_str();
}