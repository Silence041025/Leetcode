#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "queue"
#include "unordered_map"
using namespace std;

class Solution {
public:
    //顶堆顺序和线性的相反，下面cmp实际是小顶堆
    struct Cmp {
        bool operator()(pair<int,int>& A,pair<int,int>& B) {
            return A.second > B.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frequency;
        for (int i=0;i<nums.size();i++) {
            frequency[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp> pqueue;
        for (auto it=frequency.begin();it!=frequency.end();it++) {
            pqueue.push(*it);
            if (pqueue.size()>k) {
                pqueue.pop();
            }
        }
        vector<int> result(k);
        for (int i=k-1;i>=0;i--) {
            result[i] = pqueue.top().first;
            pqueue.pop();
        }
        return result;
    }
};
int main() {
    
}