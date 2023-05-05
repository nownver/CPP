#ifndef PICTURE_HPP
#define PICTURE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cmath>

bool findCircleCenter(const std::string& svgFilename, double& cx, double& cy);
void generateRandomPoints(int N, double cx, double cy, double r);

#endif 