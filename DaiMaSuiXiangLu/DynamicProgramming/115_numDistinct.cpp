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
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long>> dp(t.size(),vector<unsigned long long>(s.size(),0));
        if (s[0]==t[0]) {
            dp[0][0] = 1;
        }
        else {
            dp[0][0] = 0;
        }
        for (int j=1;j<s.size();j++) {
            if (s[j]==t[0]) {
                dp[0][j] = dp[0][j-1] + 1;
            }
            else {
                dp[0][j] = dp[0][j-1];
            }
        }

        for (int i=1;i<t.size();i++) {
            for (int j=i;j<s.size();j++) {
                if (s[j]==t[i]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }
                else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        return dp[t.size()-1][s.size()-1];
    }
};