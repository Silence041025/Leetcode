#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "stack"
using namespace std;

class MyQueue {
public:
    stack<int> stack_in;
    stack<int> stack_out;
    MyQueue() {

    }

    void push(int x) {
        stack_in.push(x);
    }

    int pop() {
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        int result = stack_out.top();
        stack_out.pop();
        return result;
    }

    int peek() {
        int result = this->pop();
        stack_out.push(result);
        return result;
    }

    bool empty() {
        return stack_in.empty()&&stack_out.empty();
    }
};


 // MyQueue* obj = new MyQueue();
 // obj->push(x);
 // int param_2 = obj->pop();
 // int param_3 = obj->peek();
 // bool param_4 = obj->empty();
int main() {
    
}