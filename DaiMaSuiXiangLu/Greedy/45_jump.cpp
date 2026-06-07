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
    int jump(vector<int>& nums) {
        if (nums.size()==1) {
            return 0;
        }
        //初始化不能是0，第一次必须把边界写出来，否则死循环
        int right_bound = nums[0];
        //最后跳到终点的那下，while循环是不会包含的
        int jump_count = 1;
        int jumping_point = 0;
        while (right_bound<nums.size()-1) {
            int next_right_bound = right_bound;
            for (int next_jumping_point=jumping_point+1;next_jumping_point<nums.size()&&next_jumping_point<=right_bound;next_jumping_point++) {
                if (next_jumping_point+nums[next_jumping_point]>next_right_bound) {
                    next_right_bound = next_jumping_point+nums[next_jumping_point];
                    jumping_point = next_jumping_point;
                }
            }
            right_bound = next_right_bound;
            jump_count++;
        }

        return jump_count;
    }
};
