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
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i=0;i<nums.size();i++) {
            sum += nums[i];
        }
        int s = (sum + target)/2;
        if (abs(target)>sum) {
            return 0;
        }
        if ((sum+target)%2!=0) {
            return 0;
        }
        vector<int> dp(s+1,0);
        dp[0] = 1;
        for (int i=0;i<nums.size();i++) {
            for (int j=s;j>=nums[i];j--) {
                dp[j] += dp[j-nums[i]];
            }
        }

        return dp[s];
    }
};