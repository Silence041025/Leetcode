#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

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

    bool connected(int a,int b) {
        int root_a = find(a);
        int root_b = find(b);
        return root_a == root_b;
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    UnionFind union_find(n);
    for (int i=0;i<m;i++) {
        int s,t;
        cin>>s>>t;
        union_find.unite(s,t);
    }

    int start,end;
    cin>>start>>end;
    if (union_find.connected(start,end)) {
        cout<<1;
    }
    else {
        cout<<0;
    }
}