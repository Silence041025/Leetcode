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
      bool isPalindrome(int x) {
          string str_x = to_string(x);
          string rev_x = str_x;
          reverse(rev_x.begin(), rev_x.end());

          return str_x==rev_x;
      }
};

//测试用的，随便选了个题