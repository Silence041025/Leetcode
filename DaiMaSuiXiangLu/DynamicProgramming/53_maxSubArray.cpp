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
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),INT_MIN);
        dp[0] = nums[0];
        for (int i=1;i<nums.size();i++) {
            dp[i] = max(nums[i],dp[i-1]+nums[i]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};