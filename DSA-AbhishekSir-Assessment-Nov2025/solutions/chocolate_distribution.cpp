#include <bits/stdc++.h>
using namespace std;

int chocolateDistribution(vector<int>& arr, int m) {
    if(m == 0 || arr.size() == 0) return 0;
    if(arr.size() < m) return -1;
    
    sort(arr.begin(), arr.end());
    
    int mindiff = INT_MAX;
    for(int i=0; i+m-1<arr.size(); i++) {
        int diff = arr[i+m-1] - arr[i];
        mindiff = min(mindiff, diff);
    }
    return mindiff;
}
