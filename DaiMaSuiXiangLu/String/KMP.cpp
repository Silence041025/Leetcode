#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

int main() {
    string s1,s2;
    cin>>s1>>s2;
    string s = s2 + '#' + s1;
    vector<int> pi(s.size(),0);
    for (int i=1;i<s.size();i++) {
        int len = pi[i-1];
        while (len>0&&s[len]!=s[i]) {
            len = pi[len-1];
        }
        if (s[i]==s[len]) {
            pi[i] = len + 1;
        }
        if (pi[i]==s2.size()) {
            cout<<i - 2 * s2.size() + 1<<endl;
        }
    }

    for (int i=0;i<s2.size();i++) {
        cout<<pi[i]<<" ";
    }
}