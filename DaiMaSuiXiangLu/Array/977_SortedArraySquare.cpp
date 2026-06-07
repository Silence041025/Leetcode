#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "cmath"
using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        for (int i=result.size()-1;i>=0;i--) {
           if (nums[right]*nums[right]>=nums[left]*nums[left]) {
               result[i] = nums[right] * nums[right];
               right--;
           }
            else {
                result[i] = nums[left] * nums[left];
                left++;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums;
    int x;
    while (true) {
        cin>>x;
        nums.push_back(x);
        if (cin.get()=='\n') {
            break;
        }
    }

    Solution solution;
    vector<int> result = solution.sortedSquares(nums);
    for (int num : result) {
        cout<<num<<" ";
    }

}