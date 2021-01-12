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

class local_path_plan {
public:
    path_plan();
private:
    void obstacleCallback(const sensor_msgs::PointCloud2ConstPtr &scan);
    void traficCallback(const std_msgs::StringConstPtr &msg);
    void laneCallback(const std_msgs::StringConstPtr &msg);  //매개변수 타입 조정필요

    ros::Subscriber trffic_light_sub;
    ros::Subscriber obstacle_sub;
    ros::Subscriber lane_sub ;//topic 타입 조정 필요
    ros::Subscriber trffic_region_state_sub;
}
