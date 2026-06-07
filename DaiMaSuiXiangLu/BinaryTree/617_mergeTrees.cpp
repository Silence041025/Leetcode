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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1==nullptr&&root2==nullptr) {
            return nullptr;
        }
        TreeNode* root = new TreeNode();
        if (root1!=nullptr&&root2!=nullptr) {
            root->val = root1->val + root2->val;
            root->left = mergeTrees(root1->left,root2->left);
            root->right = mergeTrees(root1->right,root2->right);
        }
        else if (root1==nullptr&&root2!=nullptr) {
            root->val = root2->val;
            root->left = mergeTrees(nullptr,root2->left);
            root->right = mergeTrees(nullptr,root2->right);
        }
        else if (root1!=nullptr&&root2==nullptr) {
            root->val = root1->val;
            root->left = mergeTrees(root1->left,nullptr);
            root->right = mergeTrees(root1->right,nullptr);
        }

        return root;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1==nullptr) {
            return root2;
        }
        if (root2==nullptr) {
            return root1;
        }

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left,root2->left);
        root1->right = mergeTrees(root1->right,root2->right);

        return root1;
    }
};