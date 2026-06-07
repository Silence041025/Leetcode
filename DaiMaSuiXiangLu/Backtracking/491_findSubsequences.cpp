#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "unordered_set"
using namespace std;

class Solution {
public:
    vector<vector<int>> results;
    vector<int> collects;
    void backtracking(vector<vector<int>>& results,vector<int>& collect,
        vector<int> nums,int start_index) {
        if (collect.size()>=2) {
            results.push_back(collect);
        }
        unordered_set<int> used;
        for (int i=start_index;i<nums.size();i++) {
            if (used.count(nums[i])>0||
                (!collect.empty()&&nums[i]<collect.back())) {
                continue;
            }
            collect.push_back(nums[i]);
            used.insert(nums[i]);
            backtracking(results,collect,nums,i+1);
            //uset是局部变量，只存在于同一横层，不要erase,erase了就多余而且错误了，
            //每往下一层，uset都会生成一个新的对应这一层
            collect.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {

        backtracking(results,collects,nums,0);
        return results;
    }
};
int main() {
    
}