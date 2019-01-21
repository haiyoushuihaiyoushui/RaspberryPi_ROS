#!/bin/bash
source /opt/ros/lunar/setup.bash
source /home/ubuntu/catkin_ws/devel/setup.bash
roscore &
sleep 3
cd /var/www/html/plugs/jsmpeg
node websocket-relay.js supersecret 8081 8082 &
sleep 3
cd ~/
ffmpeg -f v4l2 -framerate 25 -video_size 408x408 -i /dev/video0 -f mpegts -codec:v mpeg1video -s 408x408 -b:v 1000k -bf 0 http://localhost:8081/supersecret & 
sleep 2
roslaunch rosbridge_server rosbridge_websocket.launch &
sleep 2
roslaunch rplidar_ros myrp.launch &
sleep 2
roslaunch gmapping mymap.launch &
sleep 1
rosrun ros_robot ser > ser.log &
sleep 1
cd /usr/lib/cgi-bin/
rosrun ros_robot dh11.py > dh.log  &
sleep 1
cd /var/www/html/getMap
./productMap.sh &
