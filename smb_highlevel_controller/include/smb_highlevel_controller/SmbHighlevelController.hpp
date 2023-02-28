#pragma once

#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/LaserScan.h>
#include <string>

namespace smb_highlevel_controller {

/*!
 * Class containing the Smb Highlevel Controller
 */
class SmbHighlevelController {
public:
	/*!
	 * Constructor.
	 */
	SmbHighlevelController(ros::NodeHandle& nodeHandle);

	/*!
	 * Destructor.
	 */
	virtual ~SmbHighlevelController();

private:
	ros::NodeHandle nodeHandle_;
	ros::Subscriber subscriber_;

	void scanCallback(const sensor_msgs::LaserScan& msg);
};

} /* namespace */
