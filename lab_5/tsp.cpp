#include "tsp.h"
#include <set>
#include <iostream>
#include <set>
using namespace std;

void printv(vector<int> s){
    for (auto t = s.begin(); t!=s.end(); t++){
        cout << (*t) << " ";
    }
    cout << endl;
}


double Length(const Graph &graph, vector<int> &path){ //размер путя
    double l = 0;
    for (int i = 0; i<int(path.size())-1; i++){
        if (!graph.has_edge(path[i], path[i+1])){
            return 9999999999;
            break;
        }
        else{
            l += graph.edge_weight(path[i], path[i+1]);
        }
    }
    if (!graph.has_edge(path[0], path[path.size()-1])) return 9999999999;
    else{
        l += graph.edge_weight(path[0], path[path.size()-1]);
    }
    return l;
}


void pere(vector<int> &ver, vector<vector<int>> &answer, vector<int> &n){   //перебор всех возможных путей рекурсией
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


vector<vector<int>> perm(const Graph &graph){
    vector<int> ver = graph.get_vertices();
    vector<vector<int>> answer = {};
}


vector<int> tsp(const Graph &graph) {
    int start = 0;
    vector<int> ver = graph.get_vertices();
    if (ver.size() < 2) return {};
    vector<vector<int>> ans = {};
    vector<int> otvet = {};
    vector<int> n ={};
    pere(ver, ans, n);  //перебор всех возможных путей и запись в ans
    double l = 0;
    vector <int> nes = {};
    double min = 999999;
    for (auto i = ans.begin(); i!=ans.end(); i++){
        nes = {};
        nes.push_back(*((*i).begin()));
        l = 0;
        for (auto j = (*i).begin(); j!=(*i).end()-1; j++){  //длина путя
            if (graph.has_edge((*j), (*(j+1)))){
                nes.push_back(*(j+1));
                l += graph.edge_weight((*j), (*(j+1)));
            }
            else{
                break;
            }
        }
        if (l < min){
            min = l;
            otvet = nes;
        }
    }
    return otvet;
}