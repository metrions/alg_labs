// #define CATCH_CONFIG_RUNNER


#include <iostream>
#include <vector>
#include "activities.h"
#include <chrono>

using namespace std::chrono;
using namespace std;

int main() {
    srand(32);

    vector<Activity> t = {};
    for (int i = 0; i<11; i++){
        t.push_back(Activity((int) rand(), (int) rand()));
    }
    auto t_1 = steady_clock::now();
    get_max_activities_slow(t);
    auto t_2 = steady_clock::now();
    cout << "slow - " << duration<double>(t_2 - t_1).count() << endl;

    t_1 = steady_clock::now();
    get_max_activities(t);
    t_2 = steady_clock::now();
    cout << "fast - " << duration<double>(t_2 - t_1).count() << endl;
}
