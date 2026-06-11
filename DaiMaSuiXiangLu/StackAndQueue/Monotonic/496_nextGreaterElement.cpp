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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(),-1);
        stack<int> index_stack;
        unordered_map<int,int> v2i;
        for (int i=0;i<nums1.size();i++) {
            v2i.insert({nums1[i],i});
        }

        for (int i=0;i<nums2.size();i++) {
            while (!index_stack.empty()&&nums2[i]>nums2[index_stack.top()]) {
                if (v2i.count(nums2[index_stack.top()])) {
                    result[v2i[nums2[index_stack.top()]]] = nums2[i];
                }
                index_stack.pop();
            }
            index_stack.push(i);
        }

        return result;
    }
};