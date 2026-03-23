#include "Canvas.hpp"

void Canvas::drawCircle(cv::Mat& map, const std::vector<geometry::Point2d>& points, int radius, cv::Scalar color)
{
    for (const auto& p : points)
    {
        cv::circle(map, cv::Point((int)p.x, (int)p.y), radius, color, cv::FILLED);
    }
}

void Canvas::mouseHandler(int event, int x, int y, int flags, void* userdata)
{
    if (event == cv::EVENT_LBUTTONDOWN)
    {
        points.push_back({(double)x, (double)y});
    }
}