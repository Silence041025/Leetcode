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
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount+1,0);
        dp[0] = 1;
        for (int i=0;i<coins.size();i++) {
            for (int j=coins[i];j<=amount;j++) {
                dp[j] += dp[j-coins[i]];
            }
        }

        return dp[amount];
    }
};