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
        if (prices.size()==1) {
            return 0;
        }
        //持有（当购买时，必须从前天状态推来）
        //不持有
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[1][0] = max(dp[0][0],-prices[1]);
        dp[1][1] = max(dp[0][1],dp[0][0] + prices[1]);
        for (int i=2;i<prices.size();i++) {
            dp[i][0] = max(dp[i-1][0],dp[i-2][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);
        }

        return dp[prices.size()-1][1];
    }
};