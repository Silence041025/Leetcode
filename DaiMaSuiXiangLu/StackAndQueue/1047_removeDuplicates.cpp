#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "stack"
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk1;
        stack<char> stk2;
        for (int i=0;i<s.size();i++) {
            if (stk1.empty()||s[i]!=stk1.top()) {
                stk1.push(s[i]);
            }
            else {
                stk1.pop();
            }
        }
        while (!stk1.empty()) {
            char temp = stk1.top();
            stk2.push(temp);
            stk1.pop();
        }
        string result = "";
        while (!stk2.empty()) {
            char temp = stk2.top();
            result += temp;
            stk2.pop();
        }
        return result;
    }
};

int main() {
    
}