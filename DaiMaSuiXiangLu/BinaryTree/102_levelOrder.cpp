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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if (root!=nullptr) {
            que.push(root);
        }
        while (!que.empty()) {
            vector<int> collector;
            int level_node_count = que.size();
            while (level_node_count--) {
                TreeNode* temp = que.front();
                que.pop();
                collector.push_back(temp->val);
                if (temp->left!=nullptr) {
                    que.push(temp->left);
                }
                if (temp->right!=nullptr) {
                    que.push(temp->right);
                }
            }
            result.push_back(collector);
        }

        return result;
    }
};
int main() {
    
}