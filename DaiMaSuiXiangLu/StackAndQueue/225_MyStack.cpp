#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "queue"
using namespace std;

class MyStack {
public:
    queue<int> queue;
    MyStack() {

    }

    void push(int x) {
        queue.push(x);
    }

    int pop() {
        int queue_size = queue.size();
        queue_size--;
        while (queue_size--) {
            int temp = queue.front();
            queue.push(temp);
            queue.pop();
        }
        int result = queue.front();
        queue.pop();
        return result;
    }

    int top() {
        return queue.back();
    }

    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main() {
    
}