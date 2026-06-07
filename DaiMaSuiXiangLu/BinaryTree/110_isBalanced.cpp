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
    int height(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }

        int left_height = height(root->left);
        int right_height = height(root->right);
        int result = max(left_height,right_height) + 1;
        return result;
    }
    bool isBalanced(TreeNode* root) {
       if (root==nullptr) {
           return true;
       }

       if (abs(height(root->left)-height(root->right))>1) {
           return false;
       }

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
