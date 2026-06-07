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
        if (a[0]==b[0]) {
            return a[1] < b[1];
        }else {
            return a[0] > b[0];
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),cmp);
        vector<vector<int>> result;
        for (int i=0;i<people.size();i++) {
            int position = people[i][1];
            result.insert(result.begin()+position,people[i]);
        }

        return result;
    }
};