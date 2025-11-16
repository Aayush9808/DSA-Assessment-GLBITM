#include <bits/stdc++.h>
using namespace std;

vector<int> findElementsMoreThanNK(vector<int>& arr, int k) {
    vector<int> ans;
    map<int,int> mp;
    int n = arr.size();
    
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }
    
    for(auto x : mp) {
        if(x.second > n/k) {
            ans.push_back(x.first);
        }
    }
    return ans;
}
