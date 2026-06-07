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

    void get_squares(vector<unsigned long long>& squares) {
        for (int i=1;i<=100;i++) {
            squares.push_back(i*i);
        }
    }
    int numSquares(int n) {
        vector<unsigned long long> squares;
        get_squares(squares);
        vector<unsigned long long> dp(n+1,INT_MAX);
        dp[0] = 0;
        for (int i=0;i<squares.size();i++) {
            for (int j=squares[i];j<=n;j++) {
                dp[j] = min(dp[j],dp[j-squares[i]]+1);
            }
        }

        return dp[n];
    }
};