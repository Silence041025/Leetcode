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
        int result = INT_MIN;
        int sum = 0;
        for (int i=0;i<nums.size();i++) {
            sum += nums[i];
            result = max(result,sum);
            if (sum<0) {
                sum = 0;
            }
        }

        return result;
    }
};