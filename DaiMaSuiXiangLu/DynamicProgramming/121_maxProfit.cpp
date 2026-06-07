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
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i=1;i<dp.size();i++) {
            //继续不买，卖出
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i]);
            //继续持有，第一次买
            dp[i][1] = max(dp[i-1][1],0-prices[i]);
        }

        return dp[dp.size()-1][0];
    }
};