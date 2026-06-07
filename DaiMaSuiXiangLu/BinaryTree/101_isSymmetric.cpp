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
    bool compare(TreeNode* left,TreeNode* right) {
        if (left==nullptr&&right!=nullptr) {
            return false;
        }
        if (left!=nullptr&&right==nullptr) {
            return false;
        }
        if (left==nullptr&&right==nullptr) {
            return true;
        }
        if (left->val!=right->val) {
            return false;
        }
        //左右值相等，继续递归看outside,inside
        bool outside_result = compare(left->left,right->right);
        bool inside_result = compare(left->right,right->left);
        bool result = outside_result&&inside_result;
        return result;
    }
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr) {
            return true;
        }
        return compare(root->left,root->right);
    }
};