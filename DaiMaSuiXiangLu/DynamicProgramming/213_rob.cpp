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
    int robI(vector<int>& nums) {
        if (nums.size()==1) {
            return nums[0];
        }
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for (int i=2;i<dp.size();i++) {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }

        return dp.back();
    }

    int rob(vector<int>& nums) {
        if (nums.size()==1) {
            return nums[0];
        }
        if (nums.size()==2) {
            return max(nums[0],nums[1]);
        }
        vector<int> nums_without0(nums.begin()+1,nums.end());
        vector<int> nums_withoutBack(nums.begin(),nums.end()-1);
        int result1 = robI(nums_without0);
        int result2 = robI(nums_withoutBack);

        return max(result1,result2);
    }
};