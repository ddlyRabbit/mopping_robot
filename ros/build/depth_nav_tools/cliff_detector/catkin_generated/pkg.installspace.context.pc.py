# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;image_geometry;image_transport;nodelet;dynamic_reconfigure;sensor_msgs;depth_nav_msgs".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lCliffDetector;-lCliffDetectorNode".split(';') if "-lCliffDetector;-lCliffDetectorNode" != "" else []
PROJECT_NAME = "cliff_detector"
PROJECT_SPACE_DIR = "/home/ubuntu/mopping_robot/ros/install"
PROJECT_VERSION = "1.0.1"
