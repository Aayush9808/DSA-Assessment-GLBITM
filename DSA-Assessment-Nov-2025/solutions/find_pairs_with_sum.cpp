#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> findPairsWithSum(vector<int>& arr, int sum) {
    vector<pair<int,int>> ans;
    unordered_map<int,int> mp;
    
    for(int i=0; i<arr.size(); i++) {
        int rem = sum - arr[i];
        if(mp.find(rem) != mp.end()) {
            ans.push_back({rem, arr[i]});
        }
        mp[arr[i]]++;
    }
    return ans;
}
