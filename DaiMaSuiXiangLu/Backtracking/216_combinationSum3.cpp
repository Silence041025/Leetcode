#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> collect;
    void backtracking(vector<vector<int>>& result,vector<int>& collect,int n,int k,int sum,int start_index) {
        if (sum>n||collect.size()>k) {
            return;
        }
        if (sum==n&&collect.size()==k) {
            result.push_back(collect);
        }

        for (int i=start_index;i<=9;i++) {
            if (k-collect.size()>9-i+1) {
                break;
            }
            collect.push_back(i);
            sum += i;
            backtracking(result,collect,n,k,sum,i+1);
            sum -= i;
            collect.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(result,collect,n,k,0,1);
        return result;
    }
};

int main() {

}