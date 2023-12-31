#include "min_spanning_tree.h"
#include <queue>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int pop(std::set<int> &pq, std::vector<double> &dis){
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

struct{
    	bool operator()(const pair<int, vector<double>::iterator> &l, const pair<int, vector<double>::iterator> &r) const { 
			return l.second < r.second; 
		}
	} ForPriorQ;

vector<pair<int, int>> min_spanning_tree(const Graph &graph) {
	vector<int> vert = graph.get_vertices();
	vector<double> MinWeight{};
	set<int> Q_vert{};
	vector<int> Parent{};

	for (auto i=vert.begin(); i!=vert.end(); i++){
		MinWeight.push_back(9999999.0);
		Parent.push_back(-1);
	}
	if (vert.size() == 0) return vector<pair<int, int>>{};
	vector <pair<int, vector<double>::iterator>> q{};
	set<int> Q;
	for (int i=0; i<vert.size(); i++){
		Q.insert(vert[i]);
	}
	// cout << Q.top().first << endl;

	while (!Q.empty()){
		int t = pop(Q, MinWeight);
		Q.erase(t);
		vector <pair<int, double>> AdjacentEdge = graph.get_adjacent_edges(t);
		for (auto v=AdjacentEdge.begin(); v!=AdjacentEdge.end(); v++){
			if (Q.find(v->first)!=Q.end() && MinWeight[v->first] > v->second){
				// cout << "WE " << MinWeight[v->first] << " " << v->second << endl;
				MinWeight[v->first] = v->second;
				// for (auto j =Q_vert.begin(); j!=Q_vert.end(); j++){
				// 	cout << *j << " ";
				// }
				// cout << endl;
				Parent[v->first] = t;
			}
		}
		Q_vert.insert(t);
	}
	vector<pair<int, int>> MST{};
	for (auto i=Q_vert.begin(); i!=Q_vert.end(); i++){
		if (Parent[*i] != -1) MST.push_back(make_pair(*i, Parent[*i]));
	}
	return MST;

}
