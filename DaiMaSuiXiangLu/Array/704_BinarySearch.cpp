#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left<=right) {
            int mid = left + (right - left) / 2;
            if (nums[mid]==target) {
                return mid;
            }
            if (nums[mid]>target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums;
    int x;
    int target;

    while (true) {
        cin>>x;
        nums.push_back(x);
        if (cin.get()=='\n') {
            break;
        }
    }

    cin>>target;

    Solution solution;
    cout<<solution.search(nums,target)<<endl;

    return 0;
}