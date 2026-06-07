#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "stack"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void preorder(TreeNode* root,vector<int>& result) {
        if (root==nullptr) {
            return;
        }

        result.push_back(root->val);
        preorder(root->left,result);
        preorder(root->right,result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root,result);
        return result;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> result;
        if (root==nullptr) return result;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* temp = stk.top();
            result.push_back(temp->val);
            stk.pop();

            if (temp->right)stk.push(temp->right);
            if (temp->left)stk.push(temp->left);
        }
        return result;
    }
};

int main() {
    
}