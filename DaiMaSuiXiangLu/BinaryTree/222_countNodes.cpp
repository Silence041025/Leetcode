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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }

        TreeNode* l = root->left;
        TreeNode* r = root->right;
        int left_depth = 0;
        int right_depth = 0;
        while (l!=nullptr) {
            l = l->left;
            left_depth++;
        }
        while (r!=nullptr) {
            r = r->right;
            right_depth++;
        }

        if (left_depth==right_depth) {
            //2^(depth+1) - 1
            return (2<<left_depth)-1;
        }

        int left_count = countNodes(root->left);
        int right_count = countNodes(root->right);
        int result = left_count + right_count + 1;

        return result;
    }
};