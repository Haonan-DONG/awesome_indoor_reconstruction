#include <iostream>
#include <cstdio>

#include <glog/logging.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <pcl/common/transforms.h>
#include <pcl/console/parse.h>

using namespace std;

int main(int argc, char **argv)
{
    // Initialize logging.
    FLAGS_logtostderr = 1;
    google::InitGoogleLogging(argv[0]);
    pcl::console::setVerbosityLevel(pcl::console::L_ALWAYS);

    // Parse arguments.
    std::string ground_truth_depth_path;
    pcl::console::parse_argument(argc, argv, "--ground_truth_depth_path", ground_truth_depth_path);

    cv::Mat gt_depth_map(4032, 6048, CV_32FC1);
    cv::Mat gt_depth_map_int(4032, 6048, CV_16UC1);

    FILE *ground_truth_depth_file = fopen(ground_truth_depth_path.c_str(), "rb");
    fread(gt_depth_map.data, sizeof(float), gt_depth_map.rows * gt_depth_map.cols, ground_truth_depth_file);
    fclose(ground_truth_depth_file);

    int scale = 1000;

    for (int i = 0; i < gt_depth_map.rows; i++)
    {
        for (int j = 0; j < gt_depth_map.cols; j++)
        {
            float *depth_value = gt_depth_map.ptr<float>(i, j);
            uint16_t depth_int = *depth_value * scale;
            gt_depth_map_int.ptr<uint16_t>(i, j)[0] = depth_int;
        }
    }

    std::cout << "Saving GT depth."
              << std::endl;
    cv::imwrite("depth.png", gt_depth_map_int);
    return 0;
}