#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;

struct Point {
    int id, steps;
    Point(int _id, int _steps) : id(_id), steps(_steps) {}
};

bool bfs(vector<vector<int>>& graph, int target_id, int& steps) {
    vector<bool> visited(graph.size(), false);  // visited 数组
    queue<Point> que;
    que.push(Point(0, 1));
    visited[0] = true;

    while (!que.empty()) {
        Point f = que.front();
        que.pop();
        if (f.id == target_id) {
            steps = f.steps;
            return true;
        }
        for (int c = 0; c < graph[f.id].size(); c++) {
            if (graph[f.id][c] == 1 && !visited[c]) {
                visited[c] = true;
                que.push(Point(c, f.steps + 1));
            }
        }
    }
    return false;
}

bool is_connected(string str1, string str2) {
    int change_num = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) {
            change_num++;
            if (change_num > 1) {
                return false;
            }
        }
    }
    return change_num == 1;
}

int main() {
    int n;
    cin >> n;
    string beginStr, endStr;
    cin >> beginStr >> endStr;

    vector<string> strList(n + 2);
    strList[0] = beginStr;
    strList.back() = endStr;
    for (int i = 1; i < strList.size() - 1; i++) {
        cin >> strList[i];
    }

    vector<vector<int>> graph(n + 2, vector<int>(n + 2, 0));

    // 建图：添加双向边（这样才能保证连通）
    for (int i = 0; i < strList.size(); i++) {
        for (int j = i + 1; j < strList.size(); j++) {
            if (is_connected(strList[i], strList[j])) {
                graph[i][j] = 1;
                graph[j][i] = 1;  // 关键：添加反向边
            }
        }
    }

    int steps = 0;
    if (bfs(graph, n + 1, steps)) {
        cout << steps << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}