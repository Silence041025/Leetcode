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
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(),-1);
        stack<int> index_stack;
        for (int i=0;i<nums.size()*2;i++) {
            while (!index_stack.empty()&&nums[i%nums.size()]>nums[index_stack.top()]) {
                result[index_stack.top()] = nums[i%nums.size()];
                index_stack.pop();
            }
            index_stack.push(i%nums.size());
        }

        return result;
    }
};