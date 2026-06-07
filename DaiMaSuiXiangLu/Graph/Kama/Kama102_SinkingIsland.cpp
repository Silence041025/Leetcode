#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;

vector<int> drow = {-1,1,0,0};
vector<int> dcol = {0,0,-1,1};

bool can_visit(vector<vector<int>>& graph,vector<vector<bool>>& used
    ,int row,int col) {
    if (row>=0&&row<graph.size()&&col>=0&&col<graph[row].size()&&
        graph[row][col]==1&&!used[row][col]) {
        return true;
    }
    return false;
}

bool is_isolated(vector<vector<int>>& graph,int row,int col) {
    if (row==0||col==0||row==graph.size()-1||col==graph[row].size()-1) {
        return false;
    }
    return true;
}

struct Point {
    int row,col;
    Point(int _row,int _col):row(_row),col(_col){}
};

void bfs(vector<vector<int>>& graph,
    vector<Point>& sinks,
    vector<vector<bool>>& used,
    int row,
    int col,
    bool& isolated) {
    queue<Point> que;
    que.push(Point(row,col));
    sinks.push_back(Point(row,col));
    while (!que.empty()) {
        Point f = que.front();
        sinks.push_back(f);
        que.pop();
        if (!is_isolated(graph,f.row,f.col)) {
            isolated = false;
        }
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
    vector<vector<bool>> used(n,vector<bool>(m,false));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (!used[i][j]&&graph[i][j]==1) {
                used[i][j] = true;
                bool isolated = true;
                vector<Point> sinks;
                bfs(graph,sinks,used,i,j,isolated);
                if (isolated) {
                    for (int k=0;k<sinks.size();k++) {
                        Point temp = sinks[k];
                        graph[temp.row][temp.col] = 0;
                    }
                }
            }
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout<<graph[i][j];
            if (j!=m-1) {
                cout<<" ";
            }
        }
        if (i!=n-1) {
            cout<<endl;
        }
    }
}