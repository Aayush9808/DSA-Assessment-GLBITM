#include <vector>
#include <algorithm>
using namespace std;

int medianRowSorted(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int minVal = matrix[0][0], maxVal = matrix[0][cols-1];
    
    for(int i = 1; i < rows; i++) {
        minVal = min(minVal, matrix[i][0]);
        maxVal = max(maxVal, matrix[i][cols-1]);
    }
    
    int desired = (rows * cols + 1) / 2;
    
    while(minVal < maxVal) {
        int mid = minVal + (maxVal - minVal) / 2;
        int count = 0;
        
        for(int i = 0; i < rows; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        
        if(count < desired) minVal = mid + 1;
        else maxVal = mid;
    }
    return minVal;
}
