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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root==nullptr) {
            return nullptr;
        }
        if (root->val==val) {
            return root;
        }
        if (root->val>val) {
            root = searchBST(root->left,val);
        }
        else if (root->val<val) {
            root = searchBST(root->right,val);
        }

        return root;
    }
};
