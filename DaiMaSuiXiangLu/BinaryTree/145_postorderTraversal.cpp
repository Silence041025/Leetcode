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
    void postorder(TreeNode* root,vector<int>& result) {
        if (root==nullptr) {
            return;
        }
        postorder(root->left,result);
        postorder(root->right,result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root,result);
        return result;
    }
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        if (root==nullptr) return result;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* temp = stk.top();
            result.push_back(temp->val);
            stk.pop();

            if (temp->left)stk.push(temp->left);
            if (temp->right)stk.push(temp->right);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
int main() {

}