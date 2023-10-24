#include "activities.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <list>

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
    return t;
}

std::vector<Activity> get_max_activities_s(const std::vector<Activity> &activities) {
    std::vector<Activity> t = activities;    


}

void print(const std::vector<Activity> &activities){
    for (int i=0; i<activities.size(); i++){
        std::cout << activities[i].start << " " << activities[i].finish << std::endl;
    }
    std::cout << ":::::::::" << std::endl;
}

bool prav(const std::vector<Activity> &activities){
    int t;
    for (int i=0; i<activities.size(); i++){
        for (int j=0; j<activities.size(); j++){
            if (i != j){
                if ((activities[i].start > activities[j].start && activities[i].start < activities[j].finish)
                || (activities[i].finish > activities[j].start && activities[i].finish < activities[j].finish)
                ){
                    return false;
                }
            }
        }
    }
    return true;
}

std::vector<Activity> get_max_rec(const std::vector<Activity> &activities){
    std::vector<Activity> v;
    std::vector<Activity> answer = {};
    std::vector<Activity> t;
    if (activities.size() == 0) return {};
    else if (activities.size() == 1) return activities;
    if (prav(activities)) return activities;
    for (auto i=0; i<activities.size(); i++){
        for (int j=0; j<activities.size(); j++){
            if (i != j) v.push_back(activities[j]);
        }
        if (prav(v)){
            return v;
        }
        t = get_max_rec(v);
        if (t.size() > answer.size()) answer = t;
        v.clear();
    }
    return answer;
}

std::vector<Activity> get_max_activities_slow(const std::vector<Activity> &activities) {
    std::vector<Activity> sort_act(activities);
    std::sort(sort_act.begin(), sort_act.end(), [](const Activity &a, const Activity &b){
        return a.finish < b.finish;
    });
    return get_max_rec(sort_act);
}
