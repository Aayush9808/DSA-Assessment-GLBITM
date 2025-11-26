#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<vector<int>> intersectionOfArrays(vector<int>& nums1, vector<int>& nums2) {
    set<int> set1(nums1.begin(), nums1.end());
    vector<int> result;
    for(int num : nums2) {
        if(set1.count(num)) {
            result.push_back(num);
            set1.erase(num);
        }
    }
    return {result};
}

vector<vector<int>> getMatrixZeros(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRow = false, firstCol = false;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                if(i == 0) firstRow = true;
                if(j == 0) firstCol = true;
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    if(firstRow) {
        for(int j = 0; j < n; j++) matrix[0][j] = 0;
    }
    if(firstCol) {
        for(int i = 0; i < m; i++) matrix[i][0] = 0;
    }
    
    return {{}};
}

bool isValidAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    unordered_map<char, int> count;
    for(char c : s) count[c]++;
    for(char c : t) {
        if(!count[c]) return false;
        count[c]--;
    }
    return true;
}
