#include <bits/stdc++.h>
using namespace std;

bool findTripletSum(vector<int>& arr, int sum) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n-2; i++) {
        int l = i+1;
        int r = n-1;
        while(l < r) {
            int curr_sum = arr[i] + arr[l] + arr[r];
            if(curr_sum == sum)
                return true;
            else if(curr_sum < sum)
                l++;
            else
                r--;
        }
    }
    return false;
}

vector<vector<int>> findAllTriplets(vector<int>& arr, int target) {
    vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n-2; i++) {
        if(i > 0 && arr[i] == arr[i-1]) continue;
        
        int j = i+1;
        int k = n-1;
        
        while(j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum == target) {
                ans.push_back({arr[i], arr[j], arr[k]});
                j++; k--;
                while(j < k && arr[j] == arr[j-1]) j++;
                while(j < k && arr[k] == arr[k+1]) k--;
            }
            else if(sum < target) j++;
            else k--;
        }
    }
    return ans;
}
