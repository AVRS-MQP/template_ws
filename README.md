# ABB-IRB-1600: Template ROS-I catkin_ws
A simple template for getting started using ROS-I with WPI's ABB-IRB-1600 Robotic arm. 

Has a fixes for URDf and launch files that the main ROS-I experimental branch doesn't have.

Has Action client/server ROS packages for bridging Python and C++ enabling Python to be used for high levle control decisions. 


## ROS packages/nodes and launch files

- master.launch
A place to launch multiple launch files. Currently launches connection to the robot and static frame transformations. 
```
roslaunch master_launcher master.launch

```

- static_TFs.launch
A place to put static TFs


- ROS-I
Launch the ROS-I stack to connect to the robot and visualize in rviz:

```
roslaunch abb_irb1600_6_12_moveit_config moveit_planning_execution.launch sim:=false robot_ip:=192.168.100.100
```

- motion_server
This node recives action messages from the action client and sends motion requests to the ROS-I stack using move_group. Only needed if you wanto to use Python for planning. 
```
roslaunch motion_server motion_server.launch 
```

- motion_planning_client
This node is the main controll node written in python.  When in normal operation it will read an image and draw it on the white board. In debug mode it goes to manually  prgorammed locations.

```
roslaunch motion_planning_client motion_client.launch 
```

- master_launcher
Package with various micilanous launch files and launch files that launch others

```
TBD/varies
```

- msgs
Automatically generated custom msgs

# NOTES
```
to visualize the robot run

roslaunch abb_irb1600_6_12_moveit_config moveit_planning_execution.launch sim:=true 

This setup assistant helps you configure you URDF and must be launched and used to auto generate files after changing your URDF:
roslaunch moveit_setup_assistant setup_assistant.launch


To 

```




## Depends on

ROS-I,

MoveIt,

TRAC-IK Kinematics Solver
http://docs.ros.org/kinetic/api/moveit_tutorials/html/doc/trac_ik/trac_ik_tutorial.html

Recommended 
PCL
Open CV





