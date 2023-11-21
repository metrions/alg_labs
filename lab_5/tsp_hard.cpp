#include "tsp.h"
#include <set>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void printv(vector<int> s){
    for (auto t = s.begin(); t!=s.end(); t++){
        cout << (*t) << " ";
    }
    cout << endl;
}

void pere(vector<int> &ver, vector<vector<int>> &answer, vector<int> &n){
    if (ver.size() == 0){
        answer.push_back(n);
    }
    else{
        for (int i=0; i<ver.size(); i++){
            vector<int> t(ver.begin(), ver.end());
            vector<int> ne = n;
            ne.push_back(t[i]);
            // cout << t[i] << " ";
            t.erase(t.begin() + i);
            pere(t, answer, ne);
            // cout << endl;
        }
    }
}

void printans(vector<vector<int>> &ans){
    for (auto t = ans.begin(); t!=ans.end(); t++){
        for (auto j = (*t).begin(); j!=(*t).end(); j++){
            cout << (*j) << " ";
        }
        cout << endl;
    }
}

// vector<vector<int>> perm(const Graph &graph){
//     vector<int> ver = graph.get_vertices();
//     vector<vector<int>> answer = {};
// }

double Length(const Graph &graph, const vector<int> &path){
    double l = 0;
    for (int i = 0; i<int(path.size())-1; i++){
        l += graph.edge_weight(path[i], path[i+1]);
    }
    l += graph.edge_weight(path[0], path[path.size()-1]);
    return l;
}

double LowerBound(const Graph &graph, const vector<int> &Visited){
    double t = 0;
    vector<int> q = graph.get_vertices();
    vector<pair<int, double>> temp = {};
    set<int> mas(Visited.begin(), Visited.end());
    for (auto i = q.begin(); i!=q.end(); i++){
        temp = graph.get_adjacent_edges(*i);
        struct
        {
            bool operator()(pair<int, double> &a, pair<int, double> &b) const { return a.second < b.second; }
        }
        customLess;
        std::sort(temp.begin(), temp.end(), customLess);
        if (mas.find((*i)) != mas.end()){
            if (temp.size() >= 1) t = t + temp[0].second;
        }
        else{
            if (temp.size() >= 2) t = t + (temp[0]).second + temp[1].second;
            else{
                if (temp.size() >= 1) t = t + temp[0].second;
            }
        }
    }
    for (int i=0; i<int(Visited.size())-1; i++){
            t = t + graph.edge_weight(Visited[i], Visited[i+1]);
        }
    return t/2;
}

vector<int> MinPath(const Graph &graph, const vector<int> &p1, const vector<int> &p2){
    if (Length(graph, p1) > Length(graph, p2)) return p2;
    return p1;
}

vector<int> BnB(const Graph &graph, const vector<int> &Visited, vector<int> &BestPath){
    if (Visited.size() >= graph.get_vertices().size()){
        return MinPath(graph, Visited, BestPath);
    }
    vector<int> ver = graph.get_vertices();
    vector<int> VNext = {};
    vector<int> Path = {};
    set<int> vist(Visited.begin(), Visited.end());
    for (auto i=ver.begin(); i!=ver.end(); i++){
        if (vist.find(*i)==vist.end()){
            VNext = Visited;
            VNext.push_back((*i));
            if (LowerBound(graph, VNext) < Length(graph, BestPath)){
                Path = BnB(graph, VNext, BestPath);
                BestPath = MinPath(graph, BestPath, Path);
            }
        } 
    }
    return BestPath;
}

vector<int> tsp(const Graph &graph) {
    if (graph.get_vertices().size() < 2) return {};
    int Current = 0;
    vector<int> Path = {Current};
    vector<int> ver = graph.get_vertices();
    set<int> have_visited = {Current};
    while (Path.size() < ver.size()){
        vector<pair<int, double>>temp = graph.get_adjacent_edges(Current);
        struct
        {
            bool operator()(pair<int, double> &a, pair<int, double> &b) const { return a.second < b.second; }
        }
        customLess;
        std::sort(temp.begin(), temp.end(), customLess);
        for (auto t=temp.begin(); t!=temp.end(); t++){
            if (!(have_visited.find((*t).first) != have_visited.end())){
                have_visited.insert((*t).first);
                cout << (*t).first << " ";
                Path.push_back((*t).first);
                Current = (*t).first;
                break;
            }
        }
        cout << endl;
    }
    return Path;
}
