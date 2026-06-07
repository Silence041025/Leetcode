#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    vector<vector<string>> results;
    vector<string> collect;

    bool is_palindrome(string s,int left_index,int right_index) {
        while (left_index<right_index) {
            if (s[left_index]!=s[right_index]) {
                return false;
            }
            left_index++;
            right_index--;
        }

        return true;
    }

    void backtracking(vector<vector<string>>& results,vector<string>& collect,
        string s,int start_index) {
        if (start_index>=s.size()) {
            results.push_back(collect);
            return;
        }
        for (int i=start_index;i<s.size();i++) {
            if (!is_palindrome(s,start_index,i)) {
                continue;
            }
            collect.push_back(s.substr(start_index,i-start_index+1));
            backtracking(results,collect,s,i+1);
            collect.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        backtracking(results,collect,s,0);
        return results;
    }
};

int main() {
    
}