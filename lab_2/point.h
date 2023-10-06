#pragma once

#include <ostream>
#include <iostream>
#include <cmath>

class Point {
public:
	Point() {}
	Point(double xx, double yy) : x(xx), y(yy) {}

	double distance(const Point &p) const;

	bool operator==(const Point &p) const;
	bool operator!=(const Point &p) const;
	bool operator<(const Point &p) const;
	bool operator<=(const Point &p) const;
	void print();

public:
	double x {0.0};
	double y {0.0};
};

std::ostream& operator<<(std::ostream &os, const Point &p);
double dist(const std::pair<Point, Point> t);
void print(std::pair<Point, Point> k);
