#include <bits/stdc++.h>
using namespace std;

int findSpecificPair(vector<vector<int>>& mat) {
    int n = mat.size();
    
    int maxVal = INT_MIN;
    vector<vector<int>> maxArr(n, vector<int>(n));
    
    maxArr[n-1][n-1] = mat[n-1][n-1];
    
    int maxv = mat[n-1][n-1];
    for(int j=n-2; j>=0; j--) {
        if(mat[n-1][j] > maxv)
            maxv = mat[n-1][j];
        maxArr[n-1][j] = maxv;
    }
    
    maxv = mat[n-1][n-1];
    for(int i=n-2; i>=0; i--) {
        if(mat[i][n-1] > maxv)
            maxv = mat[i][n-1];
        maxArr[i][n-1] = maxv;
    }
    
    for(int i=n-2; i>=0; i--) {
        for(int j=n-2; j>=0; j--) {
            maxVal = max(maxVal, maxArr[i+1][j+1] - mat[i][j]);
            maxArr[i][j] = max(mat[i][j], max(maxArr[i][j+1], maxArr[i+1][j]));
        }
    }
    
    return maxVal;
}
