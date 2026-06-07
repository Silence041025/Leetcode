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
      int countSubstrings(string s) {
          long long result = 0;
          vector<vector<bool>> isPalin_ij(s.size(),vector<bool>(s.size(),false));
          for(int i=s.size()-1;i>=0;i--){
              for(int j=i;j<s.size();j++){
                  if(s[i]==s[j]){
                      if(j-i<=1){
                          isPalin_ij[i][j] = true;
                          result++;
                      }
                      else if(j-i>1&&isPalin_ij[i+1][j-1]){
                          isPalin_ij[i][j] = true;
                          result++;
                      }
                  }
              }
          }

          return result;
      }
  };