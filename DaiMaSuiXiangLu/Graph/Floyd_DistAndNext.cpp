#include "iostream"
#include "vector"
#include "climits"
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> distance(n+1,vector<int>(n+1,INT_MAX));
    vector<vector<int>> next(n+1,vector<int>(n+1));
    for (int i=0;i<m;i++) {
        int f,t,w;
        cin>>f>>t>>w;
        distance[f][t] = w;
        distance[t][f] = w;
        next[f][t] = t;
        next[t][f] = f;
    }

    for (int i=1;i<=n;i++) {
        distance[i][i] = 0;
        next[i][i] = i;
    }

    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (distance[i][k]!=INT_MAX&distance[k][j]!=INT_MAX) {
                    if (distance[i][j]>distance[i][k]+distance[k][j]) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }

    int q;
    cin>>q;
    for (int i=0;i<q;i++) {
        int start,end;
        cin>>start>>end;
        if (distance[start][end]!=INT_MAX) {
            cout<<distance[start][end]<<endl;
        }
        else {
            cout<<-1<<endl;
        }
    }
}