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
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1,0);
        dp[0] = 1;
        for (int j=0;j<=target;j++) {
            for (int i=0;i<nums.size();i++) {
                if (j>=nums[i]) {
                    dp[j] += dp[j-nums[i]];
                }
            }
        }

        return dp[target];
    }
};