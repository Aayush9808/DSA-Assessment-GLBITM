#include <bits/stdc++.h>
using namespace std;

bool hasSubarraySumZero(vector<int>& arr) {
    unordered_set<int> s;
    int sum = 0;
    
    for(int i=0; i<arr.size(); i++) {
        sum += arr[i];
        if(sum == 0 || s.find(sum) != s.end()) {
            return true;
        }
        s.insert(sum);
    }
    return false;
}
