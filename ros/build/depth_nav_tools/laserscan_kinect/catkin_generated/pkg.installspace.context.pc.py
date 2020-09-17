# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include;/opt/ros/melodic/include;/opt/ros/melodic/share/xmlrpcpp/cmake/../../../include/xmlrpcpp;/usr/include;/usr/include/opencv".split(';') if "${prefix}/include;/opt/ros/melodic/include;/opt/ros/melodic/share/xmlrpcpp/cmake/../../../include/xmlrpcpp;/usr/include;/usr/include/opencv" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;image_geometry;image_transport;nodelet;dynamic_reconfigure;sensor_msgs".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lLaserScanKinect;-lLaserScanKinectNode".split(';') if "-lLaserScanKinect;-lLaserScanKinectNode" != "" else []
PROJECT_NAME = "laserscan_kinect"
PROJECT_SPACE_DIR = "/home/ubuntu/mopping_robot/ros/install"
PROJECT_VERSION = "1.0.1"
