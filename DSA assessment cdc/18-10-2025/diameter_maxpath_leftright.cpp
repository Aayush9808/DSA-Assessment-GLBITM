#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int diameter(TreeNode* root) {
    int maxDiam = 0;
    diameterHelper(root, maxDiam);
    return maxDiam;
}

int diameterHelper(TreeNode* root, int& maxDiam) {
    if(!root) return 0;
    int left = diameterHelper(root->left, maxDiam);
    int right = diameterHelper(root->right, maxDiam);
    maxDiam = max(maxDiam, left + right);
    return 1 + max(left, right);
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumHelper(root, maxSum);
    return maxSum;
}

int maxPathSumHelper(TreeNode* root, int& maxSum) {
    if(!root) return 0;
    int left = max(0, maxPathSumHelper(root->left, maxSum));
    int right = max(0, maxPathSumHelper(root->right, maxSum));
    maxSum = max(maxSum, left + right + root->val);
    return root->val + max(left, right);
}

void printLeftRight(TreeNode* root) {
    if(!root) return;
    if(root->left && root->right) {
        cout << root->val << " ";
    }
    printLeftRight(root->left);
    printLeftRight(root->right);
}
