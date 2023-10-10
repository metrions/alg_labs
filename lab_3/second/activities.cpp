#include "activities.h"
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<Activity> get_max_activities(const std::vector<Activity> &activities) {
    std::vector<Activity> sort_act(activities);
    std::sort(sort_act.begin(), sort_act.end(), [](const Activity &a, const Activity &b){
        return a.finish < b.finish;
    });
    // for (auto q : sort_act){
    //     std::cout << q.finish << " ";
    // }
    std::vector<Activity> t = {};
    int Current = 0;
    int Next = 0;
    while (Current < int(sort_act.size())){
        t.push_back(sort_act[Current]);
        Next = Current + 1;
        while (Next<sort_act.size() && ((sort_act[Next]).start < (sort_act[Current]).finish)){
            Next++;
        }
        Current = Next;
    }
    std::cout <<t.size() << "\n";
    return t;
}
