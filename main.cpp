#include <iostream>
#include "inc/Environment.hpp"

int main()
{
    environment::Config config;

    config.map_filename = "../src/opk-map.png";
    config.resolution = 0.05;

    environment::Environment environment(config);

    std::cout << "width: " << environment.getWidth() << "\n";
    std::cout << "heigth: " << environment.getHeight() << "\n";

    std::cout << "is occupied:" << environment.isOccupied(500, 700) << "\n";
    
    return 0;
}