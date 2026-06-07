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
    TreeNode* invertTree(TreeNode* root) {
        if (root==nullptr) {
            return root;
        }

        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};