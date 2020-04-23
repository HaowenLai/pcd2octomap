# 增加PCL库的依赖
find_package(PCL REQUIRED COMPONENTS common io)

# 添加头文件和库文件
add_definitions(${PCL_DEFINITIONS})
include_directories(${PCL_INCLUDE_DIRS})
link_libraries(${PCL_LIBRARY_DIRS})

# octomap
find_package(octomap REQUIRED)
include_directories(${OCTOMAP_INCLUDE_DIRS})

add_executable(pcd2octomap pcd2octomap.cpp)
target_link_libraries(pcd2octomap ${PCL_LIBRARIES} ${OCTOMAP_LIBRARIES})

add_executable( pcd2colorOctomap pcd2colorOctomap.cpp )
target_link_libraries(pcd2colorOctomap ${PCL_LIBRARIES} ${OCTOMAP_LIBRARIES})


