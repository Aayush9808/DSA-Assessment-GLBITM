#include <vector>
using namespace std;

int rowWithMax1s(vector<vector<int>>& matrix) {
    int maxRow = -1;
    int col = matrix[0].size() - 1;
    
    for(int i = 0; i < matrix.size(); i++) {
        while(col >= 0 && matrix[i][col] == 1) {
            col--;
            maxRow = i;
        }
    }
    return maxRow;
}
