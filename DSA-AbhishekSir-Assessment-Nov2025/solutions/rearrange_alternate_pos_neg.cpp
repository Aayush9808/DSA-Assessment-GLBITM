#include <bits/stdc++.h>
using namespace std;

void rearrangeAlternate(vector<int>& arr) {
    int n = arr.size();
    
    for(int i=0; i<n; i++) {
        // positive should be at even, negative at odd
        if(i%2 == 0 && arr[i] < 0) {
            // find next positive
            int j = i+1;
            while(j < n && arr[j] < 0) j++;
            
            if(j < n) {
                int temp = arr[j];
                while(j > i) {
                    arr[j] = arr[j-1];
                    j--;
                }
                arr[i] = temp;
            }
        }
        else if(i%2 == 1 && arr[i] >= 0) {
            // find next negative
            int j = i+1;
            while(j < n && arr[j] >= 0) j++;
            
            if(j < n) {
                int temp = arr[j];
                while(j > i) {
                    arr[j] = arr[j-1];
                    j--;
                }
                arr[i] = temp;
            }
        }
    }
}
