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
    static bool cmp(vector<int>& a,vector<int>& b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }else {
            return a[1] < b[1];
        }
    }

    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),cmp);
        int result = 0;
        vector<bool> joined_days(100005,false);

        for (int i=0;i<events.size();i++) {
            for (int day=events[i][0];day<=events[i][1];day++) {
                if (!joined_days[day]) {
                    result++;
                    joined_days[day] = true;
                    break;
                }
            }
        }

        return result;
    }
};