#include "iostream"
#include "vector"
#include "climits"
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,INT_MAX)));
    for (int i=0;i<m;i++) {
        int f,t,w;
        cin>>f>>t>>w;
        dp[0][f][t] = w;
        dp[0][t][f] = w;
    }

    for (int i=1;i<=n;i++) {
        dp[0][i][i] = 0;
    }

    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                dp[k][i][j] = dp[k-1][i][j];
                if (dp[k-1][i][k]!=INT_MAX&&dp[k-1][k][j]!=INT_MAX) {
                    dp[k][i][j] = min(dp[k][i][j],dp[k-1][i][k]+dp[k-1][k][j]);
                }
            }
        }
    }

    int q;
    cin>>q;
    for (int i=0;i<q;i++) {
        int start,end;
        cin>>start>>end;
        if (dp[n][start][end]!=INT_MAX) {
            cout<<dp[n][start][end]<<endl;
        }
        else {
            cout<<-1<<endl;
        }
    }
}