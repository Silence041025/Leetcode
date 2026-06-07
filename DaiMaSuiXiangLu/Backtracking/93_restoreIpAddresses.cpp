#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    vector<string> results;
    string collect;

    bool is_valid(string s,int left_index,int right_index) {
        string str = s.substr(left_index,right_index-left_index+1);
        if (right_index-left_index+1>3||(str.size()>1&&str[0]=='0')||stoi(str)>255) {
            return false;
        }
        return true;
    }

    void backtracking(vector<string>& results,string& collect,
        string s,int start_index,int segment_count) {
        if (segment_count==4) {
            if (start_index>=s.size()) {
                results.push_back(collect);
            }
            return;
        }

        for (int i=start_index;i<s.size();i++) {
            if (!is_valid(s,start_index,i)) {
                continue;
            }
            collect+=s.substr(start_index,i-start_index+1);
            if (i!=s.size()-1) {
                collect += '.';
            }
            segment_count++;
            backtracking(results,collect,s,i+1,segment_count);
            segment_count--;
            if (i!=s.size()-1) {
                collect.pop_back();
            }
            collect.erase(collect.size()-(i-start_index+1));
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtracking(results,collect,s,0,0);
        return results;
    }
};
int main() {
    
}