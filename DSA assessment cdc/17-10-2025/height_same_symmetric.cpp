#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int height(TreeNode* root) {
    if(!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    if(!p || !q) return false;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    return isMirror(root->left, root->right);
}

bool isMirror(TreeNode* left, TreeNode* right) {
    if(!left && !right) return true;
    if(!left || !right) return false;
    return left->val == right->val && isMirror(left->left, right->right) && isMirror(left->right, right->left);
}
