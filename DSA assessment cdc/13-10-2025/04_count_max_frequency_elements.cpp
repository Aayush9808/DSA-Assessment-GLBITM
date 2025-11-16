#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> freq;
    int maxFreq = 0;
    
    for(int num : nums) {
        freq[num]++;
        maxFreq = max(maxFreq, freq[num]);
    }
    
    int count = 0;
    for(auto& p : freq) {
        if(p.second == maxFreq) {
            count += maxFreq;
        }
    }
    
    return count;
}
