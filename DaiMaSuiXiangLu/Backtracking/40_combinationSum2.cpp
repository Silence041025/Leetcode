#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> collect;
    void backtracking(vector<vector<int>>& result,vector<int>& collect,vector<int>& candidate,int target,int sum,int start_index) {
        if (sum>target) {
            return;
        }
        if (sum==target) {
            result.push_back(collect);
            return;
        }

        for (int i=start_index;i<candidate.size();i++) {
            //必须是i>start_index,如果写i>0,在深层（比如第二层）
            //，第一个访问到的元素i=1
            //，直接就舍弃了（[0]==[1]），导致底层只要有重的元素就一个不留
            //i>start_index保证第一个永远不舍弃
            if (i>start_index&&candidate[i]==candidate[i-1]) {
                continue;
            }
            collect.push_back(candidate[i]);
            sum += candidate[i];
            backtracking(result,collect,candidate,target,sum,i+1);
            sum -= candidate[i];
            collect.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(result,collect,candidates,target,0,0);
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> results;
    vector<int> collect;

    void backtracking(vector<vector<int>>& results,vector<int>& collect,
        vector<bool>& used,vector<int>& candidates,int target,int sum,int start_index) {
        if (sum>target) {
            return;
        }
        if (sum==target) {
            results.push_back(collect);
            return;
        }

        for (int i=start_index;i<candidates.size();i++) {
            //!used[i-1]说明是新的树枝（横向）,used[i-1]说明是同一条树枝往下，
            //这种情况允许重复取,used[i]因为还没处理呢，到for()里永远是false
            if (i>0&&candidates[i]==candidates[i-1]&&!used[i-1]) {
                continue;
            }
            collect.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backtracking(results,collect,used,candidates,target,sum,i+1);
            used[i] = false;
            sum -= candidates[i];
            collect.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(),false);
        sort(candidates.begin(), candidates.end());
        backtracking(results,collect,used,candidates,target,0,0);
        return results;
    }
};
int main() {
    
}