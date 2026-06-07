#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1,vector<int>(n+1,INT_MAX));
    for (int i=0;i<m;i++) {
        int x,y,k;
        cin>>x>>y>>k;
        graph[x][y] = k;
        graph[y][x] = k;
    }

    vector<bool> joined(n+1,false);
    vector<int> min_distance(n+1,INT_MAX);
    min_distance[1] = 0;

    for (int t=0;t<n;t++) {
        int cur_node = -1;
        int min_dist = INT_MAX;
        for (int i=1;i<=n;i++) {
            if (!joined[i]&&min_distance[i]<min_dist) {
                cur_node = i;
                min_dist = min_distance[i];
            }
        }

        joined[cur_node] = true;

        for (int j=1;j<=n;j++) {
            if (!joined[j]&&graph[cur_node][j]<min_distance[j]) {
                min_distance[j] = graph[cur_node][j];
            }
        }
    }

    int result = 0;
    for (int i=1;i<=n;i++) {
        result += min_distance[i];
    }

    cout<<result;
}