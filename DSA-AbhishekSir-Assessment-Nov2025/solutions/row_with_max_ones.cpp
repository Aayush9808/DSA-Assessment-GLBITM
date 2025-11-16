#include <bits/stdc++.h>
using namespace std;

int rowWithMaxOnes(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    
    int maxCnt = 0;
    int rowIdx = -1;
    
    for(int i=0; i<n; i++) {
        int cnt = 0;
        for(int j=0; j<m; j++) {
            if(arr[i][j] == 1) cnt++;
        }
        if(cnt > maxCnt) {
            maxCnt = cnt;
            rowIdx = i;
        }
    }
    return rowIdx;
}

// optimized
int rowWithMaxOnesOptimized(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    
    int i = 0, j = m-1;
    int maxRow = -1;
    
    while(i < n && j >= 0) {
        if(arr[i][j] == 1) {
            maxRow = i;
            j--;
        }
        else {
            i++;
        }
    }
    return maxRow;
}
