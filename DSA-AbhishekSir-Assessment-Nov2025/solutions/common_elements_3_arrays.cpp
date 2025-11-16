#include <bits/stdc++.h>
using namespace std;

vector<int> findCommonElements(vector<int>& a, vector<int>& b, vector<int>& c) {
    vector<int> res;
    int i=0, j=0, k=0;
    
    while(i < a.size() && j < b.size() && k < c.size()) {
        if(a[i] == b[j] && b[j] == c[k]) {
            res.push_back(a[i]);
            i++; j++; k++;
        }
        else if(a[i] < b[j]) i++;
        else if(b[j] < c[k]) j++;
        else k++;
    }
    return res;
}
