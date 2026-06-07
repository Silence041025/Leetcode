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
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int sum = 0;
        for (int i=0;i<nums.size()&&nums[i]<0&&k>0;i++) {
            nums[i] = -nums[i];
            k--;
        }

        //让0到最前面
        sort(nums.begin(), nums.end());
        if (k>0&&k%2!=0) {
            nums[0] = -nums[0];
        }

        for (int i=0;i<nums.size();i++) {
            sum += nums[i];
        }

        return sum;
    }
};