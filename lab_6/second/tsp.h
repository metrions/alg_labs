#include "graph.h"
#include <set>
#include <map>

#include <vector>

/// Solve Travelling Salesman Problem (TSP) for the graph:
/// Find the shortest (with a minimal total weight) tour and return it as an array of vertices.
void DeleteFromMap(std::map<int, std::set<int>> &edge, int a);
std::vector<int> tsp(const Graph &graph);


double Rand(double a, double b);
double Length(const Graph &graph, const std::vector<int> &path);