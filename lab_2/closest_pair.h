#pragma once
#include "point.h"
#include <set>
#include <stdexcept>
#include "point.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

std::pair<Point, Point> closest(const std::vector<Point> &points);
std::pair<Point, Point> closest_fast(const std::vector<Point> &points);
std::pair<Point, Point> closest_pair_between(const std::vector <Point> &left, const std::vector <Point> &right, float d);
std::pair<Point, Point> closest_pair_slow(const std::vector<Point> &points);
std::pair<Point, Point> closest_pair_fast(const std::vector<Point> &points);

