#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "queue"
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //最大深度，就是根节点高度
    int maxDepth(TreeNode* root) {
        if (root==nullptr) {
            return 0;
        }

        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        int height = max(left_height,right_height)+1;
        return height;
    }
};