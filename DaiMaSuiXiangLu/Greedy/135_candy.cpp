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
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(),1);
        for (int i=1;i<candy.size();i++) {
            if (ratings[i]>ratings[i-1]) {
                candy[i] = candy[i-1] + 1;
            }
        }

        int result = 0;
        for (int i=candy.size()-2;i>=0;i--) {
            if (ratings[i]>ratings[i+1]) {
                candy[i] = max(candy[i],candy[i+1] + 1);
            }
        }

        for (int i=0;i<candy.size();i++) {
            result += candy[i];
        }

        return result;
    }
};