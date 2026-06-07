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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        dp[0][0] = 1;
        for (int row=0;row<dp.size();row++) {
            if (obstacleGrid[row][0]==1) {
                dp[row][0] = 0;
                break;
            }
            dp[row][0] = 1;
        }

        for (int col=0;col<dp[0].size();col++) {
            if (obstacleGrid[0][col]==1) {
                dp[0][col] = 0;
                break;
            }
            dp[0][col] = 1;
        }

        for (int row=1;row<dp.size();row++) {
            for(int col=1;col<dp[0].size();col++) {
                if (obstacleGrid[row][col]==1) {
                    dp[row][col] = 0;
                    continue;
                }
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }

        return dp[dp.size()-1][dp[0].size()-1];
    }
};