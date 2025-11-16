#include <vector>
using namespace std;

int rowWithMax1s(vector<vector<int>>& matrix) {
    int maxRow = -1;
    int maxCount = 0;
    int col = matrix[0].size() - 1;
    
    for(int row = 0; row < matrix.size(); row++) {
        while(col >= 0 && matrix[row][col] == 1) {
            col--;
            maxRow = row;
        }
    }
    return maxRow;
}
