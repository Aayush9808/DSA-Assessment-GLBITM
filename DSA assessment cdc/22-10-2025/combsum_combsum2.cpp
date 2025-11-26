#include <vector>
using namespace std;

void combinationSum(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& result) {
    if(target == 0) {
        result.push_back(current);
        return;
    }
    
    for(int i = index; i < candidates.size(); i++) {
        if(candidates[i] <= target) {
            current.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
}

void combinationSumII(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& result) {
    if(target == 0) {
        result.push_back(current);
        return;
    }
    
    for(int i = index; i < candidates.size(); i++) {
        if(i > index && candidates[i] == candidates[i-1]) continue;
        if(candidates[i] <= target) {
            current.push_back(candidates[i]);
            combinationSumII(candidates, target - candidates[i], i + 1, current, result);
            current.pop_back();
        }
    }
}
