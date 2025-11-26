#include <vector>
#include <set>
using namespace std;

vector<int> printSortedMatrix(vector<vector<int>>& matrix) {
    set<int> s;
    for(auto& row : matrix) {
        for(int val : row) {
            s.insert(val);
        }
    }
    return vector<int>(s.begin(), s.end());
}
