#include <stack>

#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
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
    void inorder(TreeNode* root,vector<int>& result) {
        if (root==nullptr) {
            return;
        }
        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root,result);
        return result;
    }
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur!=nullptr||!stk.empty()) {
            if (cur!=nullptr) {
                stk.push(cur);
                cur = cur->left;
            }
            else {
                TreeNode* temp = stk.top();
                stk.pop();
                result.push_back(temp->val);
                cur = temp->right;
            }
        }
        return result;
    }
};

int main() {

}