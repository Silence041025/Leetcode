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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size()==0) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(nums[nums.size()/2]);

        vector<int> left(nums.begin(),nums.begin()+nums.size()/2);
        vector<int> right(nums.begin()+nums.size()/2+1,nums.end());

        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);

        return root;
    }
};