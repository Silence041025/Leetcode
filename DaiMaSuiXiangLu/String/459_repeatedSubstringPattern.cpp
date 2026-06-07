#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> pai(s.size(),0);
        for (int i=1;i<s.size();i++) {
            int len = pai[i-1];
            while (len>0&&s[i]!=s[len]) {
                len = pai[len-1];
            }
            if (s[i]==s[len]) {
                pai[i] = len + 1;
            }
        }
        int len = pai[s.size()-1];
        if (len!=0&&len%((int)s.size()-len)==0) {
            return true;
        }
        else {
            return false;
        }
    }
};
int main() {

}