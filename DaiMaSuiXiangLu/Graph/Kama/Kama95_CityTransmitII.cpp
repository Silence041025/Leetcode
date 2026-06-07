#include "iostream"
#include "vector"
#include "algorithm"
#include "list"
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
    int start = 1;
    int end = n;
    vector<int> min_distance(n+1,INT_MAX);
    min_distance[start] = 0;
    bool have_circle = false;

    for (int i=0;i<n;i++) {
        for (Edge edge : graph) {
            int from = edge.from;
            int to = edge.to;
            int weight = edge.weight;
            if (i!=n-1) {
                if (min_distance[from]!=INT_MAX&&
                min_distance[from]+weight<min_distance[to]) {
                    min_distance[to] = min_distance[from] + weight;
                }
            }
            else {
                if (min_distance[from]!=INT_MAX&&
                min_distance[from]+weight<min_distance[to]) {
                    have_circle = true;
                    min_distance[to] = min_distance[from] + weight;
                }
            }
        }
    }

    if (min_distance[end]==INT_MAX) {
        cout<<"unconnected";
    }
    else if (have_circle) {
        cout<<"circle";
    }
    else {
        cout<<min_distance[end];
    }
}