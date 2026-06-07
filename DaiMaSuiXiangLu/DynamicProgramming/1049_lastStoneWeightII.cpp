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
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int stone:stones) {
            sum += stone;
        }
        int target = sum/2;

        vector<int> dp(target+1,0);
        for (int i=0;i<stones.size();i++) {
            for (int j=target;j>=stones[i];j--) {
                dp[j] = max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }

        return sum - 2*dp[target];
    }
};