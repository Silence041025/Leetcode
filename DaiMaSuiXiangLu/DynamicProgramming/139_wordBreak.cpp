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
    bool wordBreak(string s, vector<string>& wordDict) {
        //爬楼梯模型
        //dp[i]表示0..i-1能否拆分
        //注意dp和s错开了一个下标
        vector<bool> dp(s.size()+1,false);
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for (int i=1;i<dp.size();i++) {
            for (int j=0;j<i;j++) {
                if (dp[j]&&uset.find(s.substr(j,i-j))!=uset.end()) {
                    dp[i] = true;
                }
            }
        }

        return dp[s.size()];
    }
};