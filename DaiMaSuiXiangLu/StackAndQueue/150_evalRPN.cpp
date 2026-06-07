#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "stack"
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num_stack;
        for (int i=0;i<tokens.size();i++) {
            if (tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/") {
                int temp = stoi(tokens[i]);
                num_stack.push(temp);
            }
            else {
                int num2 = num_stack.top();
                num_stack.pop();
                int num1 = num_stack.top();
                num_stack.pop();
                if (tokens[i]=="+") {
                    int num = num1 + num2;
                    num_stack.push(num);
                }
                else if (tokens[i]=="-") {
                    int num = num1 - num2;
                    num_stack.push(num);
                }
                else if (tokens[i]=="*") {
                    int num = num1 * num2;
                    num_stack.push(num);
                }
                else if (tokens[i]=="/") {
                    int num = num1 / num2;
                    num_stack.push(num);
                }
            }
        }
        return num_stack.top();
    }
};
int main() {
    
}