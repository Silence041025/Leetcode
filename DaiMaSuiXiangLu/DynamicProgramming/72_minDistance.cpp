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
#include <vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word2.size(),vector<int>(word1.size(),0));
        if(word1.size()==0){
            return word2.size();
        }
        if(word2.size()==0){
            return word1.size();
        }
        dp[0][0] = word1[0] == word2[0] ? 0 : 1;
        for(int j=1;j<word1.size();j++){
            if(word1[j]==word2[0]){
                dp[0][j] = j;
            }
            else{
                dp[0][j] = dp[0][j-1] + 1;
            }
        }

        for(int i=1;i<word2.size();i++){
            if(word1[0]==word2[i]){
                dp[i][0] = i;
            }
            else{
                dp[i][0] = dp[i-1][0] + 1;
            }
        }

        for(int i=1;i<word2.size();i++){
            for(int j=1;j<word1.size();j++){
                if(word1[j]==word2[i]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                }
            }
        }

        return dp[word2.size()-1][word1.size()-1];
    }
};

