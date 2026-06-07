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
    void traversal(TreeNode* root,int depth,int& max_depth,int& result) {
        if (root->left==nullptr&&root->right==nullptr) {
            if (depth>max_depth) {
                result = root->val;
                max_depth = depth;
            }
        }

        for (int i=0;i<2;i++) {
            if (i==0) {
                if (root->left) {
                    traversal(root->left,depth+1,max_depth,result);
                }
            }
            else {
                if (root->right) {
                    traversal(root->right,depth+1,max_depth,result);
                }
            }
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        int max_depth = INT_MIN;
        int result;
        traversal(root,0,max_depth,result);
        return result;
    }
};