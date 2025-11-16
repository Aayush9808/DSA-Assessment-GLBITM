#include <bits/stdc++.h>
using namespace std;

int smallestSubarrayWithGreaterSum(vector<int>& arr, int x) {
    int n = arr.size();
    int minlen = INT_MAX;
    int sum = 0;
    int start = 0;
    
    for(int end=0; end<n; end++) {
        sum += arr[end];
        
        while(sum > x) {
            minlen = min(minlen, end-start+1);
            sum -= arr[start];
            start++;
        }
    }
    
    return (minlen == INT_MAX) ? 0 : minlen;
}
