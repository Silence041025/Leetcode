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

bool can_visit(vector<vector<int>>& graph,
    vector<vector<bool>>& border_reach,
    int row,int col,int new_row,int new_col) {
    if (new_row>=0&&new_row<graph.size()&&
        new_col>=0&&new_col<graph[new_row].size()&&
        !border_reach[new_row][new_col]&&
        graph[new_row][new_col]>=graph[row][col]) {
        return true;
    }
    return false;
}

void bfs(vector<vector<int>>& graph,vector<vector<bool>>& border_reach,int row,int col) {
    queue<Point> que;
    que.push(Point(row,col));
    border_reach[row][col] = true;
    while (!que.empty()) {
        Point f = que.front();
        border_reach[f.row][f.col] = true;
        que.pop();
        for (int i=0;i<4;i++) {
            int new_row = f.row + drow[i];
            int new_col = f.col + dcol[i];
            if (can_visit(graph,border_reach,f.row,f.col,new_row,new_col)) {
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

    vector<vector<bool>> first_border_reach(n,vector<bool>(m,false));
    vector<vector<bool>> second_border_reach(n,vector<bool>(m,false));
    for (int c=0;c<graph[0].size();c++) {
        bfs(graph,first_border_reach,0,c);
    }
    for (int r=1;r<graph.size();r++) {
        bfs(graph,first_border_reach,r,0);
    }

    for (int c=0;c<graph[0].size();c++) {
        bfs(graph,second_border_reach,n-1,c);
    }
    for (int r=0;r<graph.size()-1;r++) {
        bfs(graph,second_border_reach,r,m-1);
    }

    vector<Point> result;

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (first_border_reach[i][j]&&second_border_reach[i][j]) {
                result.push_back(Point(i,j));
            }
        }
    }

    for (int i=0;i<result.size();i++) {
        cout<<result[i].row<<" "<<result[i].col;
        if (i!=result.size()-1) {
            cout<<endl;
        }
    }
}