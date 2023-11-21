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

vector<vector<int>> perm(const Graph &graph){
    vector<int> ver = graph.get_vertices();
    vector<vector<int>> answer = {};
}


vector<int> tsp(const Graph &graph) {
    int start = 0;
    vector<int> ver = graph.get_vertices();
    if (ver.size() < 2) return {};
    vector<vector<int>> ans = {};
    vector<int> n ={};
    pere(ver, ans, n);
    for (auto i = ans.begin(); i!=ans.end(); i++){
        nes = {};
        nes.push_back(*((*i).begin()));
        l = 0;
        for (auto j = (*i).begin(); j!=(*i).end()-1; j++){
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
