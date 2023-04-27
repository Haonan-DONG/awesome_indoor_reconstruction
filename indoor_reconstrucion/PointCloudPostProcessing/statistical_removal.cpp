#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/io/ply_io.h>
#include <pcl/console/parse.h>

int main(int argc, char **argv)
{
    std::string point_cloud_path;
    pcl::console::parse_argument(argc, argv, "--input", point_cloud_path);
    std::string point_cloud_path_out;
    pcl::console::parse_argument(argc, argv, "--output", point_cloud_path_out);

    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZRGB>);

    // Fill in the cloud data
    if (pcl::io::loadPLYFile<pcl::PointXYZRGB>(point_cloud_path, *cloud) == -1) //* load the file
    {
        PCL_ERROR("Couldn't read file test_pcd.pcd \n");
        system("PAUSE");
        return (-1);
    }

    std::cerr << "Cloud before filtering: " << std::endl;
    std::cerr << *cloud << std::endl;

    // Create the filtering object
    pcl::StatisticalOutlierRemoval<pcl::PointXYZRGB> sor;
    sor.setInputCloud(cloud);
    sor.setMeanK(50);
    sor.setStddevMulThresh(1.0);
    sor.filter(*cloud_filtered);

    std::cerr << "Cloud after filtering: " << std::endl;
    std::cerr << *cloud_filtered << std::endl;

    pcl::io::savePLYFile(point_cloud_path_out, *cloud_filtered);

    return (0);
}