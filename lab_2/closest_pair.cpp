#include "closest_pair.h"

using namespace std;



std::pair<Point, Point> closest_pair_slow(const std::vector<Point> &points) {
    double mi = 99999999;
    if (points.size() < 2) {
		throw std::invalid_argument("Not enough points");
	}
    else{
        return closest(points);
    }
    // return answer;
}

std::pair<Point, Point> closest_pair_fast(const std::vector<Point> &points) {
    if (points.size() < 2) {
        cout << "ASDASD";
		throw std::invalid_argument("Not enough points");
        return closest_fast(points);
	}
    else{
        cout << "ASDASD";
        return closest_fast(points);
    }
    return closest_fast(points);
}

std::pair<Point, Point> closest_fast(const std::vector<Point> &points) {
    std::pair<Point, Point> answer;
    if (points.size() <= 3){
        return closest(points);
    }
    else{
        std::vector sort_points(points);
        std::sort(sort_points.begin(), sort_points.end(), [](const Point &p1, const Point &p2) {
                return p1.x < p2.x;});
        std::vector<Point> left(sort_points.begin(), sort_points.begin() + sort_points.size()/2);
	    std::vector<Point> right(sort_points.begin() + sort_points.size() / 2, sort_points.end());
        auto pl = closest_fast(left);
        auto pr = closest_fast(right);
        double d = min(dist(pl), dist(pr));
        auto pb = closest_pair_between(left, right, d);
        answer = (d == dist(pl)) ? pl : pr;
        answer = (dist(answer) < dist(pb)) ? answer : pb;
        return answer;

    }
    return answer;
}
std::pair<Point, Point> closest(const std::vector<Point> &points) {
    double mi = 99999999;
    std::pair<Point, Point> answer = make_pair(Point(0,0), Point(999,999));
    for (auto i=points.begin(); i!=points.end()--; i++){
        for (auto j=next(i, 1); j!=points.end(); j++){
            if ((*i).distance((*j)) < mi){
                mi = (*i).distance((*j));
                answer = std::make_pair(*i, *j);
            }
        }
    }
    return answer;
}


std::pair<Point, Point> closest_pair_between(const std::vector <Point> &left, const std::vector <Point> &right, float d){
	double Xm = ((left[left.size()-1].x + right[0].x) / 2);
	std::set<Point> PStripe;
	std::vector<Point> obj(left);
    std::vector<Point> k;
    for (auto s : right){
        obj.push_back(s);
    }
	for (auto i : obj){
		if (abs(i.x - Xm) < d) k.push_back(i);
	}
	
	double mi = 99999999999;
    std::vector sort_points(k);
    std::sort(sort_points.begin(), sort_points.end(), [](const Point &p1, const Point &p2) {
                return p1.y < p2.y;});
	auto t = std::make_pair(Point(0, 0), Point(999, 999));
	for (int i=0; i<sort_points.size(); i++){
		for (int j=i+1; j<sort_points.size() && abs(sort_points[i].y - sort_points[j].y)<d; j++){
            if (sort_points[i].distance(sort_points[j])<mi){
				mi = sort_points[i].distance(sort_points[j]);
				t = std::make_pair(sort_points[i], sort_points[j]);
			}
		}
	}
	return t;
    }
	
