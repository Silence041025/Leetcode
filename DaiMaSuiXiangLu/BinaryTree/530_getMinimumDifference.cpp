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
    void traverse(TreeNode* root,vector<int>& nums) {
        if (root==nullptr) {
            return;
        }

        traverse(root->left,nums);
        nums.push_back(root->val);
        traverse(root->right,nums);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> nums;
        traverse(root,nums);
        int result = INT_MAX;
        for (int i=0;i<nums.size()-1;i++) {
            result = min(result,abs(nums[i+1]-nums[i]));
        }

        return result;
    }
};