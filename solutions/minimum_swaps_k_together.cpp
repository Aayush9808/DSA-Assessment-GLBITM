#include <bits/stdc++.h>
using namespace std;

int minSwapsToGroupLessThanK(vector<int>& arr, int k) {
    int n = arr.size();
    
    // count total elements <= k
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] <= k) cnt++;
    }
    
    // count bad elements in first window
    int bad = 0;
    for(int i=0; i<cnt; i++) {
        if(arr[i] > k) bad++;
    }
    
    int ans = bad;
    
    // sliding window
    for(int i=0, j=cnt; j<n; i++, j++) {
        if(arr[i] > k) bad--;
        if(arr[j] > k) bad++;
        ans = min(ans, bad);
    }
    
    return ans;
}
