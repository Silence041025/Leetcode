#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct Edge {
    int from;
    int to;
    Edge():from(0),to(0){}
    Edge(int _from,int _to):from(_from),to(_to){}
};

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
        if (x==parent[x]) {
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
            parent[root_b] = root_a;
        }
    }

    bool is_connected(int a,int b) {
        int root_a = find(a);
        int root_b = find(b);
        return root_a==root_b;
    }
};

int main() {
    int n;
    cin>>n;
    UnionFind union_find(n);
    Edge result;

    for (int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        if (union_find.is_connected(a,b)) {
            result = Edge(a,b);
        }
        else {
            union_find.unite(a,b);
        }
    }

    cout<<result.from<<" "<<result.to;
}