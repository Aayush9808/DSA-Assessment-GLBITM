#include <vector>
#include <algorithm>
using namespace std;

int activitySelection(vector<int>& start, vector<int>& end) {
    vector<pair<int,int>> activities;
    for(int i = 0; i < start.size(); i++) {
        activities.push_back({end[i], start[i]});
    }
    sort(activities.begin(), activities.end());
    
    int count = 1;
    int lastEnd = activities[0].first;
    
    for(int i = 1; i < activities.size(); i++) {
        if(activities[i].second >= lastEnd) {
            count++;
            lastEnd = activities[i].first;
        }
    }
    return count;
}

int minimumPlatforms(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    
    int platforms = 1, maxPlatforms = 1;
    int i = 1, j = 0;
    
    while(i < arr.size() && j < dep.size()) {
        if(arr[i] <= dep[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, platforms);
    }
    return maxPlatforms;
}

int coinChange(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend());
    int count = 0;
    
    for(int coin : coins) {
        while(amount >= coin) {
            amount -= coin;
            count++;
        }
    }
    return amount == 0 ? count : -1;
}
