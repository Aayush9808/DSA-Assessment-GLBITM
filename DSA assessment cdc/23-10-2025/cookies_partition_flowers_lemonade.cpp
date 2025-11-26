#include <vector>
#include <algorithm>
using namespace std;

int assignCookies(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    int i = 0, j = 0;
    while(i < g.size() && j < s.size()) {
        if(s[j] >= g[i]) i++;
        j++;
    }
    return i;
}

vector<vector<int>> arrayPartition(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for(int i = 0; i < nums.size(); i += 2) {
        result.push_back({nums[i], nums[i+1]});
    }
    return result;
}

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    for(int i = 0; i < flowerbed.size(); i++) {
        if(flowerbed[i] == 0) {
            bool emptyLeft = (i == 0) || (flowerbed[i-1] == 0);
            bool emptyRight = (i == flowerbed.size()-1) || (flowerbed[i+1] == 0);
            
            if(emptyLeft && emptyRight) {
                flowerbed[i] = 1;
                count++;
            }
        }
    }
    return count >= n;
}

int lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for(int bill : bills) {
        if(bill == 5) five++;
        else if(bill == 10) {
            if(five == 0) return -1;
            five--;
            ten++;
        } else {
            if(ten > 0 && five > 0) {
                ten--;
                five--;
            } else if(five >= 3) {
                five -= 3;
            } else {
                return -1;
            }
        }
    }
    return 0;
}
