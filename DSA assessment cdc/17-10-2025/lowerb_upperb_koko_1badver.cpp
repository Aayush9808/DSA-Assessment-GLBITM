#include <vector>
using namespace std;

int lowerBound(vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}

int upperBound(vector<int>& arr, int target) {
    int left = 0, right = arr.size();
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return left;
}

int kokoEatingBananas(vector<int>& piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    while(left < right) {
        int mid = left + (right - left) / 2;
        long hours = 0;
        for(int pile : piles) {
            hours += (pile + mid - 1) / mid;
        }
        if(hours <= h) right = mid;
        else left = mid + 1;
    }
    return left;
}

int findFirstBadVersion(int n) {
    int left = 1, right = n;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(isBadVersion(mid)) right = mid;
        else left = mid + 1;
    }
    return left;
}

bool isBadVersion(int version);
