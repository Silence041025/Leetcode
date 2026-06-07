#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0;fast<nums.size();fast++) {
            if (nums[fast]!=val) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
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

    int val;
    cin>>val;

    Solution solution;
    cout<<solution.removeElement(nums,val)<<endl;
}