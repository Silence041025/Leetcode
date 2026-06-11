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
    int largestRectangleArea(vector<int>& heights) {
        //i right
        //第一个top mid
        //pop后的top left
        int result = 0;
        stack<int> index_stack;
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        for (int i=0;i<heights.size();i++) {
            while (!index_stack.empty()&&heights[i]<heights[index_stack.top()]) {
                int right = heights[i];
                int mid = heights[index_stack.top()];
                index_stack.pop();
                if (!index_stack.empty()) {
                    int left = index_stack.top();
                    int h = mid;
                    int w = i - index_stack.top() - 1;
                    result = max(result,w*h);
                }
            }
            index_stack.push(i);
        }

        return result;
    }
};