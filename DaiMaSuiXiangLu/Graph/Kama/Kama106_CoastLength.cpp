#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;

vector<int> drow = {-1,1,0,0};
vector<int> dcol = {0,0,-1,1};

struct Point {
    int row,col;
    Point(int _row,int _col):row(_row),col(_col){}
};

bool can_visit(vector<vector<int>>& graph,vector<vector<bool>>& used,
    int row,int col) {
    if (row>=0&&row<graph.size()&&col>=0&&col<graph[row].size()&&
        graph[row][col]==1&&!used[row][col]) {
        return true;
    }
    return false;
}

void cal_length(vector<vector<int>>& graph,int row,int col,int& length) {
    if (row==0||graph[row-1][col]==0) {
        length++;
    }
    if (row==graph.size()-1||graph[row+1][col]==0) {
        length++;
    }
    if (col==0||graph[row][col-1]==0) {
        length++;
    }
    if (col==graph[row].size()-1||graph[row][col+1]==0) {
        length++;
    }
}

void bfs(vector<vector<int>>& graph,vector<vector<bool>>& used,
    int row,int col,int& length) {
    queue<Point> que;
    que.push(Point(row,col));
    used[row][col] = true;
    while (!que.empty()) {
        Point f = que.front();
        que.pop();
        cal_length(graph,f.row,f.col,length);
        for (int i=0;i<4;i++) {
            int new_row = f.row + drow[i];
            int new_col = f.col + dcol[i];
            if (can_visit(graph,used,new_row,new_col)) {
                que.push(Point(new_row,new_col));
                used[new_row][new_col] = true;
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
    int length = 0;
    vector<vector<bool>> used(n,vector<bool>(m,false));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (graph[i][j]==1) {
                bfs(graph,used,i,j,length);
                cout<<length;
                return 0;
            }
        }
    }
}