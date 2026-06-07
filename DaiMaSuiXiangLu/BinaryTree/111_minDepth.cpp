#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "queue"
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
    int minDepth(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }

        int left_height = minDepth(root->left);
        int right_height = minDepth(root->right);
        if(root->left==nullptr&&root->right!=nullptr) {
            return right_height + 1;
        }
        if(root->left!=nullptr&&root->right==nullptr) {
            return left_height + 1;
        }

        return min(left_height,right_height) + 1;

    }
};