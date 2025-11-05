#include <bits/stdc++.h>
using namespace std;

// brute force
int countInversion(vector<int>& arr) {
    int cnt = 0;
    for(int i=0; i<arr.size(); i++) {
        for(int j=i+1; j<arr.size(); j++) {
            if(arr[i] > arr[j]) cnt++;
        }
    }
    return cnt;
}

// merge function
long long merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    long long cnt = 0;

    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
    }
    return cnt;
}

long long mergeSort(vector<int> &arr, int low, int high) {
    long long cnt = 0;
    if(low >= high) return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}

long long countInversionOptimized(vector<int>& arr) {
    return mergeSort(arr, 0, arr.size()-1);
}
