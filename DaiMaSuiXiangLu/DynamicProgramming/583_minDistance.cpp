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
    int minDistance(string word1, string word2) {
        int result = 0;
        vector<vector<int>> dp(word2.size(),vector<int>(word1.size(),0));
        for (int j=0;j<word1.size();j++) {
            if (word1[j]==word2[0]) {
                while (j<word1.size()) {
                    dp[0][j++] = 1;
                    result = 1;
                }
            }
        }

        for (int i=0;i<word2.size();i++) {
            if (word2[i]==word1[0]) {
                while (i<word2.size()) {
                    dp[i++][0] = 1;
                    result = 1;
                }
            }
        }

        for (int i=1;i<word2.size();i++) {
            for (int j=1;j<word1.size();j++) {
                if (word1[j]==word2[i]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                result = max(result,dp[i][j]);
            }
        }

        return (word1.size()-result) + (word2.size()-result);
    }
};