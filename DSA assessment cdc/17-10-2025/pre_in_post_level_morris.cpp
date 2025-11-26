#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode* root, vector<int>& result) {
    if(!root) return;
    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}

void inorder(TreeNode* root, vector<int>& result) {
    if(!root) return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

void postorder(TreeNode* root, vector<int>& result) {
    if(!root) return;
    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->val);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

vector<int> morrisTraversal(TreeNode* root) {
    vector<int> result;
    TreeNode* curr = root;
    
    while(curr) {
        if(!curr->left) {
            result.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* pred = curr->left;
            while(pred->right && pred->right != curr) {
                pred = pred->right;
            }
            
            if(!pred->right) {
                result.push_back(curr->val);
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = nullptr;
                curr = curr->right;
            }
        }
    }
    return result;
}
