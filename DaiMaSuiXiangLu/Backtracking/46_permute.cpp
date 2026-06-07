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
        vector<bool> used,vector<int> nums) {
        if (collect.size()==nums.size()) {
            results.push_back(collect);
            return;
        }

        for (int i=0;i<nums.size();i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            collect.push_back(nums[i]);
            backtracking(results,collect,used,nums);
            collect.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        backtracking(results,collect,used,nums);
        return results;
    }
};
int main() {
    
}