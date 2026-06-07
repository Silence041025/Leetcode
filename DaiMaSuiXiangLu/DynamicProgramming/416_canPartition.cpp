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
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num:nums) {
            sum += num;
        }
        if (sum%2==1) {
            return false;
        }
        int target = sum/2;
        vector<int> dp(target+1,0);
        for (int i=0;i<nums.size();i++) {
            for (int j=target;j>=nums[i];j--) {
                dp[j] = max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }

        if (dp[target]==target) {
            return true;
        }
        return false;
    }
};