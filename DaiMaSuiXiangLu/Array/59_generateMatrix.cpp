#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n));
        int num = 1;
        int start_i = 0;
        int start_j = 0;
        int end_i = result.size() - 1;
        int end_j = result[0].size() - 1;
        int times = n/2;
        for (int t=0;t<times;t++) {
            for (int j=start_j;j<end_j;j++) {
                result[start_i][j] = num++;
            }
            for (int i=start_i;i<end_i;i++) {
                result[i][end_j] = num++;
            }
            for (int j=end_j;j>start_j;j--) {
                result[end_i][j] = num++;
            }
            for (int i=end_i;i>start_i;i--) {
                result[i][start_j] = num++;
            }
            start_i++;
            start_j++;
            end_i--;
            end_j--;
        }
        if (n%2!=0) {
            result[n/2][n/2] = num;
        }
        return result;
    }
};

int main() {
    int n;
    cin>>n;
    Solution solution;

    vector<vector<int>> result = solution.generateMatrix(n);
    for (int i=0;i<result.size();i++) {
        for (int j=0;j<result[i].size();j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}