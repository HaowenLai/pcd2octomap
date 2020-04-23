# cvt_pcd2octomap
## Description
A ros package for converting pcd file to octomap \*.bt/\*.ot file.  
It has two nodes, which is for binary and color tree respectively. Furthermore, online converting PointCloud2 to Octomap message is alse available using `octomap_server` and `pcl_ros`. You can use launch file to start it and rviz to visualize it.  
An octomap of a room is like this:  
![octomap_room](https://github.com/HaowenLai/pcd2octomap/blob/master/docs/images/octomap_room.png)

## Dependency
For offline file converting:
- pcl 1.7
- octomap 1.8
For online message converting:
- pcl 1.7
- octomap 1.8
- ROS Kinetic
- pcl_ros 1.4.4
- octomap_server 0.6.4

## Document
You can find more information about function usage here: <https://haowenlai.github.io/pcd2octomap/>

## Author
Haowen Lai

