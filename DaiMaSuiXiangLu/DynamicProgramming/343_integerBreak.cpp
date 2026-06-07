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
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i=3;i<=n;i++) {
            for (int j=1;j<=i/2;j++) {
                dp[i] = max(dp[i],max(j*(i-j),j*dp[i-j]));
            }
        }

        return dp[n];
    }
};