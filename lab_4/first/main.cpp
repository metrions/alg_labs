#include <vector>
#include "shortest_path.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
    srand(10);
   Graph g {};
   const int k = 10000;
   int a[k];
   for (int i=0; i<k; i++){
      a[i] = i;
      g.add_vertex(i);
   }
   for (int i=0; i<k-1; i++){
      for (int j=i+1; j<k; j++){
         if (rand()%10 == 0) g.add_edge(a[i], a[j], rand()%10000);
      }
   }
   double sum = 0;
   auto t_1 = steady_clock::now();
   auto t_2 = steady_clock::now();
   vector<int> answer;
   for (int i=0; i<k; i++){
      t_1 = steady_clock::now();
      vector<int> answer = shortest_path(g, rand()%k, rand()%k);
      t_2 = steady_clock::now();
      sum += duration<double>(t_2 - t_1).count();
   }
   cout << "N: " << k << " ";
   cout << "sr - " << sum/k << endl;
   // for (auto i=answer.begin(); i!=answer.end(); i++){
   //    cout << *i << " ";
   // }
}
