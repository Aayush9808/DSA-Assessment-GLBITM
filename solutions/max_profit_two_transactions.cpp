#include <bits/stdc++.h>
using namespace std;

int maxProfitTwoTransactions(vector<int>& prices) {
    int n = prices.size();
    if(n <= 1) return 0;
    
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    
    int mini = prices[0];
    for(int i=1; i<n; i++) {
        mini = min(mini, prices[i]);
        left[i] = max(left[i-1], prices[i] - mini);
    }
    
    int maxi = prices[n-1];
    for(int i=n-2; i>=0; i--) {
        maxi = max(maxi, prices[i]);
        right[i] = max(right[i+1], maxi - prices[i]);
    }
    
    int profit = 0;
    for(int i=0; i<n; i++) {
        profit = max(profit, left[i] + right[i]);
    }
    
    return profit;
}
