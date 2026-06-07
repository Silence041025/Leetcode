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
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;
        for (int row=1;row<dp.size();row++) {
            dp[row][0] = 1;
        }
        for (int col=1;col<dp[0].size();col++) {
            dp[0][col] = 1;
        }

        for (int row=1;row<dp.size();row++) {
            for (int col=1;col<dp[row].size();col++) {
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }

        return dp[dp.size()-1][dp[0].size()-1];
    }
};