#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i =0,j=s.size()-1;i<s.size()/2;i++,j--) {
            char temp;
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};

int main() {
    
}