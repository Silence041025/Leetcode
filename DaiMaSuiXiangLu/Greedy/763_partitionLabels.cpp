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
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> right_bound(27,0);
        vector<int> result;
        for (int i=0;i<s.size();i++) {
            right_bound[s[i]-'a'] = i;
        }

        int left = 0;
        int right = 0;
        for (int i=0;i<s.size();i++) {
            right = max(right,right_bound[s[i]-'a']);
            if (i==right) {
                result.push_back(right-left+1);
                left = i + 1;
            }
        }

        return result;
    }
};