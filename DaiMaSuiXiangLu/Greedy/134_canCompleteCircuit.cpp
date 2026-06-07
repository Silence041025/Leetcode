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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size()==1&&gas[0]>=cost[0]) {
            return 0;
        }else if (gas.size()==1&&gas[0]<cost[0]) {
            return -1;
        }
        vector<int> diff(gas.size());
        vector<int> start_index;
        for (int i=0;i<gas.size();i++) {
            diff[i] = gas[i] - cost[i];
        }
        if (diff[0]>0&&diff[diff.size()-1]<0) {
            start_index.push_back(0);
        }
        for (int i=1;i<diff.size();i++) {
            if (diff[i-1]<0&&diff[i]>0) {
                start_index.push_back(i);
            }
        }
        int result = -1;

        for (int s=0;s<start_index.size();s++) {
            int fuel = gas[start_index[s]];
            bool can_complete = true;
            for (int i=start_index[s],t=0;t<diff.size()+1;i=(i+1)%diff.size(),t++) {
                if (fuel - cost[i]<0) {
                    can_complete = false;
                    break;
                } else {
                    fuel -= cost[i];
                    fuel += gas[(i+1)%diff.size()];
                }
            }
            if (can_complete) {
                result = start_index[s];
            }
        }

        return result;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i=0;i<cost.size();i++) {
            int rest = gas[i] - cost[i];
            int index = (i+1)%cost.size();
            while (rest>0&&index!=i) {
                rest += gas[index] - cost[index];
                index = (index+1)%cost.size();
            }
            if (rest>=0&&index==i) {
                return i;
            }
        }

        return -1;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int result = 0;
        for (int i=0;i<cost.size();i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum<0) {
                result = i+1;
                curSum = 0;
            }
        }

        if (totalSum<0) {
            return -1;
        }else {
            return result;
        }
    }
};