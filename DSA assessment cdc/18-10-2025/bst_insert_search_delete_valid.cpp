#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertBST(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    if(val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

TreeNode* searchBST(TreeNode* root, int val) {
    if(!root || root->val == val) return root;
    if(val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}

TreeNode* deleteBST(TreeNode* root, int key) {
    if(!root) return nullptr;
    
    if(key < root->val) {
        root->left = deleteBST(root->left, key);
    } else if(key > root->val) {
        root->right = deleteBST(root->right, key);
    } else {
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        
        TreeNode* minNode = findMin(root->right);
        root->val = minNode->val;
        root->right = deleteBST(root->right, minNode->val);
    }
    return root;
}

TreeNode* findMin(TreeNode* root) {
    while(root->left) root = root->left;
    return root;
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}

bool isValidBSTHelper(TreeNode* root, long minVal, long maxVal) {
    if(!root) return true;
    if(root->val <= minVal || root->val >= maxVal) return false;
    return isValidBSTHelper(root->left, minVal, root->val) && 
           isValidBSTHelper(root->right, root->val, maxVal);
}
