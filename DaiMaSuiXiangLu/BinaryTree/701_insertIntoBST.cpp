#include "vector"
#include "TreeNode.h"
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
using namespace std;

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root==nullptr) {
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        if (root->val < val) {
            root->right = insertIntoBST(root->right,val);
        }
        else if (root->val > val) {
            root->left = insertIntoBST(root->left,val);
        }

        return root;
    }
};