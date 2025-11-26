#include <vector>
using namespace std;

int countingBits(int n) {
    int count = 0;
    while(n) {
        count++;
        n &= (n - 1);
    }
    return count;
}

int singleNumberI(vector<int>& nums) {
    int result = 0;
    for(int num : nums) result ^= num;
    return result;
}

vector<int> singleNumberII(vector<int>& nums) {
    int xorResult = 0;
    for(int num : nums) xorResult ^= num;
    
    int rightmostBit = xorResult & -xorResult;
    int num1 = 0, num2 = 0;
    
    for(int num : nums) {
        if(num & rightmostBit) num1 ^= num;
        else num2 ^= num;
    }
    return {num1, num2};
}

bool isPowerSet(int n, int k) {
    return (n & (1 << k)) != 0;
}

vector<int> findMissingNumber(vector<int>& nums) {
    int xorResult = 0;
    for(int i = 0; i <= nums.size(); i++) xorResult ^= i;
    for(int num : nums) xorResult ^= num;
    return {xorResult};
}

int duplicateNumber(vector<int>& nums) {
    int xorResult = 0;
    for(int num : nums) xorResult ^= num;
    for(int i = 1; i < nums.size(); i++) xorResult ^= i;
    return xorResult;
}
