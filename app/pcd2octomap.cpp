/**
 * @file pcd2octomap.cpp
 * @author Derek Lai
 * @brief Convert pcd file to binary octomap
 * @detail Detail things,..... Detail things,.....
 * @date 2020-02-03
 * @version v1.0
 */

#include <iostream>
#include <assert.h>

//pcl
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

//octomap 
#include <octomap/octomap.h>

using namespace std;

/** 
 * Main function
 *
 *  Convert pcd file to binary octomap. This function uses
 * pcl::PointXYZRGBA and octomap::OcTree
 *
 * @param[in] argc How many argument
 * @param argv Concrete argument
 * @return 0 for success, otherwise failure
 */
int main( int argc, char** argv )
{
    if (argc != 3)
    {
        cout<<"Usage: pcd2octomap <input_file> <output_file>"<<endl;
        return -1;
    }

    string input_file = argv[1], output_file = argv[2];
    pcl::PointCloud<pcl::PointXYZRGBA> cloud;
    pcl::io::loadPCDFile<pcl::PointXYZRGBA> ( input_file, cloud );

    cout<<"point cloud loaded, piont size = "<<cloud.points.size()<<endl;

    //声明octomap变量
    cout<<"copy data into octomap..."<<endl;
    // 创建八叉树对象，参数为分辨率，这里设成了0.05
    octomap::OcTree tree( 0.05 );

    for (auto p:cloud.points)
    {
        // 将点云里的点插入到octomap中
        tree.updateNode( octomap::point3d(p.x, p.y, p.z), true );
    }

    // 更新octomap
    tree.updateInnerOccupancy();
    // 存储octomap
    tree.writeBinary( output_file );
    cout<<"done."<<endl;

    return 0;
}

