#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "queue"
using namespace std;

class Solution {
public:
    void push(deque<int>& deque,int val) {
        while (!deque.empty()&&deque.back()<val) {
            deque.pop_back();
        }
        deque.push_back(val);
    }
    void pop(deque<int>& deque,int val) {
        if (deque.front()==val) {
            deque.pop_front();
        }
    }
    int get_max_value(deque<int>& deque) {
        return deque.front();
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deque;
        vector<int> result;
        for (int i=0;i<k;i++) {
            push(deque,nums[i]);
        }
        result.push_back(get_max_value(deque));
        for (int i=1;i<nums.size()-k+1;i++) {
            pop(deque,nums[i-1]);
            push(deque,nums[i+k-1]);
            result.push_back(get_max_value(deque));
        }
        return result;
    }
};
int main() {
    
}