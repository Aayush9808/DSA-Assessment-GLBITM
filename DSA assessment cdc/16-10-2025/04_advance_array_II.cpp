#include <vector>
#include <algorithm>
using namespace std;

int maxWater(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxArea = 0;
    
    while(left < right) {
        int width = right - left;
        int h = min(height[left], height[right]);
        maxArea = max(maxArea, width * h);
        
        if(height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}

vector<int> mergeSortedArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    
    while(j >= 0) {
        if(i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
    return nums1;
}

int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;
    
    while(left < right) {
        if(height[left] < height[right]) {
            if(height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            if(height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }
    return water;
}
