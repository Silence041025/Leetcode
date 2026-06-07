#include "iostream"
#include "vector"
#include "algorithm"
#include "climits"
using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
    Edge(int _from,int _to,int _weight):from(_from),to(_to),weight(_weight){}
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<Edge> edges;
    for (int i=0;i<m;i++) {
        int f,t,w;
        cin>>f>>t>>w;
        edges.push_back(Edge(f,t,w));
    }

    int start = 1;
    int end = n;

    vector<int> min_distance(n+1,INT_MAX);
    min_distance[start] = 0;

    for (int t=0;t<n-1;t++) {
        for (Edge edge:edges) {
            int from = edge.from;
            int to = edge.to;
            int weight = edge.weight;
            if (min_distance[from]!=INT_MAX&&
                min_distance[from]+weight<min_distance[to]) {
                min_distance[to] = min_distance[from] + weight;
            }
        }
    }

    if (min_distance[n]==INT_MAX) {
        cout<<"unconnected";
    }
    else {
        cout<<min_distance[n];
    }
}