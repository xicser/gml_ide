#ifndef PLANNING_H
#define PLANNING_H

#include <ros/ros.h>
#include <vector>
#include <geometry_msgs/Point.h>
#include "path_planning/PathParam.h"
#include "path_planning/PathResult.h"

class Planning
{
private:
    ros::NodeHandle nh;
    bool plan_success; // 规划成功
    std::vector<geometry_msgs::Point> goals; // 路径规划的结果
    ros::Subscriber path_result_sub;
    ros::Publisher path_param_pub;
    // 路径规划相关
	void path_result_callback(const path_planning::PathResult::ConstPtr &msg);

public:
    Planning();
    std::vector<geometry_msgs::Point> planning(const geometry_msgs::Point &start,
                                               const geometry_msgs::Point &goal);
};

#endif