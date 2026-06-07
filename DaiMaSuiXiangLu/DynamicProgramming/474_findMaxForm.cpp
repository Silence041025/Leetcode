#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "numeric"
#include "deque"
#include "queue"
#include "stack"
#include "unordered_set"
#include "set"
#include "unordered_map"
#include "map"
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for (string str:strs) {
            int weight_zero = count(str.begin(), str.end(),'0');
            int weight_one = str.size()-weight_zero;
            for (int i=m;i>=weight_zero;i--) {
                for (int j=n;j>=weight_one;j--) {
                    dp[i][j] = max(dp[i][j],dp[i-weight_zero][j-weight_one]+1);
                }
            }
        }

        return dp[m][n];
    }
};