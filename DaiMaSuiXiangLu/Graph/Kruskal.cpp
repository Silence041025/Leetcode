#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct Edge {
    int from,to,weight;
    Edge(int _from,int _to,int _weight):from(_from),
    to(_to),weight(_weight){}
};

bool cmp(Edge e1,Edge e2) {
    return e1.weight < e2.weight;
}

class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n+1);
        for (int i=1;i<=n;i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x]==x) {
            return x;
        }
        else {
            return parent[x] = find(parent[x]);
        }
    }

    void unite(int a,int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a!=root_b) {
            parent[root_a] = root_b;
        }
    }

    bool is_connected(int a,int b) {
        int root_a = find(a);
        int root_b = find(b);
        return root_a == root_b;
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<Edge> edges;
    for (int i=0;i<m;i++) {
        int x,y,k;
        cin>>x>>y>>k;
        edges.push_back(Edge(x,y,k));
    }
    sort(edges.begin(), edges.end(),cmp);
    UnionFind union_find(n);
    int result = 0;
    for (int e=0;e<m;e++) {
        if (!union_find.is_connected(edges[e].from,edges[e].to)) {
            union_find.unite(edges[e].from,edges[e].to);
            result += edges[e].weight;
        }
    }

    cout<<result;
}