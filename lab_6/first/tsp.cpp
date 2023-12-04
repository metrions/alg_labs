#include "tsp.h"
#include <set>
#include <vector>
#include <iostream>
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

vector<int> Transform(vector <int> &Path, int a, int b, int c, int d){
    vector<int> n = {a}; //добавление вершины a
    bool ch = false;
    // printv(Path);
    for (int i=Path.size(); i>=0; i--){ //добавление от B до C в обратном порядке(включительно)
        if (ch){
            n.push_back(Path[i]);
            if (Path[i] == b){
                ch = false;
                break;
            }
        }
        else{
            if (Path[i] == c){
                ch = true;
                n.push_back(Path[i]);
            }
        }
    }
    for (int i=0; i<Path.size(); i++){  //добвление вершин от D до A
        if (ch){
            n.push_back(Path[i]);
            if (Path[i] == a){
                break;
            }
        }
        else{
            if (Path[i] == d){
                ch = true;
                n.push_back(Path[i]);
            }
        }
    }
    // printv(Path);
    return n;
}

vector<int> TwoOptImprove(const Graph &graph, vector <int> &Path){
    vector<int> h = graph.get_vertices();
    vector<int> temp = {};
    vector<pair<int, int>> ver ={};
    set<int> bul;
    //создания вектора всех ребер
    for (auto i=h.begin(); i!=h.end(); i++){    //проход по всем вершинам графа
        temp = graph.get_adjacent_vertices(*i); //смежные вершины
        bul.insert(*i); //bul - для того чтобы ребра не повторялись
        for (auto j=temp.begin(); j!=temp.end(); j++){
            if (bul.find(*j) == bul.end())  ver.push_back(make_pair(*i, *j));   //добавление пары 1вершина-2вершина
        }
    }
    double OldWeight = 999999999;
    double NewWeight = 999999999;
    vector<int> temp_path = {Path};
    set<int> tmp;
    for (auto i=ver.begin(); i!=ver.end()-1; i++){
        bul = {};
        for (auto j=i+1; j!=ver.end(); j++){
            bul = {};
            bul.insert((*i).first);
            bul.insert((*i).second);
            bul.insert((*j).first);
            bul.insert((*j).second);
            if (bul.size() == 4){   //проверка на то что ребра несмежные так как если вершин различных <4 тогда ребра смежные
                OldWeight = 999999999;
                NewWeight = 999999999;
                if (graph.has_edge((*i).first, (*i).second) && graph.has_edge((*j).first, (*j).second) &&
                    graph.has_edge((*i).first, (*j).first) && graph.has_edge((*i).second, (*j).second)){    //проверка нахождение ребра в графе

                    OldWeight = graph.edge_weight((*i).first, (*i).second) + graph.edge_weight((*j).first, (*j).second);
                    NewWeight = graph.edge_weight((*i).first, (*j).first) + graph.edge_weight((*i).second, (*j).second);
                }
                if (NewWeight < OldWeight){ //трансформация графа в случае когда новый путь меньше предыдущего
                    temp_path =Transform(Path, (*i).first, (*i).second, (*j).first, (*j).second);
                    tmp = {};
                    tmp.insert(temp_path.begin(), temp_path.end());

                    //проверка на то что вершины не повторяются и в путь входят все точки
                    if (temp_path.size() == h.size() && h.size() == tmp.size()){
                        return Transform(Path, (*i).first, (*i).second, (*j).first, (*j).second);
                    }
                }
            }
        }
    }
    return Path;

}

vector<int> tsp_act(const Graph &graph, vector<int> CurrentPath){ //локальный поиск
    vector<int> ImprovedPath = {};
    while (true){
        ImprovedPath = TwoOptImprove(graph, CurrentPath);
        if (Length(graph, ImprovedPath) < Length(graph, CurrentPath)){
            CurrentPath = ImprovedPath;
        }
        else return CurrentPath;
    }
    return CurrentPath;
}


vector<int> tsp(const Graph &graph) {
    vector<int> CurrentPath = graph.get_vertices();
    if (CurrentPath.size() < 2) return {};
    srand(32);
    vector<int> temp = {};
    set<int> t = {};
    int k;
    double min = 99999999;
    vector<int> minv = {};
    for (int i=0; i<1; i++){                       //несколько путей для нахождения локальных экстремумов
        t = {};
        temp = {};
        k = CurrentPath[(int(rand()))%(int (CurrentPath.size()))];  //начальная точка
        while (t.size() != CurrentPath.size()){                     //добавление в путь вершины
            k = CurrentPath[(int(rand()))%(int (CurrentPath.size()))];  //генерация случайного маршрута
            if (t.find(k) == t.end()){
                t.insert(k);
                temp.push_back(k);
            }
        }
        temp = tsp_act(graph, temp); //алгоритм для каждой точки
        if (Length(graph, temp) < min){ //нахождение нового минимума
            min = Length(graph, temp);
            minv = temp;
        }
    }
    return minv;
}
