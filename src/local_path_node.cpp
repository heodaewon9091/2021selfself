#include <ros/ros.h>

#include "path_planning/local_path.cpp"

int main(int argc, char** argv)
{
    ros::init(argc,argv,"path_plan_node");
    path_plan kcity_planner;
    if(kcity_planner.globalPath_loaded){
    switch (kcity_planner.currentstate)
    {
    case GLOBAL_PATH_TRACKING:

      //draw pcl utm
      //lane watch dog
      //
      kcity_planner.makeTF();
      kcity_planner.globalPathTracking(globalMapPoses, local_path_pub); // gp추종      
      kcity_planner.checkState(region_state_pub);                                         //현재 state 체크하기
      kcity_planner.drawStateMarker(stateMarker_pub);
      //check state
      break;

    case STOP_READY:
      //draw pcl utm
      //check traffic sign & sign_flag
      //check obstacle & obs_flag
      //if flag == 1 change state to STOP
      kcity_planner.makeTF();
      kcity_planner.globalPathTracking(globalMapPoses, local_path_pub);
      kcity_planner.checkState(region_state_pub); //현재 state 체크하기
      kcity_planner.drawStateMarker(stateMarker_pub);
      break;

    case TRAFFIC_LEFT:
      //draw pcl utm
      //check traffic sign & sign_flag
      //check obstacle & obs_flag
      //if flag == 1 change state to STOP
      kcity_planner.makeTF();
      kcity_planner.globalPathTracking(globalMapPoses, local_path_pub);
      kcity_planner.checkState(region_state_pub); //현재 state 체크하기
      kcity_planner.drawStateMarker(stateMarker_pub);
      break;

    case STOP:
      //draw pcl utm
      //(check sign *OR* Obstacle) and change flag
      kcity_planner.makeTF();
      kcity_planner.checkState(region_state_pub); //현재 state 체크하기
      kcity_planner.drawStateMarker(stateMarker_pub);
      //
      break;
    case PARKING_READY:
      kcity_planner.makeTF();
      kcity_planner.globalPathTracking(globalMapPoses, local_path_pub);
      kcity_planner.checkState(region_state_pub); //현재 state 체크하기
      kcity_planner.drawStateMarker(stateMarker_pub);
      //decrease velocity
      //find empty parking space
      //if find space change state to PARKING
      break;

    case PARKING:
      kcity_planner.makeTF();
      kcity_planner.checkState(region_state_pub); //현재 state 체크하
      kcity_planner.drawStateMarker(stateMarker_pub);
      //follow parking path (while get checkpoint)
      //delay 10s
      //follow paring path (while get checkpoint)
      //parkingEndFlag = 1, chage state to GLOBAL_PATH_TRACKING
      break;
    case OBS_READY:
      kcity_planner.makeTF();
      kcity_planner.outbreakStopCheck();
      kcity_planner.checkState(region_state_pub); //현재 state 체크하
      kcity_planner.drawStateMarker(stateMarker_pub);
      kcity_planner.globalPathTracking(globalMapPoses, local_path_pub);
      break;

    case OBSTACLE_AVOIDANCE_READY:

      kcity_planner.makeTF();
      kcity_planner.obstacleAvoidance(globalMapPoses,local_costmap_pub,local_path_pub);
      kcity_planner.checkState(region_state_pub); //현재 state 체크하
      kcity_planner.drawStateMarker(stateMarker_pub);
      kcity_planner.globalPathTracking(globalMapPoses, local_path_pub);
      break;
    case SHORT_OBSTACLE_READY:

      kcity_planner.makeTF();
      kcity_planner.obstacleAvoidance(globalMapPoses,local_costmap_pub,local_path_pub);
      kcity_planner.checkState(region_state_pub); //현재 state 체크하
      kcity_planner.drawStateMarker(stateMarker_pub);
      kcity_planner.globalPathTracking(globalMapPoses, local_path_pub);
      break;
    default:
      kcity_planner.makeTF();
      kcity_planner.globalPathTracking(globalMapPoses, local_path_pub);
      kcity_planner.checkState(region_state_pub); //현재 state 체크하기
      kcity_planner.drawStateMarker(stateMarker_pub);
      break;
    }
   }
    // local_path_pub.publish(temp_path);
    // temp_local_map.data = temp_data;
    // local_costmap.publish(temp_local_map);

    r.sleep();
    ros::spinOnce();
  }
    ros::spin();
    return 0;
}
