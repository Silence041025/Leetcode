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
    void dfs(TreeNode* root,int sum,int target,bool& result) {
        if (root->left==nullptr&&root->right==nullptr) {
            if (sum==target) {
                result = true;
                return;
            }
            return;
        }

        for (int i=0;i<2;i++) {
            if (i==0) {
                if (root->left) {
                    sum += root->left->val;
                    dfs(root->left,sum,target,result);
                    sum -= root->left->val;
                }
            }
            else {
                if (root->right) {
                    sum += root->right->val;
                    dfs(root->right,sum,target,result);
                    sum -= root->right->val;
                }
            }
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool result = false;
        if (root==nullptr) {
            return false;
        }
        int sum = root->val;
        dfs(root,sum,targetSum,result);
        return result;
    }
};