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
        vector<bool>& used,vector<int> nums) {
        if (collect.size()==nums.size()) {
            results.push_back(collect);
            return;
        }

        for (int i=0;i<nums.size();i++) {
            //横向同层去重
            if (i>0&&nums[i]==nums[i-1]&&!used[i-1]) {
                continue;
            }

            //纵向树枝去重
            if (used[i]) {
                continue;
            }

            collect.push_back(nums[i]);
            used[i]=true;
            backtracking(results,collect,used,nums);
            used[i]=false;
            collect.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        sort(nums.begin(), nums.end());
        backtracking(results,collect,used,nums);
        return results;
    }
};
int main() {
    
}