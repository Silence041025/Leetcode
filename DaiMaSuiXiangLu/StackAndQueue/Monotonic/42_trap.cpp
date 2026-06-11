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
    int trap(vector<int>& height) {
        //遍历i : right
        //第一个栈口： mid
        //弹出第一个，之后的栈口：left
        int result = 0;
        stack<int> index_value;
        for (int i=0;i<height.size();i++) {
            while (!index_value.empty()&&height[i]>height[index_value.top()]) {
                int right = height[i];
                int mid = height[index_value.top()];
                index_value.pop();
                if (!index_value.empty()) {
                    int left = height[index_value.top()];
                    int h = min(left,right) - mid;
                    int w = i - index_value.top() - 1;
                    result += h*w;
                }
            }
            index_value.push(i);
        }

        return result;
    }
};