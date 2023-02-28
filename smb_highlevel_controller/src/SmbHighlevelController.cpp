#include <smb_highlevel_controller/SmbHighlevelController.hpp>

namespace smb_highlevel_controller {

SmbHighlevelController::SmbHighlevelController(ros::NodeHandle& nodeHandle) :
  nodeHandle_(nodeHandle)
{
    std::string topic;
    int queue_size;
    if ( !nodeHandle.getParam("subscriber_topic", topic) 
        || !nodeHandle.getParam("queue_size", queue_size) ) 
    {
        ROS_ERROR("Could not find subscriber params!"); 
        ros::requestShutdown();
    }
    // create subscriber
    subscriber_ = nodeHandle_.subscribe(topic, queue_size, 
        &SmbHighlevelController::scanCallback, this);
    ROS_INFO("Smb highlevel controller node launched!");
}

SmbHighlevelController::~SmbHighlevelController()
{
}

void SmbHighlevelController::scanCallback(const sensor_msgs::LaserScan& msg)
{
  int size = msg.ranges.size();
  float min = msg.range_max;

  // tim gia tri nho nhat tu vector msg.ranges
  for (int i = 0; i < size; i++) {
    if (msg.ranges.at(i) < min && msg.ranges.at(i) > msg.range_min) {
      min = msg.ranges.at(i);
    }
  }

  ROS_INFO_STREAM("Minimum distance: " << min);
}
} /* namespace */
