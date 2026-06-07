#include "vector"
#include "stack"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> my_stack;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='(') {
                my_stack.push(')');
            }
            else if (s[i]=='[') {
                my_stack.push(']');
            }
            else if (s[i]=='{') {
                my_stack.push('}');
            }
            else if (s[i]==')') {
                if (my_stack.empty()||my_stack.top()!=')') {
                    return false;
                }
                my_stack.pop();
            }
            else if (s[i]==']') {
                if (my_stack.empty()||my_stack.top()!=']') {
                    return false;
                }
                my_stack.pop();
            }
            else if (s[i]=='}') {
                if (my_stack.empty()||my_stack.top()!='}') {
                    return false;
                }
                my_stack.pop();
            }
        }
        if (!my_stack.empty()) {
            return false;
        }
        return true;
    }
};
int main() {
    
}