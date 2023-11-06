#include "shortest_path.h"
#include <algorithm>
#include <set>
#include <iostream>


using namespace std;

int pop(std::set<int> &pq, std::vector<int> &dis){
    int min = 99999999;
    int j = -1;
    for (auto i=pq.begin(); i!=pq.end(); i++){
        if (min > dis[*i]){
            j = *i;
            min = dis[*i];
        }
    }
    return j;
}

vector <int> built_path(std::vector<int> parent, int start_vertex, int end_vertex){
    int i = end_vertex;
    vector <int> t{};
    t.push_back(i);
    while(parent[i] != start_vertex){
        i = parent[i];
        t.push_back(i);
        if (i == -1) return vector<int>{};
    }
    t.push_back(start_vertex);
    vector <int> answer{};
    for (int i=t.size()-1; i>=0; i--){
        answer.push_back(t[i]);
    }
    return answer;
    
}

vector<int> shortest_path(const Graph &graph, int start_vertex, int end_vertex) {
    std::vector<int> distance{};
    std::vector<int> parent{};
    std::vector<int> v = graph.get_vertices();
    std::set<int> q(v.begin(), v.end());


    for (int i = 0; i < q.size(); i++){
        distance.push_back(999999);
        parent.push_back(-1);
    }

    if (graph.has_vertex(start_vertex)){
        distance[start_vertex] = 0;
    }
    else{
        return vector<int> {};
    }
    while (!q.empty()){
        int t = pop(q, distance);
        q.erase(t);
        if (t == end_vertex){
            return built_path(parent, start_vertex, end_vertex);
        }
        else{
            std::vector<pair<int, double>> k = graph.get_adjacent_edges(t);
            for (auto s : k){
                if (distance[s.first] > distance[t] + s.second){
                    distance[s.first] =distance[t] + s.second;
                    parent[s.first] = t;
                }
            }
        }
        // q.remove_vertex(t);
    }
    return vector<int> {};
}
