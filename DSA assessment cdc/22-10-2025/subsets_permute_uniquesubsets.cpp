#include <vector>
#include <string>
using namespace std;

void printAllSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);
    
    for(int i = index; i < nums.size(); i++) {
        current.push_back(nums[i]);
        printAllSubsets(nums, i + 1, current, result);
        current.pop_back();
    }
}

void permutations(string s, int l, int r, vector<string>& result) {
    if(l == r) {
        result.push_back(s);
        return;
    }
    
    for(int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permutations(s, l + 1, r, result);
        swap(s[l], s[i]);
    }
}

vector<string> findAllUniqueSubsets(string s) {
    vector<string> result;
    string current = "";
    for(int i = 0; i < (1 << s.length()); i++) {
        current = "";
        for(int j = 0; j < s.length(); j++) {
            if(i & (1 << j)) current += s[j];
        }
        result.push_back(current);
    }
    return result;
}
