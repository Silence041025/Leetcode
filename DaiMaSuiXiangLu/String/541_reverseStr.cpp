#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int left=0;

        while (left<s.size()) {
            int right=left+2*k;

            if (right>=s.size()) {
                if (s.size()-left<k) {
                    reverse(s.begin()+left,s.end());
                }
                else {
                    reverse(s.begin()+left,s.begin()+left+k);
                }
                break;
            }
            reverse(s.begin()+left,s.begin()+left+k);
            left += 2*k;
        }
        return s;
    }
};
int main() {
    
}