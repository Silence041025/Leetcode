#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;



class Solution {
public:
    vector<int> collect;
    vector<vector<int>> result;
    void backtracking(vector<vector<int>>& result,vector<int>& collect,int n,int k,int start_index) {
        if (collect.size()==k) {
            result.push_back(collect);
            return;
        }

        for (int i=start_index;i<=n;i++) {
            if (collect.size() + (n - i + 1) < k) {
                break;
            }
            collect.push_back(i);
            backtracking(result,collect,n,k,i+1);
            collect.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(result,collect,n,k,1);
        return result;
    }
};

int main() {

}