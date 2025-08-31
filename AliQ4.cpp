#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to, pleasant, time;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
};

void DFS(int node, int target, int currentPleasant, int currentTime, int &maxPleasant, int &minTime, vector<bool> &visited, const Graph &g) {
    if(node == target) {
        if(currentPleasant > maxPleasant || (currentPleasant == maxPleasant && currentTime < minTime)) {
            maxPleasant = currentPleasant;
            minTime = currentTime;
        }
        return;
    }
    visited[node] = true;
    for(const auto &edge : g.edges) {
        if(edge.from == node && !visited[edge.to]) {
            if(edge.pleasant == -1){
                DFS(edge.to, target, currentPleasant, currentTime + edge.time, maxPleasant, minTime, visited, g);
            }else{
                currentPleasant = min(currentPleasant, edge.pleasant);
                DFS(edge.to, target, currentPleasant, currentTime + edge.time, maxPleasant, minTime, visited, g);
            }
            
        }
    }
    visited[node] = false;
}

int main() {
    freopen("input.txt", "r", stdin);
    int N,M;
    cin >> N >> M;
    while(!(N == 0 && M == 0)) {
        Graph g;
        g.V = N;
        g.E = M;
        g.edges.resize(M);
        for(int i = 0; i < M; i++) {
            cin >> g.edges[i].from >> g.edges[i].to >> g.edges[i].pleasant >> g.edges[i].time;
        }
        int S,T,Spleasant;
        cin >> S >> T >> Spleasant;
        int maxPleasant = INT_MIN;
        int minTime = INT_MAX;
        vector<bool> visited(N, false);
        DFS(S, T, Spleasant, 0, maxPleasant, minTime, visited, g);
        if(minTime == INT_MAX){
            cout << "Impossible!" << endl;
        }else{
            cout << maxPleasant << " " << minTime << endl;
        }
        cin >> N >> M;
    }
    return 0;
}