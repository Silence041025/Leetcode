#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    vector<vector<int>> results;
    vector<int> collect;
    bool is_valid(vector<int>& collect,int row,int col) {
        for (int i=0;i<row;i++) {
            if (collect[i]==col) {
                return false;
            }
            if (abs(collect[i]-col)==abs(i-row)) {
                return false;
            }
        }
        return true;
    }

    void backtracking(vector<vector<int>>& results,
        vector<int>& collect,int n,int row) {
        if (row==n) {
            results.push_back(collect);
        }

        for (int col=0;col<n;col++) {
            if (!is_valid(collect,row,col)) {
                continue;
            }
            collect[row] = col;
            backtracking(results,collect,n,row+1);
            collect[row] = 0;
        }
    }

    vector<vector<string>> make_pattern(vector<vector<int>>& results,int n) {
        vector<vector<string>> pattern_results;
        for (int i=0;i<results.size();i++) {
            vector<string> pattern(n,string(n,'.'));
            for (int row = 0;row < n;row++) {
                int col = results[i][row];
                pattern[row][col] = 'Q';
            }
            pattern_results.push_back(pattern);
        }
        return pattern_results;
    }
    vector<vector<string>> solveNQueens(int n) {
        collect.resize(n);
        backtracking(results,collect,n,0);
        return make_pattern(results,n);
    }
};
int main() {
    
}