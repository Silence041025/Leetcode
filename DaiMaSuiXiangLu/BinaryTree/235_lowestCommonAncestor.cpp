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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr) {
            return nullptr;
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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr) {
            return nullptr;
        }
        if (root->val > p->val&&root->val > q->val) {
            return lowestCommonAncestor(root->left,p,q);
        }
        else if (root->val < p->val&&root->val < q->val) {
            return lowestCommonAncestor(root->right,p,q);
        }
        else {
            return root;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr) {
            return nullptr;
        }
        while (root) {
            if (root->val > p->val&& root->val > q->val) {
                root = root->left;
            }
            else if (root->val < p->val&&root->val < q->val) {
                root = root->right;
            }
            else {
                return root;
            }
        }

        return root;
    }
};