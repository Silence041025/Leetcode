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
    bool canJump(vector<int>& nums) {
        int right_bound = 0;
        for (int i=0;i<nums.size()&&i<=right_bound;i++) {
            right_bound = max(right_bound,nums[i]+i);
        }

        return right_bound >= nums.size()-1;
    }
};