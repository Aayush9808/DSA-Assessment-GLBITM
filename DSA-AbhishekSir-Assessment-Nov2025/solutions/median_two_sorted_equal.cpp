#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArraysEqual(vector<int>& a, vector<int>& b) {
    int n = a.size();
    if(n == 0) return 0.0;
    
    int i=0, j=0, cnt=0;
    int m1=-1, m2=-1;
    
    for(cnt=0; cnt<=n; cnt++) {
        if(i == n) {
            m1 = m2;
            m2 = b[0];
            break;
        }
        else if(j == n) {
            m1 = m2;
            m2 = a[0];
            break;
        }
        
        if(a[i] <= b[j]) {
            m1 = m2;
            m2 = a[i];
            i++;
        }
        else {
            m1 = m2;
            m2 = b[j];
            j++;
        }
    }
    
    return (m1 + m2) / 2.0;
}

// binary search approach
double findMedianSortedArraysEqualOptimized(vector<int>& a, vector<int>& b) {
    int n = a.size();
    if(n == 0) return 0.0;
    if(n == 1) return (a[0] + b[0]) / 2.0;
    
    if(a[n-1] < b[0]) return (a[n-1] + b[0]) / 2.0;
    if(b[n-1] < a[0]) return (b[n-1] + a[0]) / 2.0;
    
    int low=0, high=n;
    
    while(low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = n - cut1;
        
        int l1 = (cut1 == 0) ? INT_MIN : a[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2-1];
        int r1 = (cut1 == n) ? INT_MAX : a[cut1];
        int r2 = (cut2 == n) ? INT_MAX : b[cut2];
        
        if(l1 <= r2 && l2 <= r1) {
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if(l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1;
        }
    }
    return 0.0;
}
