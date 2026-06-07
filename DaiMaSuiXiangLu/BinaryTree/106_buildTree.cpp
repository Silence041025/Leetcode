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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size()==0) {
            return nullptr;
        }

        int root_val = postorder.back();
        TreeNode* root = new TreeNode(root_val);
        if (postorder.size()==1) {
            return root;
        }

        int root_index = 0;
        for (int i=0;i<inorder.size();i++) {
            if (inorder[i]==root_val) {
                root_index = i;
                break;
            }
        }

        vector<int> in_left(inorder.begin(),inorder.begin()+root_index);
        vector<int> post_left(postorder.begin(),postorder.begin()+root_index);
        vector<int> in_right(inorder.begin()+root_index+1,inorder.end());
        vector<int> post_right(postorder.begin()+root_index,postorder.end()-1);

        root->left = buildTree(in_left,post_left);
        root->right = buildTree(in_right,post_right);

        return root;
    }
};
