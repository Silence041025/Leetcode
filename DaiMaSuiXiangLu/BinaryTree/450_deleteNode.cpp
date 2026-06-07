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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==nullptr) {
            return nullptr;
        }
        if (root->val == key) {
            if (root->left==nullptr&&root->right==nullptr) {
                return nullptr;
            }
            else if (root->left==nullptr&&root->right!=nullptr) {
                return root->right;
            }
            else if (root->left!=nullptr&&root->right==nullptr) {
                return root->left;
            }
            else {
                TreeNode* successor = root->right;
                while (successor->left) {
                    successor = successor->left;
                }

                successor->left = root->left;
                return root->right;
            }
        }

        if (root->val > key) {
            root->left = deleteNode(root->left,key);
        }
        if (root->val < key) {
            root->right = deleteNode(root->right,key);
        }

        return root;
    }
};