#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    vector<vector<int>> results;
    vector<int> collect;
    void backtracking(vector<int>& candidates,int target,int index_start,int sum) {
        if (sum>target) {
            return;
        }
        if (sum==target) {
            results.push_back(collect);
            return;
        }

        for (int i=index_start;i<candidates.size();i++) {
            collect.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates,target,i,sum);
            sum -= candidates[i];
            collect.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0,0);
        return results;
    }
};
int main() {
    
}