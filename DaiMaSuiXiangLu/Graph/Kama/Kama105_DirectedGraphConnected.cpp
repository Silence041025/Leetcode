#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;

struct Point{
    int id;
    Point(int _id):id(_id){}
};

bool bfs(vector<vector<int>>& graph,vector<bool>& used,
    int id,int target_visited,int& visited){
    queue<Point> que;
    que.push(Point(id));
    used[id] = true;

    while (!que.empty()) {
        Point f =que.front();
        que.pop();
        if (visited==target_visited) {
            return true;
        }

        for (int c=1;c<graph[f.id].size();c++) {
            if (graph[f.id][c]==1&&!used[c]) {
                visited++;
                used[c] = true;
                int new_id = c;
                que.push(Point(new_id));
            }
        }
    }

    return false;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> graph(n+1,vector<int>(n+1,0));
    vector<bool> used(n+1,false);
    for (int i=0;i<k;i++){
        int r,c;
        cin>>r>>c;
        graph[r][c] = 1;
    }

    int visited = 1;
    if (bfs(graph,used,1,n,visited)) {
        cout<<1;
    }
    else {
        cout<<-1;
    }

}