#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    vector<string> hash_map={
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> results;
    string collect;

    void backtracking(vector<string>& result,string collect,string digits,int digit_index) {
        if (collect.size()==digits.size()) {
            result.push_back(collect);
            return;
        }
        for (int i=0;i<hash_map[digits[digit_index]-'0'].size();i++) {
            collect += hash_map[digits[digit_index]-'0'][i];
            backtracking(result,collect,digits,digit_index+1);
            collect.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        backtracking(results,collect,digits,0);

        return results;
    }
};
int main() {
    
}