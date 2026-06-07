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
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size()<2) {
            return nums.size();
        }
        int result = 1;
        int diff = INT_MAX;
        for (int i=1;i<nums.size();i++) {
            if (nums[i]==nums[i-1]) {
                continue;
            }
            else if (nums[i]>nums[i-1]) {
                if (diff!=INT_MAX&&diff>0) {
                    continue;
                }
                else {
                    result++;
                    diff = nums[i] - nums[i-1];
                }
            }
            else {
                if (diff!=INT_MAX&&diff<0) {
                    continue;
                }
                else {
                    result++;
                    diff = nums[i] - nums[i-1];
                }
            }
        }

        return result;
    }
};