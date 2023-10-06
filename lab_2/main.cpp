#include "closest_pair.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// const int N = 1;

int main() {
    std::vector <Point> k(100);
    int s =0;
    for (int i=0; i<100; i++){
        k.push_back(Point(double(rand()%10000), double(rand()%10000)));
    }
    auto t_1 = steady_clock::now();
    auto q = closest_pair_slow(k);
    auto t_2 = steady_clock::now();
    cout << "N: " << 100 << "\n";
    cout << "slow - " << duration<double>(t_2 - t_1).count() << endl;

    t_1 = steady_clock::now();
    q = closest_fast(k);
    t_2 = steady_clock::now();
    cout << "fast - " << duration<double>(t_2 - t_1).count() << endl;
}
