#include "iostream"
#include "vector"
#include "algorithm"
#include "climits"
#include "queue"
#include "list"
using namespace std;

struct Edge {
    int to;
    int weight;
    Edge(int _to,int _weight):to(_to),weight(_weight){}
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<list<Edge>> graph(n+1);
    for (int i=0;i<m;i++) {
        int f,t,w;
        cin>>f>>t>>w;
        graph[f].push_back(Edge(t,w));
    }

    int start = 1;
    int end = n;
    vector<int> min_distance(n+1,INT_MAX);
    vector<bool> inque(n+1,false);
    min_distance[start] = 0;
    queue<int> que;
    que.push(start);

    while (!que.empty()) {
        int f = que.front();
        que.pop();
        inque[f] = false;
        for (Edge edge : graph[f]) {
            int from = f;
            int to = edge.to;
            int weight = edge.weight;
            if (min_distance[from]!=INT_MAX&&
                min_distance[from] + weight < min_distance[to]) {
                min_distance[to] = min_distance[from] + weight;
                if (!inque[to]) {
                    que.push(to);
                    inque[to] = true;
                }
            }
        }
    }

    if (min_distance[end]==INT_MAX) {
        cout<<"unconnected";
    }
    else {
        cout<<min_distance[end];
    }
}