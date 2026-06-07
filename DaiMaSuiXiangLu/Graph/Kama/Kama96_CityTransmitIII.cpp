#include "iostream"
#include "vector"
#include "climits"
using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
    Edge(int _f,int _t,int _w):from(_f),to(_t),weight(_w){}
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<Edge> graph;
    for (int i=0;i<m;i++) {
        int f,t,w;
        cin>>f>>t>>w;
        graph.push_back(Edge(f,t,w));
    }

    int start,end,k;
    cin>>start>>end>>k;

    vector<int> min_distance(n+1,INT_MAX);
    vector<int> min_distance_shadow(n+1,INT_MAX);

    min_distance[start] = 0;
    min_distance_shadow[start] = 0;
    for (int i=0;i<k+1;i++) {
        min_distance_shadow = min_distance;
        for (Edge edge : graph) {
            int from = edge.from;
            int to = edge.to;
            int weight = edge.weight;
            if (min_distance_shadow[from]!=INT_MAX&&
                min_distance_shadow[from] + weight < min_distance[to]) {
                min_distance[to] = min_distance_shadow[from] + weight;
            }
        }
    }
    if (min_distance[end]==INT_MAX) {
        cout<<"unreachable";
    }
    else {
        cout<<min_distance[end];
    }
}