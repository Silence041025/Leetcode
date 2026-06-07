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
    vector<int> robTree(TreeNode* root) {
        if (root==nullptr) {
            return {0,0};
        }

        vector<int> leftdp = robTree(root->left);
        vector<int> rightdp = robTree(root->right);
        int not_stolen = max(leftdp[0],leftdp[1])
        + max(rightdp[0],rightdp[1]);
        int stolen = root->val + leftdp[0] + rightdp[0];

        return {not_stolen,stolen};
    }

    int rob(TreeNode* root) {
        vector<int> results = robTree(root);

        return max(results[0],results[1]);
    }
};