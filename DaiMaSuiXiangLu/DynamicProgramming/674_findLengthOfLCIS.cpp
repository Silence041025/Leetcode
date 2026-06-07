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
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for(int i=1;i<dp.size();i++) {
            if (nums[i]>nums[i-1]) {
                dp[i] = dp[i-1] + 1;
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};