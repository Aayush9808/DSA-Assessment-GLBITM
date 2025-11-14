#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& arr) {
    if(arr.size() == 0) return 0;
    
    unordered_set<int> st;
    for(int i=0; i<arr.size(); i++) {
        st.insert(arr[i]);
    }
    
    int longest = 1;
    for(auto it : st) {
        if(st.find(it-1) == st.end()) {
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()) {
                x++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
