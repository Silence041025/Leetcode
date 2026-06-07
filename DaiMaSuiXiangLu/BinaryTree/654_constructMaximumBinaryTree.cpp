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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size()==0) {
            return nullptr;
        }
        int root_index = 0;
        int root_val = nums[0];
        for (int i=0;i<nums.size();i++) {
            if (nums[i]>root_val) {
                root_val = nums[i];
                root_index = i;
            }
        }
        TreeNode* root = new TreeNode(root_val);
        if (nums.size()==1) {
            return root;
        }

        vector<int> left_nums(nums.begin(),nums.begin()+root_index);
        vector<int> right_nums(nums.begin()+root_index+1,nums.end());
        root->left = constructMaximumBinaryTree(left_nums);
        root->right = constructMaximumBinaryTree(right_nums);

        return root;
    }
};