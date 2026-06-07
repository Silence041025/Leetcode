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

//0无覆盖  1有摄像头  2有覆盖（nullptr也设为2）
class Solution {
public:

    int traversal(TreeNode* root,int& result) {
        if (root==nullptr) {
            return 2;
        }
        int left = traversal(root->left,result);
        int right = traversal(root->right,result);

        if (left==2&&right==2) {
            return 0;
        }
        if (left==0||right==0) {
            result++;
            return 1;
        }
        if (left==1||right==1) {
            return 2;
        }

        return -1;
    }
    int minCameraCover(TreeNode* root) {
        int result = 0;
        if (traversal(root,result)==0) {
            result++;
        }

        return result;
    }
};