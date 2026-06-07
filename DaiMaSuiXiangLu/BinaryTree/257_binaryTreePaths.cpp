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
    string make_str(vector<int>& path) {
        string result = "";
        for (int i=0;i<path.size();i++) {
            result += (to_string(path[i]));
            if (i!=path.size()-1) {
                result += "->";
            }
        }

        return result;
    }

    void dfs(vector<string>& results,vector<int>& path,TreeNode* root) {
        if (root->left==nullptr&&root->right==nullptr) {
            results.push_back(make_str(path));
            return;
        }

        for (int i=0;i<2;i++) {
            if (i==0) {
                if (root->left) {
                    path.push_back(root->left->val);
                    dfs(results,path,root->left);
                    path.pop_back();
                }
            }
            else {
                if (root->right) {
                    path.push_back(root->right->val);
                    dfs(results,path,root->right);
                    path.pop_back();
                }
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        vector<int> path;
        path.push_back(root->val);
        dfs(results,path,root);
        return results;
    }
};
