#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/ubuntu/mopping_robot/ros/src/rosserial/rosserial_xbee"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/ubuntu/mopping_robot/ros/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/ubuntu/mopping_robot/ros/install/lib/python2.7/dist-packages:/home/ubuntu/mopping_robot/ros/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/ubuntu/mopping_robot/ros/build" \
    "/usr/bin/python2" \
    "/home/ubuntu/mopping_robot/ros/src/rosserial/rosserial_xbee/setup.py" \
     \
    build --build-base "/home/ubuntu/mopping_robot/ros/build/rosserial/rosserial_xbee" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/ubuntu/mopping_robot/ros/install" --install-scripts="/home/ubuntu/mopping_robot/ros/install/bin"
