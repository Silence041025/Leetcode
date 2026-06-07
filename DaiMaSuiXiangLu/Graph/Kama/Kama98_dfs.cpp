#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

void dfs(vector<vector<int>>& result,
    vector<int>& path,
    vector<vector<int>>& grid,int from,int to) {
    if (from==to) {
        result.push_back(path);
        return;
    }

    for (int i=1;i<grid.size();i++) {
        if (grid[from][i]) {
            path.push_back(i);
            dfs(result,path,grid,i,to);
            path.pop_back();
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    int from,to;
    vector<vector<int>> grid(n+1,vector<int>(n+1,0));
    for (int i=0;i<m;i++) {
        cin>>from>>to;
        grid[from][to] = 1;
    }
    vector<int> path;
    path.push_back(1);
    vector<vector<int>> result;
    dfs(result,path,grid,1,n);
    if (result.size()==0) {
        cout<<-1;
        return 0;
    }
    for (int i=result.size()-1;i>=0;i--) {
        for (int j=0;j<result[i].size();j++) {
            cout<<result[i][j];
            if (j!=result[i].size()-1) {
                cout<<" ";
            }
        }
        if (i!=0) {
            cout<<endl;
        }
    }
}