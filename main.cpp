#include <iostream>
#include "inc/Environment.hpp"
#include "inc/Lidar.hpp"
#include "inc/Geometry.hpp"
#include "inc/Canvas.hpp"

std::vector<geometry::Point2d> points;
std::vector<geometry::Point2d> scanPoints;

int main()
{
    environment::Config configEnvironment;

    configEnvironment.map_filename = "../src/opk-map.png";
    configEnvironment.resolution = 0.1;

    lidar::Config configLidar;

    configLidar.beam_count = 36;
    configLidar.first_ray_angle = 0;
    configLidar.last_ray_angle = 350;
    configLidar.max_range = 100;

    auto environment = std::make_shared<environment::Environment>(configEnvironment);

    lidar::Lidar lidar(configLidar, environment);

    cv::namedWindow("map");
    cv::setMouseCallback("map", Canvas::mouseHandler, &points);

    while (true)
    {
        cv::Mat frame;
        cv::cvtColor(environment->map, frame, cv::COLOR_GRAY2BGR);

        scanPoints.clear();

        for (const auto& p : points)
        {
            geometry::RobotState state;
            state.x = p.x;
            state.y = p.y;
            state.theta = 0.0;

            auto scan = lidar.scan(state);

            scanPoints.insert(scanPoints.end(), scan.begin(), scan.end());
        }

        Canvas::drawCircle(frame, points, 5, cv::Scalar(0, 255, 0));
        Canvas::drawCircle(frame, scanPoints, 3, cv::Scalar(0, 0, 255));

        cv::imshow("map", frame);

        if (cv::waitKey(30) == 27) break;
    }

    return 0;
}