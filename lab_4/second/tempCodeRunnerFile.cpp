while (!Q.empty()){
		auto t = Q.top();
		Q.pop();
		vector <pair<int, double>> AdjacentEdge = graph.get_adjacent_edges(t.first);
		for (auto i=AdjacentEdge.begin(); i!=AdjacentEdge.end(); i++){
			if (!Q_vert.contains(i->first) && MinWeight[i->first] > graph.edge_weight(t.first, i->first)){
				MinWeight[v] = graph.edge_weight(t.first, i->first);
				Parent[v] = t.first;
			}
		}
	}