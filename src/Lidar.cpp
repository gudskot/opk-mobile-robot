#include "Lidar.hpp"

namespace lidar {

    Lidar::Lidar(const Config& config, std::shared_ptr<environment::Environment> env)
    {
        this->config = config;
        this->env = env;
    }

    std::vector<geometry::Point2d> Lidar::scan(const geometry::RobotState& state) const
    {
        std::vector<geometry::Point2d> result;

        if (config.beam_count < 2) return result;

        double step = 0.1;
        double stepAngle = (config.last_ray_angle - config.first_ray_angle) / (config.beam_count - 1);

        for (int i = 0; i < config.beam_count; i++)
        {
            double angle = config.first_ray_angle + i * stepAngle;
            angle = angle * M_PI / 180.0;
            angle += state.theta;

            for (double i = 0; i < config.max_range; i += step)
            {
                double r = i / 0.1;

                double x = state.x + r * cos(angle);
                double y = state.y + r * sin(angle);

                if (env->isOccupied(x, y))
                {
                    result.push_back({x, y});
                    break;
                }
            }
        }

        return result;
    }
}