#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "stack"
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        stack<int> index_stack;
        for (int i=0;i<temperatures.size();i++) {
            while (!index_stack.empty()&&temperatures[i]>temperatures[index_stack.top()]) {
                result[index_stack.top()] = i - index_stack.top();
                index_stack.pop();
            }
            index_stack.push(i);
        }
        return result;
    }
};
int main() {
    
}