#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int countSquareSubmatrices(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int count = 0;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 1) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                count += dp[i][j];
            }
        }
    }
    return count;
}

int largestRectangleHistogram(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> s;
    
    for(int i = 0; i < n; i++) {
        while(!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? 0 : s.top() + 1;
        s.push(i);
    }
    
    while(!s.empty()) s.pop();
    
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n - 1 : s.top() - 1;
        s.push(i);
    }
    
    int maxArea = 0;
    for(int i = 0; i < n; i++) {
        int area = heights[i] * (right[i] - left[i] + 1);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty()) return 0;
    
    int m = matrix.size(), n = matrix[0].size();
    vector<int> heights(n, 0);
    int maxArea = 0;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        maxArea = max(maxArea, largestRectangleHistogram(heights));
    }
    return maxArea;
}
