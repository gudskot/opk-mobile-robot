#pragma once

#include <vector>
#include <memory>
#include "Geometry.hpp"
#include "Environment.hpp"

namespace lidar {

struct Config {
    double max_range;
    int    beam_count;
    double first_ray_angle;
    double last_ray_angle;
};

class Lidar {
private:
    Config config;
    std::shared_ptr<environment::Environment> env;
    
public:
    Lidar(const Config& config, std::shared_ptr<environment::Environment> env);

    std::vector<geometry::Point2d> scan(const geometry::RobotState& state) const;
};

} // namespace lidar
