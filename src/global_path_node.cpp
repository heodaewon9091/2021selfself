#include <ros/ros.h>

#include "path_planning/global_path_header.h"

int main(int argc, char** argv)
{
    ros::init(argc,argv,"path_plan_node");
    path_plan kcity_planner;
   while (ros::ok())
  {
    if (kcity_planner.signalStopMap_loaded == false)
    {
      if (map_client3.call(srv_signalStop))
      {
        cout << "signalStop_call!" << endl;
        kcity_planner.signalStop_map = srv_signalStop.response.map;
        kcity_planner.signalStop_map.data = srv_signalStop.response.map.data;
        //cout << signalStop_map.info.width << " x " << signalStop_map.info.height << endl;
        kcity_planner.signalStopMap_loaded = true;
        std::string file_path = ros::package::getPath("global_path_planner");
        kcity_planner.signalStop_image = cv::imread(file_path + "/map_data/Signal_Stop_Final" + ".png", 1);
        //kcity_planner.specific_traffic_signalStop_image = cv::imread(file_path + "/map_data/only_left.png", 1);
      }
      else
      {
        cout << "failed to load region map!" << endl;
        r.sleep();
        continue;
      }
    }
	  if (kcity_planner.obsMap_loaded == false)
    {
      if (map_client4.call(srv_obs))
      {
        cout << "obs_call!" << endl;
        kcity_planner.obs_map = srv_obs.response.map;
        kcity_planner.obs_map.data = srv_obs.response.map.data;
        //cout << obs_map.info.width << " x " << obs_map.info.height << endl;
        kcity_planner.obsMap_loaded = true;
        std::string file_path = ros::package::getPath("global_path_planner");
        kcity_planner.obs_image = cv::imread(file_path + "/map_data/DYNAMIC_OBS_REGION_FINAL" + ".png", 1);
        //kcity_planner.specific_traffic_obs_image = cv::imread(file_path + "/map_data/only_left.png", 1);
      }
      else
      {
        cout << "failed to load obsMap map!" << endl;
        r.sleep();
        continue;
      }
    }
    if (kcity_planner.regionMap_loaded == false)
    {
      if (map_client3.call(srv_region))
      {
        cout << "region_call!" << endl;
        kcity_planner.region_map = srv_region.response.map;
        kcity_planner.region_map.data = srv_region.response.map.data;
        //cout << region_map.info.width << " x " << region_map.info.height << endl;
        kcity_planner.regionMap_loaded = true;
        std::string file_path = ros::package::getPath("global_path_planner");
        kcity_planner.region_image = cv::imread(file_path + "/map_data/REGION_MAP_VER_FINAL" + ".png", 1);
        //kcity_planner.specific_traffic_region_image = cv::imread(file_path + "/map_data/only_left.png", 1);
      }
      else
      {
        cout << "failed to load region map!" << endl;
        r.sleep();
        continue;
      }
    }
    // global_map을 서비스통신을 통해 한번만 받아오기 위함
    if (kcity_planner.globalMap_loaded == false)
    {
      if (map_client1.call(srv))
      {
        cout << "global_call!" << endl;

        //cout << global_map.info.width << " x " << global_map.info.height << endl;
        kcity_planner.global_map = srv.response.map;
        kcity_planner.global_map.data = srv.response.map.data;
        kcity_planner.global_map.info = srv.response.map.info;
        kcity_planner.globalMap_loaded = true;
        kcity_planner.resolution = srv.response.map.info.resolution;

       
      }
      else 
      {
        cout << "failed to load global map!" << endl;
        r.sleep();
        continue;
      }
    }


    if (kcity_planner.plainMap_loaded == false)
    {
      if (map_client2.call(srv_plain))
      {
        cout << "plain_call!" << endl;
        kcity_planner.plain_map = srv_plain.response.map;
        kcity_planner.plain_map.data = srv_plain.response.map.data;
        kcity_planner.plain_map.info = srv_plain.response.map.info;
  
        //cout << plain_map.info.width << " x " << plain_map.info.height << endl;
        kcity_planner.plainMap_loaded = true;
      }
      else
      {
        //cout << "failed to load plain map!" << endl;
        r.sleep();
        continue;
      }
    }


    ros::spin();
    return 0;
}
