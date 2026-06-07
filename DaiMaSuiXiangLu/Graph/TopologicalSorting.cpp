#include "iostream"
#include "unordered_map"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> in_degree(n,0);
    unordered_map<int,vector<int>> umap;
    for (int i=0;i<m;i++) {
        int f,t;
        cin>>f>>t;
        in_degree[t]++;
        umap[f].push_back(t);
    }
    vector<int> result;
    queue<int> que;
    for (int i=0;i<n;i++) {
        if (in_degree[i]==0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        result.push_back(cur);
        vector<int> nodes = umap[cur];
        for (int i=0;i<nodes.size();i++) {
            in_degree[nodes[i]]--;
            if (in_degree[nodes[i]]==0) {
                que.push(nodes[i]);
            }
        }
    }
    if (result.size()==n) {
        for (int i=0;i<result.size();i++) {
            cout<<result[i];
            if (i!=result.size()-1) {
                cout<<" ";
            }
        }
    }
    else {
        cout<<-1;
    }
}