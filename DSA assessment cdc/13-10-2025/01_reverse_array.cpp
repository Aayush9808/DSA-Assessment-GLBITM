/*
 * Problem: Reverse The Array
 * 
 * Problem Statement:
 * Given an arraylist 'ARR' of integers and a position 'M'. 
 * You have to reverse the array after that position.
 * 
 * Example:
 * ARR = {1, 2, 3, 4, 5, 6} and M = 3
 * Output: {1, 2, 3, 4, 6, 5}
 * (0-based indexing, subarray [5, 6] will be reversed)
 * 
 * Constraints:
 * 1 <= T <= 10
 * 0 <= M <= N <= 5*10^4
 * -10^9 <= ARR[i] <= 10^9
 * 
 * Time Limit: 1 sec
 */

#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int m) {
    int l = m + 1;           // Start from position after M
    int r = arr.size() - 1;  // End of array
    
    // Two pointer approach to reverse
    while(l < r) {
        swap(arr[l++], arr[r--]);
    }
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        reverseArray(arr, m);
        
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * 
 * Approach: Two Pointer Technique
 * - Start from position M+1 and end of array
 * - Swap elements and move pointers towards each other
 * - Stop when pointers meet
 */
