#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumOfLeaves(TreeNode* root) {
    if(!root) return 0;
    if(!root->left && !root->right) return root->val;
    return sumOfLeaves(root->left) + sumOfLeaves(root->right);
}

int topView(TreeNode* root) {
    if(!root) return 0;
    return root->val;
}

int bottomView(TreeNode* root) {
    if(!root) return 0;
    if(!root->left && !root->right) return root->val;
    int left = bottomView(root->left);
    int right = bottomView(root->right);
    return left != 0 ? left : (right != 0 ? right : root->val);
}
