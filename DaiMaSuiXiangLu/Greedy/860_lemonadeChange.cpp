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
    bool lemonadeChange(vector<int>& bills) {
        vector<int> moneys(3,0);
        for (int i=0;i<bills.size();i++) {
            if (bills[i]==5) {
                moneys[0]++;
            }else if (bills[i]==10){
                if (moneys[0]>0) {
                    moneys[0]--;
                    moneys[1]++;
                }else {
                    return false;
                }
            }else {
                if (moneys[1]>0&&moneys[0]>0) {
                    moneys[1]--;
                    moneys[0]--;
                }else if (moneys[0]>2) {
                    moneys[0] -= 3;
                }else {
                    return false;
                }
                moneys[2]++;
            }
        }

        return true;
    }
};