#include "iostream"
#include "vector"
#include "algorithm"
#include "climits"
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1,vector<int>(n+1,INT_MAX));
    vector<int> min_distance(n+1,INT_MAX);
    vector<bool> visited(n+1,false);
    for (int i=0;i<m;i++) {
        int f,t,w;
        cin>>f>>t>>w;
        graph[f][t] = w;
    }
    int start = 1;
    int end = n;
    min_distance[start] = 0;
    for (int t=0;t<n;t++) {
        int min_dis = INT_MAX;
        int cur_node = 0;
        for (int i=1;i<=n;i++) {
            if (!visited[i]&&min_distance[i]<min_dis) {
                min_dis = min_distance[i];
                cur_node = i;
            }
        }

        visited[cur_node] = true;

        for (int j=1;j<=n;j++) {
            if (!visited[j]&&min_distance[cur_node] + graph[cur_node][j]<min_distance[j]) {
                min_distance[j] = min_distance[cur_node] + graph[cur_node][j];
            }
        }
    }

    cout<<min_distance[end];
}