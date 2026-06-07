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
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),0));
        int result = 0;
        for (int i=0;i<s.size();i++) {
            if (s[i]==t[0]) {
                while (i<s.size()) {
                    dp[i++][0] = 1;
                    result = 1;
                }
            }
        }

        for (int j=0;j<t.size();j++) {
            if (s[0]==t[j]) {
                while (j<t.size()) {
                    dp[0][j++] = 1;
                    result = 1;
                }
            }
        }

        for (int i=1;i<s.size();i++) {
            for (int j=1;j<t.size();j++) {
                if (s[i]==t[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                result = max(result,dp[i][j]);
            }
        }

        if (result==s.size()) {
            return true;
        }

        return false;
    }
};