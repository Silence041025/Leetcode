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
      int longestPalindromeSubseq(string s) {
          vector<vector<int>> longestSubSequence_ij(s.size(),vector<int>(s.size(),0));
          for(int i=0;i<s.size();i++){
              longestSubSequence_ij[i][i] = 1;
          }
          for(int i=s.size()-1;i>=0;i--){
              for(int j=i+1;j<s.size();j++){
                  if(s[i]==s[j]){
                      longestSubSequence_ij[i][j] = longestSubSequence_ij[i+1][j-1] + 2;
                  }
                  else{
                      longestSubSequence_ij[i][j] =
                      max(longestSubSequence_ij[i+1][j],longestSubSequence_ij[i][j-1]);
                  }
              }
          }

          return longestSubSequence_ij[0][s.size()-1];
      }
  };