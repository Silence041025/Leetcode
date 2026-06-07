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
    int coinChange(vector<int>& coins, int amount) {
        vector<unsigned long long> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for (int i=0;i<coins.size();i++) {
            for (int j=coins[i];j<=amount;j++) {
                dp[j] = min(dp[j],dp[j-coins[i]]+1);
            }
        }

        if (dp[amount]==INT_MAX) {
            return -1;
        }
        return dp[amount];
    }
};