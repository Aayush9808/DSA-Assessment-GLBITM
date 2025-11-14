#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& arr) {
    int n = arr.size();
    int idx = -1;
    
    // finding break point
    for(int i = n-2; i >= 0; i--) {
        if(arr[i] < arr[i+1]) {
            idx = i;
            break;
        }
    }
    
    if(idx == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }
    
    // find next greater element and swap
    for(int i = n-1; i > idx; i--) {
        if(arr[i] > arr[idx]) {
            swap(arr[i], arr[idx]);
            break;
        }
    }
    
    // reverse rest
    reverse(arr.begin() + idx + 1, arr.end());
}
