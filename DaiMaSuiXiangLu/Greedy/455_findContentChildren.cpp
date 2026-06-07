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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0;
        int s_index = s.size()-1;
        for (int i=g.size()-1;i>=0;i--) {
            if (s_index>=0&&s[s_index]>=g[i]) {
                result++;
                s_index--;
            }
        }

        return result;
    }
};