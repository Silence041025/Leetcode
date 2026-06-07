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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr) {
            return nullptr;
            //return nullptr
        }
        if (root==p||root==q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if (left!=nullptr&&right!=nullptr) {
            return root;
        }
        else if (left!=nullptr&&right==nullptr) {
            return left;
        }
        else {
            return right;
        }
    }
};