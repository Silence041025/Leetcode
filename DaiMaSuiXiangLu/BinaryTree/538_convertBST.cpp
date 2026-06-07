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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root==nullptr) {
            return nullptr;
        }

        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);

        return root;
    }
};