#include "Environment.hpp"

namespace environment {

    Environment::Environment(const Config& config)
    {
        map = cv::imread(config.map_filename, cv::IMREAD_GRAYSCALE);

        if(map.empty())
            throw std::runtime_error("Map file not found");

        if(map.type() != CV_8UC1)
            throw std::runtime_error("Map must be grayscale");
    }

    bool Environment::isOccupied(double x, double y) const
    {
        int intX = (int)x;
        int intY = (int)y;

        if(intX < 0 || intY < 0 || intX >= map.cols || intY >= map.rows)
        {
            return true;
        }

        uchar point = map.at<uchar>(intY, intX);

        if(point < 128)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    double Environment::getHeight() const
    {
        return map.rows;
    }

    double Environment::getWidth() const
    {
        return map.cols;
    }
}