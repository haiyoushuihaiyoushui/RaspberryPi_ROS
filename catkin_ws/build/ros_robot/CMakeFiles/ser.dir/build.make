# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/catkin_ws/build

# Include any dependencies generated for this target.
include ros_robot/CMakeFiles/ser.dir/depend.make

# Include the progress variables for this target.
include ros_robot/CMakeFiles/ser.dir/progress.make

# Include the compile flags for this target's objects.
include ros_robot/CMakeFiles/ser.dir/flags.make

ros_robot/CMakeFiles/ser.dir/src/ser.cpp.o: ros_robot/CMakeFiles/ser.dir/flags.make
ros_robot/CMakeFiles/ser.dir/src/ser.cpp.o: /home/ubuntu/catkin_ws/src/ros_robot/src/ser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ros_robot/CMakeFiles/ser.dir/src/ser.cpp.o"
	cd /home/ubuntu/catkin_ws/build/ros_robot && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ser.dir/src/ser.cpp.o -c /home/ubuntu/catkin_ws/src/ros_robot/src/ser.cpp

ros_robot/CMakeFiles/ser.dir/src/ser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ser.dir/src/ser.cpp.i"
	cd /home/ubuntu/catkin_ws/build/ros_robot && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/catkin_ws/src/ros_robot/src/ser.cpp > CMakeFiles/ser.dir/src/ser.cpp.i

ros_robot/CMakeFiles/ser.dir/src/ser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ser.dir/src/ser.cpp.s"
	cd /home/ubuntu/catkin_ws/build/ros_robot && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/catkin_ws/src/ros_robot/src/ser.cpp -o CMakeFiles/ser.dir/src/ser.cpp.s

ros_robot/CMakeFiles/ser.dir/src/ser.cpp.o.requires:

.PHONY : ros_robot/CMakeFiles/ser.dir/src/ser.cpp.o.requires

ros_robot/CMakeFiles/ser.dir/src/ser.cpp.o.provides: ros_robot/CMakeFiles/ser.dir/src/ser.cpp.o.requires
	$(MAKE) -f ros_robot/CMakeFiles/ser.dir/build.make ros_robot/CMakeFiles/ser.dir/src/ser.cpp.o.provides.build
.PHONY : ros_robot/CMakeFiles/ser.dir/src/ser.cpp.o.provides

ros_robot/CMakeFiles/ser.dir/src/ser.cpp.o.provides.build: ros_robot/CMakeFiles/ser.dir/src/ser.cpp.o


# Object files for target ser
ser_OBJECTS = \
"CMakeFiles/ser.dir/src/ser.cpp.o"

# External object files for target ser
ser_EXTERNAL_OBJECTS =

/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: ros_robot/CMakeFiles/ser.dir/src/ser.cpp.o
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: ros_robot/CMakeFiles/ser.dir/build.make
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /opt/ros/kinetic/lib/libroscpp.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /usr/lib/arm-linux-gnueabihf/libboost_signals.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /opt/ros/kinetic/lib/librosconsole.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /usr/lib/arm-linux-gnueabihf/liblog4cxx.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /opt/ros/kinetic/lib/librostime.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /opt/ros/kinetic/lib/libcpp_common.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /usr/lib/arm-linux-gnueabihf/libboost_chrono.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /usr/lib/arm-linux-gnueabihf/libboost_atomic.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /usr/lib/arm-linux-gnueabihf/libpthread.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: /home/ubuntu/catkin_ws/devel/lib/libserial.so
/home/ubuntu/catkin_ws/devel/lib/ros_robot/ser: ros_robot/CMakeFiles/ser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/ubuntu/catkin_ws/devel/lib/ros_robot/ser"
	cd /home/ubuntu/catkin_ws/build/ros_robot && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ros_robot/CMakeFiles/ser.dir/build: /home/ubuntu/catkin_ws/devel/lib/ros_robot/ser

.PHONY : ros_robot/CMakeFiles/ser.dir/build

ros_robot/CMakeFiles/ser.dir/requires: ros_robot/CMakeFiles/ser.dir/src/ser.cpp.o.requires

.PHONY : ros_robot/CMakeFiles/ser.dir/requires

ros_robot/CMakeFiles/ser.dir/clean:
	cd /home/ubuntu/catkin_ws/build/ros_robot && $(CMAKE_COMMAND) -P CMakeFiles/ser.dir/cmake_clean.cmake
.PHONY : ros_robot/CMakeFiles/ser.dir/clean

ros_robot/CMakeFiles/ser.dir/depend:
	cd /home/ubuntu/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/catkin_ws/src /home/ubuntu/catkin_ws/src/ros_robot /home/ubuntu/catkin_ws/build /home/ubuntu/catkin_ws/build/ros_robot /home/ubuntu/catkin_ws/build/ros_robot/CMakeFiles/ser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ros_robot/CMakeFiles/ser.dir/depend

