#include "iostream"
#include "vector"
#include "climits"
#include "queue"
using namespace std;

// 0 1
//7   2
//6   3
// 5 4

vector<int> drow = {-2,-2,-1,1,2,2,1,-1};
vector<int> dcol = {-1,1,2,2,1,-1,-2,-2};

struct Point {
    int row;
    int col;
    int cost_from_start;
    int heuristic_estimate;
    int total_estimated_cost;

    Point(int row, int col, int cost_from_start, int heuristic_estimate, int total_estimated_cost)
        : row(row),
          col(col),
          cost_from_start(cost_from_start),
          heuristic_estimate(heuristic_estimate),
          total_estimated_cost(total_estimated_cost) {
    }
};

struct Cmp {
    bool operator()(Point a,Point b) {
        return a.total_estimated_cost > b.total_estimated_cost;
    }
};

bool can_visit(int row,int col) {
    if (row>=1&&row<=1000&&col>=1&&col<=1000) {
        return true;
    }
    return false;
}

int heuristics(int x1,int y1,int x2,int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

void a_star_search(vector<vector<int>>& best,
    int start_row,int start_col,int target_row,int target_col,
    int& result) {
    priority_queue<Point,vector<Point>,Cmp> que;
    int start_h = heuristics(start_row,start_col,target_row,target_col);
    que.push(Point(start_row,start_col,0,start_h,start_h));
    best[start_row][start_col] = 0;
    while (!que.empty()) {
        Point t = que.top();
        que.pop();
        if (t.row==target_row&&t.col==target_col) {
            result = t.cost_from_start;
            return;
        }
        if (t.cost_from_start > best[t.row][t.col]) {
            continue;
        }
        for (int i=0;i<8;i++) {
            int new_row = t.row + drow[i];
            int new_col = t.col + dcol[i];
            if (can_visit(new_row,new_col)) {
                int new_cost_from_start = t.cost_from_start + 5;
                if (new_cost_from_start<best[new_row][new_col]) {
                    best[new_row][new_col] = new_cost_from_start;
                    int new_heuristic_estimate = heuristics(new_row,new_col,target_row,target_col);
                    int new_total_estimated_cost = new_cost_from_start + new_heuristic_estimate;
                    que.push(Point(new_row,new_col,new_cost_from_start,new_heuristic_estimate,new_total_estimated_cost));
                }
            }
        }
    }
}

int main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        int start_row,start_col,target_row,target_col;
        cin>>start_row>>start_col>>target_row>>target_col;
        vector<vector<int>> best(1001,vector<int>(1001,INT_MAX));
        int result = -1;
        a_star_search(best,start_row,start_col,target_row,target_col,result);
        cout<<result/5<<endl;
    }
}