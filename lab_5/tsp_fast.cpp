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

double Length(const Graph &graph, vector<int> &path){
    double l = 0;
    for (int i = 0; i<int(path.size())-1; i++){
        l += graph.edge_weight(path[i], path[i+1]);
    }
    l += graph.edge_weight(path[0], path[path.size()-1]);
    return l;
}

double LowerBound(const Graph &graph, vector<int> &Visited){    //среднее значение ребер в Visited и оставшихся
    double t = 0;
    vector<int> q = graph.get_vertices();
    vector<pair<int, double>> temp = {};
    set<int> mas(Visited.begin(), Visited.end());
    for (auto i = q.begin(); i!=q.end(); i++){  //для каждой вершины
        temp = graph.get_adjacent_edges(*i);    //2 смежных ребра для вершины
        struct
        {
            bool operator()(pair<int, double> &a, pair<int, double> &b) const { return a.second < b.second; }
        }
        customLess;
        std::sort(temp.begin(), temp.end(), customLess);    //сортировка по весу
        if (mas.find((*i)) != mas.end()){   //добавлена ли уже вершина
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

vector<int> MinPath(const Graph &graph, vector<int> &p1, vector<int> &p2){
    if (Length(graph, p1) > Length(graph, p2)) return p2;
    return p1;
}

vector<int> BnB(const Graph &graph, vector<int> &Visited, vector<int> &BestPath){
    if (Visited.size() >= graph.get_vertices().size()){ //Если посещенные вершины содержат все вершины графа graph
        return MinPath(graph, Visited, BestPath);   //минимальный путь между 2 путями
    }
    vector<int> ver = graph.get_vertices();
    vector<int> VNext = {};
    vector<int> Path = {};
    set<int> vist(Visited.begin(), Visited.end());  //вершины Visited
    for (auto i=ver.begin(); i!=ver.end(); i++){
        if (vist.find(*i)==vist.end()){ //Для каждой вершины i графа G не из Visited
            VNext = Visited;
            VNext.push_back((*i));
            if (LowerBound(graph, VNext) < Length(graph, BestPath)){    //если средний путь меньше нашего тогда
                Path = BnB(graph, VNext, BestPath);     //повторить цикл
                BestPath = MinPath(graph, BestPath, Path);  //выбрать лучшее с предыдущего и нового
            }
        } 
    }
    return BestPath;
}

vector<int> tsp(const Graph &graph) {
    if (graph.get_vertices().size() < 2) return {};
    vector<int> BestPath = graph.get_vertices(); //некоторое эвристическое решение
    vector<int> Visited = {0};  //список пройденных вершин
    // cout << endl << Length(graph, BnB(graph, Visited, BestPath)) << endl << endl;
    return BnB(graph, Visited, BestPath);   
}
