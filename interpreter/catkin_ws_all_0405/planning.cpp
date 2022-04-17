#include "xml_interpreter/planning.h"

Planning::Planning()
{
    // 路径规划相关
    path_result_sub = nh.subscribe("path_result", 10, &Planning::path_result_callback, this);
    path_param_pub = nh.advertise<path_planning::PathParam>("path_param", 10);
}

void Planning::path_result_callback(const path_planning::PathResult::ConstPtr &msg)
{
    // ROS_INFO("debug before");
    ROS_INFO("result size:%ld", msg->result.size());
    // ROS_INFO("goals size:%d", goals.size());
    
    goals = msg->result;
    plan_success = true;
    // goals.resize(msg->result.size());
    // for (int i = 0; i < goals.size(); i++)
    // {
    //     std::cout << goals[i].x << " " << goals[i].y << " " << goals[i].z << std::endl;
    // }
    // c goal = msg->result;
    // ROS_INFO("success!");

    ROS_INFO("goals size:%ld", goals.size());
    ROS_INFO("plan_success:%d", plan_success);
    // ROS_INFO("debug after");
}

std::vector<geometry_msgs::Point> Planning::planning(const geometry_msgs::Point &start,
                                                     const geometry_msgs::Point &goal)
{
    plan_success = false; // 规划的结果不能立即得到
    path_planning::PathParam msg;
    msg.start = start;
    msg.goal = goal;
    path_param_pub.publish(msg);
    ros::spinOnce();
    ros::Duration(0.1).sleep();
    ROS_INFO("planning...");
    ros::Time start_time = ros::Time::now();
    while (!plan_success && ros::ok() && (ros::Time::now() - start_time) < ros::Duration(5.0))
    {
        ROS_INFO("plan_success:%d", plan_success);
        // 等待规划结果
        ros::spinOnce();
        ros::Duration(1.0).sleep();
    }
    return goals;
}
