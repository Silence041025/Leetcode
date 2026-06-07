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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }
        if (root->left==nullptr&&root->right==nullptr) {
            return 0;
        }

        int count = 0;
        if (root->left!=nullptr&&root->left->left==nullptr&&root->left->right==nullptr) {
            count = root->left->val;
        }
        int left_count = sumOfLeftLeaves(root->left);
        int right_count = sumOfLeftLeaves(root->right);
        return count + left_count + right_count;
    }
};