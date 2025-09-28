#include <bits/stdc++.h>
using namespace std;

vector<int> deltaX = {-1, 0, 1, 0};
vector<int> deltaY = {0, 1, 0, -1};
bool flag = false;

class UnionFind {

void unionCell(vector<vector<bool>>& visited, vector<vector<int>>& map, int hour, int x2, int y2){
    int n = map.size();
    int m = map[0].size();
    vector<vector<bool>> newVisited = visited;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j] == true){
                for(int d=0;d<4;d++){
                    int newX = i + deltaX[d];
                    int newY = j + deltaY[d];
                    if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                        if(map[newX][newY] <= hour){
                            newVisited[newX][newY] = true;
                        }
                    }
                }
            }
        }
    }
    visited = newVisited;
    if(visited[x2][y2] == true){
        flag = true;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int minTime = INT_MAX;
    int hour = 0;
    while (flag == false)
    {
        unionCell(visited, map, hour,x2,y2);
        hour++;
    }
    cout << hour-1 << endl;
    return 0;
}