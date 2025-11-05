#include <bits/stdc++.h>
using namespace std;

int minOperationsToPalindrome(vector<int>& arr) {
    int n = arr.size();
    int i = 0, j = n-1;
    int cnt = 0;
    
    while(i < j) {
        if(arr[i] == arr[j]) {
            i++; j--;
        }
        else if(arr[i] < arr[j]) {
            i++;
            arr[i] += arr[i-1];
            cnt++;
        }
        else {
            j--;
            arr[j] += arr[j+1];
            cnt++;
        }
    }
    return cnt;
}
