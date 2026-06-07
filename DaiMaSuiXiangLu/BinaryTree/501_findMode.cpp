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
    struct Cmp {
        bool operator()(pair<int,int> a,pair<int,int> b) {
            return a.second < b.second;
        }
    };

    void traverse(TreeNode* root,
        unordered_map<int,int>& frequency) {
        if (root==nullptr) {
            return;
        }

        traverse(root->left,frequency);
        frequency[root->val]++;
        traverse(root->right,frequency);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> frequency;
        traverse(root,frequency);
        priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp> pque;
        for (auto it=frequency.begin();it!=frequency.end();it++) {
            pque.push(*it);
        }

        int max_fre = pque.top().second;
        vector<int> result;
        while (!pque.empty()&&pque.top().second==max_fre) {
            result.push_back(pque.top().first);
            pque.pop();
        }

        return result;
    }
};
