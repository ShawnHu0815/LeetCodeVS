#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,start,y,z;
    // cin >> n >> start >> y >> z;

    // 3 1 3 4
    // 1 2 1
    // 2 3 1

    n = 3;
    start = 1;
    y = 3;
    z = 4;

    vector<vector<int>> edges;
    int edgesNum = n-1;
    // while(edgesNum--){
    //     int u,v,w;
    //     cin >> u >> v >> w;

    //     nodes[u].edges.push_back({v, w});
    //     nodes[v].edges.push_back({u, w});
    // }
    edges.push_back({1, 2, 1});
    edges.push_back({2, 1, 1});
    edges.push_back({2, 3, 1});
    edges.push_back({3, 2, 1});

    for (const auto& edge1 : edges) {
        int u1 = edge1[0], v1 = edge1[1], w1 = edge1[2];
        for (const auto& edge2 : edges) {
            int u2 = edge2[0], v2 = edge2[1], w2 = edge2[2];
            if (v1 == u2) {
                edges.push_back({u1, v2, w1 + w2});
            }
        }
    }

    int ans = INT_MAX;
    int cur;
    vector<bool> visited(n+1, false);
    for(int start=1;start<n+1;start++){
        cur = 0;
        for(int end=1;end<n+1;end++){
            for(const auto& edge : edges){
                if(edge[0] == start && edge[1] == end){
                    cur += edge[2] * y;
                }
            }
            ans = min(ans, cur);
        }
    }
    cout << ans << endl;

    return 0;
    
}