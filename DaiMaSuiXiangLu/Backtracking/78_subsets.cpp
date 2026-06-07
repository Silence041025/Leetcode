#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    vector<vector<int>> results;
    vector<int> collect;

    void backtracking(vector<vector<int>>& results,vector<int>& collect,
        vector<int> nums,int start_index) {
        results.push_back(collect);
        for (int i=start_index;i<nums.size();i++) {
            collect.push_back(nums[i]);
            backtracking(results,collect,nums,i+1);
            collect.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(results,collect,nums,0);
        return results;
    }
};
int main() {

}