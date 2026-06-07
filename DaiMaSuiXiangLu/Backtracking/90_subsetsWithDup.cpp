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
        vector<bool>& used,vector<int>& nums,int start_index) {
        results.push_back(collect);
        for (int i=start_index;i<nums.size();i++) {
            if (i>0&&nums[i]==nums[i-1]&&!used[i-1]) {
                continue;
            }
            collect.push_back(nums[i]);
            used[i] = true;
            backtracking(results,collect,used,nums,i+1);
            used[i] = false;
            collect.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        sort(nums.begin(), nums.end());
        backtracking(results,collect,used,nums,0);
        return results;
    }
};
int main() {
    
}