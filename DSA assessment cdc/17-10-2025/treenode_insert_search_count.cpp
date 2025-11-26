#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createTree(int val) {
    return new TreeNode(val);
}

int getType(TreeNode* root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 1; // Leaf
    if(root->left && root->right) return 2; // Internal
    return 3; // Has one child
}

TreeNode* insertNode(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    if(val < root->val) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);
    return root;
}
