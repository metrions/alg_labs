#include <vector>
#include <iostream>
#include "tsp.h"
#include <chrono>

#include <algorithm>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
   Graph graph2{{0, 1, 2.0}, {0, 2, 4.0}, {0, 3, 1.0}, {0, 4, 2.5}, {0, 5, 3.2},
             {1, 2, 3.6}, {1, 3, 6.0}, {1, 4, 3.0}, {1, 5, 0.1},
             {2, 3, 7.0}, {2, 4, 5.0}, {2, 5, 9},
             {3, 4, 9.0}, {3, 5, 0.5},            
             {4, 5, 1.0}};
   Graph graph1 {{0, 1, 6.0}, {0, 2, 4.0}, {0, 3, 1.0},
             {1, 2, 3.5}, {1, 3, 2.0}, 
             {2, 3, 5.0}};
//    Graph graph3{{0, 1, 83}, {0, 2, 86}, {0, 3, 77}, {0, 4, 15}, {0, 5, 93}, {0, 6, 35}, {0, 7, 86}, {0, 8, 92}, {0, 9, 49}, {0, 10, 21}, {0, 11, 62}, {1, 0, 27}, {1, 2, 90}, {1, 3, 59}, {1, 4, 63}, {1, 5, 26}, {1, 6, 40}, {1, 7, 26}, {1, 8, 72}, {1, 9, 36}, {1, 10, 11}, {1, 11, 68}, {2, 0, 67}, {2, 1, 29}, {2, 3, 82}, {2, 4, 30}, {2, 5, 62}, {2, 6, 23}, {2, 7, 67}, {2, 8, 35}, {2, 9, 29}, {2, 10, 2}, {2, 11, 22}, {3, 0, 58}, {3, 1, 69}, {3, 2, 67}, {3, 4, 93}, {3, 5, 56}, {3, 6, 11}, {3, 7, 42}, {3, 8, 29}, {3, 9, 73}, {3, 10, 21}, {3, 11, 19}, {4, 0, 84}, {4, 1, 37}, {4, 2, 98}, {4, 3, 24}, {4, 5, 15}, {4, 6, 70}, {4, 7, 13}, {4, 8, 26}, {4, 9, 91}, {4, 10, 80}, {4, 11, 56}, {5, 0, 73}, {5, 1, 62}, {5, 2, 70}, {5, 3, 96}, {5, 4, 81}, {5, 6, 5}, {5, 7, 25}, {5, 8, 84}, {5, 9, 27}, {5, 10, 36}, {5, 11, 5}, {6, 0, 46}, {6, 1, 29}, {6, 2, 13}, {6, 3, 57}, {6, 4, 24}, {6, 5, 95}, {6, 7, 82}, {6, 8, 45}, {6, 9, 14}, {6, 10, 67}, {6, 11, 34}, {7, 0, 64}, {7, 1, 43}, {7, 2, 50}, {7, 3, 87}, {7, 4, 8}, {7, 5, 76}, {7, 6, 78}, {7, 8, 88}, {7, 9, 84}, {7, 10, 3}, {7, 11, 51}, {8, 0, 54}, {8, 1, 99}, {8, 2, 32}, {8, 3, 60}, {8, 4, 76}, {8, 5, 68}, {8, 6, 39}, {8, 7, 12}, {8, 9, 26}, {8, 10, 86}, {8, 11, 94}, {9, 0, 39}, {9, 1, 95}, {9, 2, 70}, {9, 3, 34}, {9, 4, 78}, {9, 5, 67}, {9, 6, 1}, {9, 7, 97}, {9, 8, 2}, {9, 10, 17}, {9, 11, 92}, {10, 0, 52}, {10, 1, 56}, {10, 2, 1}, {10, 3, 80}, {10, 4, 86}, {10, 5, 41}, {10, 6, 65}, {10, 7, 89}, {10, 8, 44}, {10, 9, 19}, {10, 11, 40}, {11, 0, 29}, {11, 1, 31}, {11, 2, 17}, {11, 3, 97}, {11, 4, 71}, {11, 5, 81}, {11, 6, 75}, {11, 7, 9}, {11, 8, 27}, {11, 9, 67}, {11, 10, 56}};
   Graph graph3{{0, 1, 83}, {0, 2, 86}, {0, 3, 77}, {0, 4, 15}, {0, 5, 93}, {0, 6, 35}, {0, 7, 86}, {0, 8, 92}, {0, 9, 49}, {1, 0, 21}, {1, 2, 62}, {1, 3, 27}, {1, 4, 90}, {1, 5, 59}, {1, 6, 63}, {1, 7, 26}, {1, 8, 40}, {1, 9, 26}, {2, 0, 72}, {2, 1, 36}, {2, 3, 11}, {2, 4, 68}, {2, 5, 67}, {2, 6, 29}, {2, 7, 82}, {2, 8, 30}, {2, 9, 62}, {3, 0, 23}, {3, 1, 67}, {3, 2, 35}, {3, 4, 29}, {3, 5, 2}, {3, 6, 22}, {3, 7, 58}, {3, 8, 69}, {3, 9, 67}, {4, 0, 93}, {4, 1, 56}, {4, 2, 11}, {4, 3, 42}, {4, 5, 29}, {4, 6, 73}, {4, 7, 21}, {4, 8, 19}, {4, 9, 84}, {5, 0, 37}, {5, 1, 98}, {5, 2, 24}, {5, 3, 15}, {5, 4, 70}, {5, 6, 13}, {5, 7, 26}, {5, 8, 91}, {5, 9, 80}, {6, 0, 56}, {6, 1, 73}, {6, 2, 62}, {6, 3, 70}, {6, 4, 96}, {6, 5, 81}, {6, 7, 5}, {6, 8, 25}, {6, 9, 84}, {7, 0, 27}, {7, 1, 36}, {7, 2, 5}, {7, 3, 46}, {7, 4, 29}, {7, 5, 13}, {7, 6, 57}, {7, 8, 24}, {7, 9, 95}, {8, 0, 82}, {8, 1, 45}, {8, 2, 14}, {8, 3, 67}, {8, 4, 34}, {8, 5, 64}, {8, 6, 43}, {8, 7, 50}, {8, 9, 87}, {9, 0, 8}, {9, 1, 76}, {9, 2, 78}, {9, 3, 88}, {9, 4, 84}, {9, 5, 3}, {9, 6, 51}, {9, 7, 54}, {9, 8, 99}};
   // Graph graph{{0, 1, 83}, {0, 2, 86}, {0, 3, 77}, {0, 4, 15}, {0, 5, 93}, {0, 6, 35}, {0, 7, 86}, {0, 8, 92}, {0, 9, 49}, {0, 10, 21}, {0, 11, 62}, {0, 12, 27}, {0, 13, 90}, {0, 14, 59}, {0, 15, 63}, {0, 16, 26}, {0, 17, 40}, {0, 18, 26}, {0, 19, 72}, {1, 0, 36}, {1, 2, 11}, {1, 3, 68}, {1, 4, 67}, {1, 5, 29}, {1, 6, 82}, {1, 7, 30}, {1, 8, 62}, {1, 9, 23}, {1, 10, 67}, {1, 11, 35}, {1, 12, 29}, {1, 13, 2}, {1, 14, 22}, {1, 15, 58}, {1, 16, 69}, {1, 17, 67}, {1, 18, 93}, {1, 19, 56}, {2, 0, 11}, {2, 1, 42}, {2, 3, 29}, {2, 4, 73}, {2, 5, 21}, {2, 6, 19}, {2, 7, 84}, {2, 8, 37}, {2, 9, 98}, {2, 10, 24}, {2, 11, 15}, {2, 12, 70}, {2, 13, 13}, {2, 14, 26}, {2, 15, 91}, {2, 16, 80}, {2, 17, 56}, {2, 18, 73}, {2, 19, 62}, {3, 0, 70}, {3, 1, 96}, {3, 2, 81}, {3, 4, 5}, {3, 5, 25}, {3, 6, 84}, {3, 7, 27}, {3, 8, 36}, {3, 9, 5}, {3, 10, 46}, {3, 11, 29}, {3, 12, 13}, {3, 13, 57}, {3, 14, 24}, {3, 15, 95}, {3, 16, 82}, {3, 17, 45}, {3, 18, 14}, {3, 19, 67}, {4, 0, 34}, {4, 1, 64}, {4, 2, 43}, {4, 3, 50}, {4, 5, 87}, {4, 6, 8}, {4, 7, 76}, {4, 8, 78}, {4, 9, 88}, {4, 10, 84}, {4, 11, 3}, {4, 12, 51}, {4, 13, 54}, {4, 14, 99}, {4, 15, 32}, {4, 16, 60}, {4, 17, 76}, {4, 18, 68}, {4, 19, 39}, {5, 0, 12}, {5, 1, 26}, {5, 2, 86}, {5, 3, 94}, {5, 4, 39}, {5, 6, 95}, {5, 7, 70}, {5, 8, 34}, {5, 9, 78}, {5, 10, 67}, {5, 11, 1}, {5, 12, 97}, {5, 13, 2}, {5, 14, 17}, {5, 15, 92}, {5, 16, 52}, {5, 17, 56}, {5, 18, 1}, {5, 19, 80}, {6, 0, 86}, {6, 1, 41}, {6, 2, 65}, {6, 3, 89}, {6, 4, 44}, {6, 5, 19}, {6, 7, 40}, {6, 8, 29}, {6, 9, 31}, {6, 10, 17}, {6, 11, 97}, {6, 12, 71}, {6, 13, 81}, {6, 14, 75}, {6, 15, 9}, {6, 16, 27}, {6, 17, 67}, {6, 18, 56}, {6, 19, 97}, {7, 0, 53}, {7, 1, 86}, {7, 2, 65}, {7, 3, 6}, {7, 4, 83}, {7, 5, 19}, {7, 6, 24}, {7, 8, 28}, {7, 9, 71}, {7, 10, 32}, {7, 11, 29}, {7, 12, 3}, {7, 13, 19}, {7, 14, 70}, {7, 15, 68}, {7, 16, 8}, {7, 17, 15}, {7, 18, 40}, {7, 19, 49}, {8, 0, 96}, {8, 1, 23}, {8, 2, 18}, {8, 3, 45}, {8, 4, 46}, {8, 5, 51}, {8, 6, 21}, {8, 7, 55}, {8, 9, 79}, {8, 10, 88}, {8, 11, 64}, {8, 12, 28}, {8, 13, 41}, {8, 14, 50}, {8, 15, 93}, {8, 16, 0}, {8, 17, 34}, {8, 18, 64}, {8, 19, 24}, {9, 0, 14}, {9, 1, 87}, {9, 2, 56}, {9, 3, 43}, {9, 4, 91}, {9, 5, 27}, {9, 6, 65}, {9, 7, 59}, {9, 8, 36}, {9, 10, 32}, {9, 11, 51}, {9, 12, 37}, {9, 13, 28}, {9, 14, 75}, {9, 15, 7}, {9, 16, 74}, {9, 17, 21}, {9, 18, 58}, {9, 19, 95}, {10, 0, 29}, {10, 1, 37}, {10, 2, 35}, {10, 3, 93}, {10, 4, 18}, {10, 5, 28}, {10, 6, 43}, {10, 7, 11}, {10, 8, 28}, {10, 9, 29}, {10, 11, 76}, {10, 12, 4}, {10, 13, 43}, {10, 14, 63}, {10, 15, 13}, {10, 16, 38}, {10, 17, 6}, {10, 18, 40}, {10, 19, 4}, {11, 0, 18}, {11, 1, 28}, {11, 2, 88}, {11, 3, 69}, {11, 4, 17}, {11, 5, 17}, {11, 6, 96}, {11, 7, 24}, {11, 8, 43}, {11, 9, 70}, {11, 10, 83}, {11, 12, 90}, {11, 13, 99}, {11, 14, 72}, {11, 15, 25}, {11, 16, 44}, {11, 17, 90}, {11, 18, 5}, {11, 19, 39}, {12, 0, 54}, {12, 1, 86}, {12, 2, 69}, {12, 3, 82}, {12, 4, 42}, {12, 5, 64}, {12, 6, 97}, {12, 7, 7}, {12, 8, 55}, {12, 9, 4}, {12, 10, 48}, {12, 11, 11}, {12, 13, 22}, {12, 14, 28}, {12, 15, 99}, {12, 16, 43}, {12, 17, 46}, {12, 18, 68}, {12, 19, 40}, {13, 0, 22}, {13, 1, 11}, {13, 2, 10}, {13, 3, 5}, {13, 4, 1}, {13, 5, 61}, {13, 6, 30}, {13, 7, 78}, {13, 8, 5}, {13, 9, 20}, {13, 10, 36}, {13, 11, 44}, {13, 12, 26}, {13, 14, 22}, {13, 15, 65}, {13, 16, 8}, {13, 17, 16}, {13, 18, 82}, {13, 19, 58}, {14, 0, 24}, {14, 1, 37}, {14, 2, 62}, {14, 3, 24}, {14, 4, 0}, {14, 5, 36}, {14, 6, 52}, {14, 7, 99}, {14, 8, 79}, {14, 9, 50}, {14, 10, 68}, {14, 11, 71}, {14, 12, 73}, {14, 13, 31}, {14, 15, 81}, {14, 16, 30}, {14, 17, 33}, {14, 18, 94}, {14, 19, 60}, {15, 0, 63}, {15, 1, 99}, {15, 2, 81}, {15, 3, 99}, {15, 4, 96}, {15, 5, 59}, {15, 6, 73}, {15, 7, 13}, {15, 8, 68}, {15, 9, 90}, {15, 10, 95}, {15, 11, 26}, {15, 12, 66}, {15, 13, 84}, {15, 14, 40}, {15, 16, 90}, {15, 17, 84}, {15, 18, 76}, {15, 19, 42}, {16, 0, 36}, {16, 1, 7}, {16, 2, 45}, {16, 3, 56}, {16, 4, 79}, {16, 5, 18}, {16, 6, 87}, {16, 7, 12}, {16, 8, 48}, {16, 9, 72}, {16, 10, 59}, {16, 11, 9}, {16, 12, 36}, {16, 13, 10}, {16, 14, 42}, {16, 15, 87}, {16, 17, 6}, {16, 18, 1}, {16, 19, 13}, {17, 0, 72}, {17, 1, 21}, {17, 2, 55}, {17, 3, 19}, {17, 4, 99}, {17, 5, 21}, {17, 6, 4}, {17, 7, 39}, {17, 8, 11}, {17, 9, 40}, {17, 10, 67}, {17, 11, 5}, {17, 12, 28}, {17, 13, 27}, {17, 14, 50}, {17, 15, 84}, {17, 16, 58}, {17, 18, 20}, {17, 19, 24}, {18, 0, 22}, {18, 1, 69}, {18, 2, 96}, {18, 3, 81}, {18, 4, 30}, {18, 5, 84}, {18, 6, 92}, {18, 7, 72}, {18, 8, 72}, {18, 9, 50}, {18, 10, 25}, {18, 11, 85}, {18, 12, 22}, {18, 13, 99}, {18, 14, 40}, {18, 15, 42}, {18, 16, 98}, {18, 17, 13}, {18, 19, 98}, {19, 0, 90}, {19, 1, 24}, {19, 2, 90}, {19, 3, 9}, {19, 4, 81}, {19, 5, 19}, {19, 6, 36}, {19, 7, 32}, {19, 8, 55}, {19, 9, 94}, {19, 10, 4}, {19, 11, 79}, {19, 12, 69}, {19, 13, 73}, {19, 14, 76}, {19, 15, 50}, {19, 16, 55}, {19, 17, 60}, {19, 18, 42}};
   

//    for (int i=0; i<10; i++){
//         for (int j = 0; j<10; j++){
//             if (i != j) cout << "{" << i << ", " << j << ", " << rand()%100 << "}, ";
//         }
//     }
   auto t_1 = steady_clock::now();
   vector<int> t;
   auto t_2 = steady_clock::now();

   t_1 = steady_clock::now();
   t = tsp(graph1);
   t_2 = steady_clock::now();
   cout << "Time: " << duration<double>(t_2 - t_1).count() << endl; 
   cout << "Weight: " << Length(graph1, t) << endl;

   t_1 = steady_clock::now();
   t = tsp(graph2);
   t_2 = steady_clock::now();
   cout << "Time: " << duration<double>(t_2 - t_1).count() << endl; 
   cout << "Weight: " << Length(graph2, t) << endl;

   t_1 = steady_clock::now();
   t = tsp(graph3);
   t_2 = steady_clock::now();
   cout << "Time: " << duration<double>(t_2 - t_1).count() << endl; 
   cout << "Weight: " << Length(graph3, t) << endl;
}
