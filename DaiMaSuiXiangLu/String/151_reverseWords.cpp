#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int slow=0;
        for (int fast=0;fast<s.size();fast++) {
            if (s[fast]!=' ') {
                if (slow!=0) {
                    s[slow++] = ' ';
                }
                while (fast<s.size()&&s[fast]!=' ') {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
        int i=0;
        int j=1;
        while (j<s.size()+1) {
            if (j==s.size()) {
                reverse(s.begin()+i,s.end());
                break;
            }
            while  (j<s.size()&&s[j]!=' ') {
                j++;
            }
            reverse(s.begin()+i,s.begin()+j);
            i = j+1;
            j = i+1;
        }
        return s;
    }
};
int main() {
    
}