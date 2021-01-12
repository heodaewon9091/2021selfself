#include "ros/ros.h"
#include "nav_msgs/OccupancyGrid.h"
#include "nav_msgs/GetMap.h"
#include "nav_msgs/Path.h"
#include "std_msgs/Header.h"
#include "std_msgs/String.h"
#include "nav_msgs/MapMetaData.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/PointCloud.h"
#include "sensor_msgs/PointCloud2.h"
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <queue>
#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <pcl_ros/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/conversions.h>
#include <pcl_ros/transforms.h>
#include <pcl/filters/passthrough.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/point_cloud_conversion.h>
#include <morai_msgs/ERP42Info.h>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Eigen>
#include "std_msgs/Int16.h"
#include <tf/transform_broadcaster.h>

class global_path_plan {
public:
    path_plan();
private:


        // ros
    ros::NodeHandle nh;
    ros::NodeHandle pnh;

    //ros xhdtls

    ros::Publisher local_path_pub;
    ros::Publisher region_state_pub;

    //
    ros::Subscriber pose_sub;
    ros::Subscriber region_state_sub;
    ros::Subscriber gps_sub;

    ros::ServiceClient map_client1
    ros::ServiceClient map_client2;  //~~맵
    ros::ServiceClient map_client3 ;  //~~맵

    nav_msgs::GetMap srv;
    nav_msgs::GetMap srv_plain;
    nav_msgs::GetMap srv_region;
    nav_msgs::OccupancyGrid global_map;                    // 글로벌 맵

    /*! @brief 자기 위치에서 가장 가까운 global path를 publish해주는 함수
    * @param[in] global_path_poses globalpathCallback 받은 전체 global path
    * @param[in] local_path_pub path 보낼 publisher, topic: /local_path
    */

   signalStop_map



}

