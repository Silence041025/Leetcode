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
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text2.size(),vector<int>(text1.size(),0));
        int result = 0;
        for (int j=0;j<text1.size();j++) {
            if (text1[j]==text2[0]) {
                while (j<text1.size()) {
                    dp[0][j++] = 1;
                    result = 1;
                }
            }
        }

        for (int i=0;i<text2.size();i++) {
            if (text1[0]==text2[i]) {
                while (i<text2.size()) {
                    dp[i++][0] = 1;
                    result = 1;
                }
            }
        }

        for (int i=1;i<text2.size();i++) {
            for (int j=1;j<text1.size();j++) {
                if (text1[j]==text2[i]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                result = max(result,dp[i][j]);
            }
        }

        return result;
    }
};