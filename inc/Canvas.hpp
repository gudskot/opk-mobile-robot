#pragma once
#include <opencv2/opencv.hpp>
#include "Geometry.hpp"

class Canvas
{
public:
    static void drawCircle(cv::Mat& map, const std::vector<geometry::Point2d>& points, int radius, cv::Scalar color);

    static void mouseHandler(int event, int x, int y, int flags, void* userdata);
};

