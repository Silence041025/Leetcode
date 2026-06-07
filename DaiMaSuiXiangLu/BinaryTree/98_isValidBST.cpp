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
    bool isValid(TreeNode* root,long long parent_val_min,long long parent_val_max) {
        if (root==nullptr) {
            return true;
        }

        if (root->val<=parent_val_min||root->val>=parent_val_max) {
            return false;
        }

        return isValid(root->left,parent_val_min,root->val)
        &&isValid(root->right,root->val,parent_val_max);
    }

    bool isValidBST(TreeNode* root) {
        long long parent_val_min = LONG_LONG_MIN;
        long long parent_val_max = LONG_LONG_MAX;
        return isValid(root,parent_val_min,parent_val_max);
    }

    void traverse(TreeNode* root, vector<int>& nums) {
        if (root==nullptr) {
            return;
        }

        traverse(root->left,nums);
        nums.push_back(root->val);
        traverse(root->right,nums);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        traverse(root,nums);
        for (int i=0;i<nums.size()-1;i++) {
            if (nums[i]>=nums[i+1]) {
                return false;
            }
        }

        return true;
    }
};
