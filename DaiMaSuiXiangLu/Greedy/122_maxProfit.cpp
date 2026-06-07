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
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i=1;i<prices.size();i++) {
            if (prices[i]-prices[i-1]>0) {
                result += prices[i] - prices[i-1];
            }
        }

        return result;
    }
};