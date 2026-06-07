#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "numeric"
#include "deque"
#include "queue"
#include "stack"
#include "unordered_set"
#include "set"
#include "unordered_map"
#include "map"
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root==nullptr) {
            return nullptr;
        }
        if (root->val<low) {
            TreeNode* right = trimBST(root->right,low,high);
            return right;
        }
        else if (root->val>high) {
            TreeNode* left = trimBST(root->left,low,high);
            return left;
        }

        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        return root;
    }
};