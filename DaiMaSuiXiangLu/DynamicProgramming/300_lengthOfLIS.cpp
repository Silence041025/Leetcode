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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for (int i=1;i<nums.size();i++) {
            for (int j=0;j<i;j++) {
                if (nums[i]>nums[j]) {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};