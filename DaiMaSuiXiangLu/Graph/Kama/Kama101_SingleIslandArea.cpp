#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
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

bool in_bound(vector<vector<int>>& graph,int row,int col) {
    if (row==0||col==0||row==graph.size()-1||
        col==graph[row].size()-1) {
        return false;
    }

    return true;
}

struct Point {
    int row,col;
    Point(int _row,int _col):row(_row),col(_col){}
};

void bfs(vector<vector<int>>& graph,vector<vector<bool>>& used,
    int row,int col,int& area,bool& valid) {
    queue<Point> que;
    que.push(Point(row,col));
    while (!que.empty()) {
        Point f = que.front();
        que.pop();
        if (!in_bound(graph,f.row,f.col)) {
            valid = false;
        }

        for (int i=0;i<4;i++) {
            int new_row = f.row + drow[i];
            int new_col = f.col + dcol[i];
            if (can_visit(graph,used,new_row,new_col)) {
                que.push(Point(new_row,new_col));
                used[new_row][new_col] = true;
                area++;
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
    vector<vector<bool>> used(n,vector<bool>(m,false));
    int single_island_area = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (!used[i][j]&&graph[i][j]==1) {
                int area = 1;
                bool valid = true;
                used[i][j] = true;
                bfs(graph,used,i,j,area,valid);
                if (valid) {
                    single_island_area += area;
                }
            }
        }
    }

    cout<<single_island_area;
}