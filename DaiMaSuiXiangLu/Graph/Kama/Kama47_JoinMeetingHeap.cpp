#include "iostream"
#include "queue"
#include "vector"
#include "algorithm"
#include "list"
#include "climits"
using namespace std;

struct Edge {
    int to,weight;
    Edge(int _to,int _weight):to(_to),weight(_weight){}
};

struct NodeAndDist {
    int id;
    int distance;
    NodeAndDist(int _id,int _distance):id(_id),distance(_distance){}
};

struct Cmp {
    bool operator()(NodeAndDist n1,NodeAndDist n2) {
        return n1.distance > n2.distance;
    }
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
    vector<bool> visited(n+1,false);

    min_distance[start] = 0;

    priority_queue<NodeAndDist,vector<NodeAndDist>,Cmp> pque;

    pque.push(NodeAndDist(start,0));
    while (!pque.empty()) {
        NodeAndDist t = pque.top();
        pque.pop();
        if (visited[t.id]) {
            continue;
        }
        visited[t.id] = true;
        for (Edge edge : graph[t.id]) {
            if (!visited[edge.to]&&min_distance[t.id]!=INT_MAX&&
                min_distance[t.id]+edge.weight<min_distance[edge.to]) {
                min_distance[edge.to] = min_distance[t.id] + edge.weight;
                pque.push(NodeAndDist(edge.to,min_distance[edge.to]));
            }
        }
    }

    if (min_distance[end]==INT_MAX) {
        cout<<-1;
    }
    else {
        cout<<min_distance[end];
    }
}