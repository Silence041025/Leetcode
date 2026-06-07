#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int min_result = INT_MAX;
        for (int right = 0;right<nums.size();right++) {
            sum += nums[right];
            while (sum>=target) {
                min_result = min(min_result,right-left+1);
                sum -= nums[left];
                left++;
            }
        }
        if (min_result==INT_MAX) {
            return 0;
        }
        return min_result;
    }
};

int main() {
    vector<int> nums;
    int x;
    int target;
    cin>>target;
    while (true) {
        cin>>x;
        nums.push_back(x);
        if (cin.peek()=='\n') {
            break;
        }
    }

    Solution solution;
    cout<<solution.minSubArrayLen(target,nums);
}