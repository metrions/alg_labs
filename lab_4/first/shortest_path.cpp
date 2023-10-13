#include "shortest_path.h"

using namespace std;

vector<int> shortest_path(const Graph &graph, int start_vertex, int end_vertex) {
    vector<int> answer();
    std::vector<int> answer(get_verties.size());
    vector<pair<int, double>> set_edges = get_adjacent_edges(start_vertex);
    for (int i = 0; i < answer.size(); i++){
        answer[i] = 9999999;
    }
    answer[start_vertex] = 0;
    for (int i=0; i<set_edges.size(); i++){
        if ()
    }
    // Return shortest path in the graph from start vertex to end vertex as array of vertices.
    // First item in the result should be start vertex, last - end vertex.
    // Return empty array if there is no path.

    // Your implementation here.
    return vector<int> {};
}
