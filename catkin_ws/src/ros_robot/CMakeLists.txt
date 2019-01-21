cmake_minimum_required(VERSION 2.8.3)
project(ros_robot)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  serial
  message_generation
)
add_message_files(
   FILES
   Active.msg
)

generate_messages(
   DEPENDENCIES
   std_msgs
	
 )

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs serial
  CATKIN_DEPENDS message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker ros_robot_generate_messages_cpp)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener ros_robot_generate_messages_cpp)

add_executable(ser src/ser.cpp)
target_link_libraries(ser ${catkin_LIBRARIES})
add_dependencies(ser ros_robot_generate_messages_cpp)
