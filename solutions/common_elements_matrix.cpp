#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    map<int,int> mp;
    
    for(int j=0; j<m; j++) {
        mp[mat[0][j]] = 1;
    }
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mp[mat[i][j]] == i) {
                mp[mat[i][j]] = i+1;
            }
        }
    }
    
    vector<int> ans;
    for(auto x : mp) {
        if(x.second == n) {
            ans.push_back(x.first);
        }
    }
    return ans;
}
