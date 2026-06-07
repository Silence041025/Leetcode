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
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int start_pos = str.size();
        for (int i=str.size()-1;i>0;i--) {
            if (str[i]-'0' < str[i-1] - '0') {
                str[i-1] = str[i-1] - 1;
                start_pos = i;
            }
        }

        for (int i=start_pos;i<str.size();i++) {
            str[i] = '9';
        }

        return stoi(str);
    }
};