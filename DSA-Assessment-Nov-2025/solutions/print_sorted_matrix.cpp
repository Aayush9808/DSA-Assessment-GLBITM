#include <bits/stdc++.h>
using namespace std;

vector<int> printSortedMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    vector<int> ans;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ans.push_back(mat[i][j]);
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}
