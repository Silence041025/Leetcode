#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash1(26,0);

        for (int i=0;i<s.size();i++) {
            hash1[s[i]-'a']++;
        }

        for (int i=0;i<t.size();i++) {
            hash1[t[i]-'a']--;
        }

        for (int i=0;i<hash1.size();i++) {
            if (hash1[i]!=0) {
                return false;
            }
        }
        return true;
    }
};

int main() {

}