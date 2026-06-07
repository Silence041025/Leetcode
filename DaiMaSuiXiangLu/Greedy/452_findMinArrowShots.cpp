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
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int arrows = 1;
        sort(points.begin(), points.end(),cmp);
        int least_right_bound = points[0][1];
        for (int i=0;i<points.size();i++) {
            if (points[i][0] > least_right_bound) {
                arrows++;
                least_right_bound = points[i][1];
            }else {
                least_right_bound = min(least_right_bound,points[i][1]);
            }
        }

        return arrows;
    }
};