#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;

vector<int> drow = {-1,1,0,0};
vector<int> dcol = {0,0,1,-1};

struct Point {
    int row,col;
    Point(int _row,int _col):row(_row),col(_col){}
};

bool can_visit(vector<vector<int>>& graph,vector<vector<bool>>& used,
    int row,int col) {
    if (row>=0&&row<graph.size()&&col>=0&&col<graph[row].size()&&
        !used[row][col]&&graph[row][col]==1) {
        return true;
    }
    return false;
}

void bfs(vector<vector<int>>& graph,vector<vector<bool>>& used,int row,int col
    ,int& area) {
    queue<Point> que;
    que.push(Point(row,col));
    used[row][col] = true;
    while (!que.empty()) {
        Point f = que.front();
        area++;
        que.pop();
        for (int i=0;i<4;i++) {
            int new_row = f.row + drow[i];
            int new_col = f.col + dcol[i];
            if (can_visit(graph,used,new_row,new_col)) {
                used[new_row][new_col] = true;
                que.push(Point(new_row,new_col));
            }
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(m,0));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin>>graph[i][j];
        }
    }

    int result = 0;
    bool all_one = true;

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (graph[i][j]==0) {
                all_one = false;
                vector<vector<bool>> used(n,vector<bool>(m,false));
                int area = 0;
                bfs(graph,used,i,j,area);
                result = max(result,area);
            }
        }
    }

    if (all_one) {
        result = max(result,n*m);
    }
    cout<<result;
}