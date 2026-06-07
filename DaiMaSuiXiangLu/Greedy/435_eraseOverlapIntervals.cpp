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
    static bool cmp(vector<int> a,vector<int> b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),cmp);
        int save = 1;
        int right_bound = intervals[0][1];
        for (int i=1;i<intervals.size();i++) {
            if (intervals[i][0] >= right_bound) {
                save++;
                right_bound = intervals[i][1];
            }
        }

        return intervals.size() - save;
    }
};