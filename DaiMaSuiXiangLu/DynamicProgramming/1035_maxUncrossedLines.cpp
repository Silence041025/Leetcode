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
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums2.size(),vector<int>(nums1.size(),0));
        int result = 0;
        for (int j=0;j<nums1.size();j++) {
            if (nums1[j]==nums2[0]) {
                while (j<nums1.size()) {
                    dp[0][j++] = 1;
                    result = 1;
                }
            }
        }

        for (int i=0;i<nums2.size();i++) {
            if (nums1[0]==nums2[i]) {
                while (i<nums2.size()) {
                    dp[i++][0] = 1;
                    result = 1;
                }
            }
        }

        for (int i=1;i<nums2.size();i++) {
            for (int j=1;j<nums1.size();j++) {
                if (nums1[j]==nums2[i]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                result = max(result,dp[i][j]);
            }
        }

        return result;
    }
};