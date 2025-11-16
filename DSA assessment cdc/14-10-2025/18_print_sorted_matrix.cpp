#include <vector>
#include <algorithm>
using namespace std;

vector<int> printSorted(vector<vector<int>>& matrix) {
    vector<int> result;
    for(auto& row : matrix) {
        for(int val : row) {
            result.push_back(val);
        }
    }
    sort(result.begin(), result.end());
    return result;
}
