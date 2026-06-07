#include "vector"
using namespace std;

class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i=0;i<n;i++) {
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

    void unite(int x,int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX!=rootY) {
            parent[rootX] = rootY;
        }
    }

    bool is_connected(int x,int y) {
        return find(x) == find(y);
    }
};

