#include <bits/stdc++.h>
using namespace std;

long getDistance(const vector<vector<int>>& distance, int u, int v) {
    if (u < v) swap(u, v);
    return (long)distance[u][v];
}

int main() {
    int n,start,y,z;
    cin >> n >> start >> y >> z;

    vector<vector<int>> edges;
    int edgesNum = n-1;
    while(edgesNum--){
        int u,v,w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
    }

    vector<vector<int>> distance;

    // 只使用一半 distance，降低内存
    distance.resize(n+1);
    for(int i=1;i<=n;i++){
        distance[i].resize(i+1, INT_MAX);
    }
    for (int i = 1; i <= n; i++) {
        distance[i][i] = 0;
    }
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        if(u < v) swap(u, v);
        distance[u][v] = edge[2];
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (getDistance(distance, i, j) > getDistance(distance, i, k) + getDistance(distance, k, j)) {
                    distance[i][j] = getDistance(distance, i, k) + getDistance(distance, k, j);
                }
            }
        }
    }
    
    int ans = INT_MAX;
    int cur;
    for(int end=1;end<n+1;end++){
        cur = 0;
        cur += getDistance(distance, start, end)*y;
        for(int i=1;i<n+1;i++){
            cur += getDistance(distance, end, i)*z;
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;

    return 0;
}