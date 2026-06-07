#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

vector<int> drow = {-1,1,0,0};
vector<int> dcol = {0,0,-1,1};

bool can_visit(vector<vector<int>>& graph,vector<vector<bool>>& used,
    int row,int col) {
    if (row>=0&&row<graph.size()&&col>=0&&col<graph[row].size()&&
        !used[row][col]&&graph[row][col]==1) {
        return true;
    }
    return false;
}

void dfs(vector<vector<int>>& graph,vector<vector<bool>>& used,
    int row,int col){
    used[row][col] = true;
    for (int i=0;i<4;i++) {
        int new_row = row + drow[i];
        int new_col = col + dcol[i];
        if (can_visit(graph,used,new_row,new_col)) {
            dfs(graph,used,new_row,new_col);
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> graph(n,vector<int>(m,0));
    vector<vector<bool>> used(n,vector<bool>(m,false));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin>>graph[i][j];
        }
    }

    int count = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (!used[i][j]&&graph[i][j]==1) {
                count++;
                dfs(graph,used,i,j);
            }
        }
    }

    cout<<count;
}