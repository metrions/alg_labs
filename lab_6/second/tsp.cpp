#include "tsp.h"
#include <set>
#include <iostream>
#include <list>
#include <set>
#include <map>
using namespace std;

void printv(vector<int> s){
    for (auto t = s.begin(); t!=s.end(); t++){
        cout << (*t) << " ";
    }
    cout << endl;
}

void printsv(set<vector<int>> s){
    for (auto t = s.begin(); t != s.end(); t++){
        cout << "vector : ";
        printv(*t);
    }
}

double Length(const Graph &graph, const vector<int> &path){
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

// vector<int> tsp_act(const Graph &graph, vector<int> CurrentPath){
//     vector<int> ImprovedPath = {};
//     while (true){
//         ImprovedPath = TwoOptImprove(graph, CurrentPath);
//         printv(ImprovedPath);
//         if (Length(graph, ImprovedPath) < Length(graph, CurrentPath)){
//             CurrentPath = ImprovedPath;
//         }
//         else return CurrentPath;
//     }
//     return CurrentPath;
// }

double Rand(double a, double b){
    double d = b - a;
    int r = rand();
    return a + double(r % 100) / 100 * d;
}

// int P = 10;
// int N = 5;

double all_weight(const Graph graph, vector<vector<int>> s){
    double k = 0;
    for (auto t=s.begin(); t!=s.end(); t++){
        k = k + Length(graph, *t);
    }
    return k;
}

vector<vector<int>> new_gen(const Graph &graph, vector<int> &ver){
    set<vector<int>> start_gen = {ver};
    int p1 = 0;
    int p2 = 0;
    int t = 0;
    while (start_gen.size() != ver.size()){
        while (start_gen.find(ver) != start_gen.end()){
            p1 = rand()% ver.size();
            p2 = rand()% ver.size();
            t = ver[p1];
            ver[p1] = ver[p2];
            ver[p2] = t;
        }
        if (Length(graph, ver) < 999999999){
            start_gen.insert(ver);
        }
    }
    vector<vector<int>> v(start_gen.begin(), start_gen.end());
    return v;
}

vector<vector<int>> SUS(const Graph &graph, vector<vector<int>> &Population, int N){
    double F = all_weight(graph, Population);
    double Dist = F / double(N);
    double Start = Rand(0, Dist);
    vector<vector<int>> Chosen = {};
    int k = 0;
    double SumWeight = Length(graph, Population[0]);
    double Point;
    for (int i=0; i<N; i++){
        Point = Start + i*Dist;
        while(SumWeight < Point){
            k++;
            SumWeight += Length(graph, Population[k]);
        }
        Chosen.push_back(Population[k]);
    }
    return Chosen;
}

int get_index(vector<int> a, int b){
    int k = 0;
    while(a[k] != b){
        k++;
    }
    return k;
}

void DeleteFromMap(std::map<int, set<int>> &edge, int a){
    edge.erase(a);
    for (auto& i : edge){
        auto it = i.second.begin();
        while (it != i.second.end())
        {
            if (*it == a) {
                it = i.second.erase(it);
            }
            else {
                ++it;
            }
        }
    }
}

int choose(map<int, set<int>> &edge){
    vector<int> t = {};
    int min = 999999;
    int a = 0;
    for (auto &i : edge){
        if (min > i.second.size()){
            min = i.second.size();
            t = {i.first};
        }
        else if (min == i.second.size()){
            t.push_back(i.first);
        }
    }
    return t[int(rand()) % t.size()];
}

vector<int> CrossovER(vector<int> &Parent1, vector<int> &Parent2){
    std::map<int, set<int>> edge;
    vector<int> Offspring = {};
    int ind = 0;
    int len = Parent1.size();
    // cout << "ASD" << endl;
    for (int i=0; i<len; i++){
        ind = get_index(Parent2, Parent1[i]);
        edge[Parent1[i]] = {Parent1[(i+1+len)%len], Parent1[(i-1+len)%len], Parent2[(ind-1+len)%len], Parent1[(ind-1+len)%len]};
    }
    int r = Parent1[int(rand()) % len];
    Offspring.push_back(r);
    set<int> temp = {};
    while (Offspring.size() != len){
        temp = edge[r];
        DeleteFromMap(edge, r);
        r = choose(edge);
        Offspring.push_back(r);
    }
    return Offspring;
}

vector<int> best(const Graph &graph, vector<vector<int>> Gen){
    vector<int> temp;
    int min = 99999999;
    for (auto &i : Gen){
        if (Length(graph, i) < min){
            min = Length(graph, i);
            temp = i;
        }
    }
    return temp;
}


vector<int> tsp(const Graph &graph) {
    vector<int> ver = graph.get_vertices();
    if (ver.size() < 2) return {};
    vector<vector<int>> start_gen = new_gen(graph, ver);    //формирование нового гена или путя
    int it = 0;
    double weight_gen = 0;

    int MaxIt = 10;
    double Pm = 0.3;
    int N = 10;
    int P = 10;

    vector<vector<int>> N_p = SUS(graph, start_gen, N);
    set<vector<int>> sons = {};
    vector<int> Parent1 = {};
    vector<int> Parent2 = {};
    int p1 = 0;
    int p2 = 0;
    vector<int> temp = {};
    while (it < MaxIt){
        weight_gen = all_weight(graph, start_gen);
        N_p = SUS(graph, start_gen, N);
        while (sons.size() < P){
            p1 = rand() % int(N_p.size());
            p2 = rand() % int(N_p.size());
            if (p1 != p2) sons.insert(CrossovER(N_p[p1], N_p[p2]));
        }
        int m = 0;
        start_gen = {};
        for (auto i=sons.begin(); i!=sons.end(); i++){
            temp = *i;
            if (Rand(0, 1) < Pm){
                start_gen.push_back(TwoOptImprove(graph, temp));
            }
            else{
                start_gen.push_back(temp);
            }
        }
        // for (auto i : sons){
        //     // printv(i);
        //     start_gen.push_back(i);
        // }
        // printv(best(graph, start_gen));
        it++;
    }

    return best(graph, start_gen);
}
