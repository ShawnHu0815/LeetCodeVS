#include "bits/stdc++.h"
using namespace std;

vector<int> deltaX = {1,-1,0,0};
vector<int> deltaY = {0,0,1,-1};

struct Point{
    int x;
    int y;
    Point(int x,int y):x(x),y(y){};
};

void DFS(vector<vector<int>> map, vector<vector<Point>> ans, vector<vector<bool>>& visited,vector<Point>& temp, int x,int y,int n, int m,int cur){
    visited[x][y] = true;
    temp.push_back(Point(x,y));
    
    for(int i=0;i<4;i++){
        int newX = x + deltaX[i];
        int newY = y + deltaY[i];
        if(newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY] && map[newX][newY] == cur){
            DFS(map,ans,visited,temp,newX,newY,n,m,cur);
        }
    }

}

int main() {
    vector<vector<int>> map({
       {1,2,1,2},
       {2,1,2,1},
       {1,2,1,2},
       {2,1,2,1} 
    });

    int m = map.size();
    int n = map[0].size();

    vector<vector<bool>> visited(m,vector<bool>(n));
    vector<vector<Point>> ans;
    vector<Point> temp;
    for(int x=0;x<m;x++){
        for(int y=0;y<n;y++){
            vector<Point> temp;
            if(!visited[x][y]){
                int cur = map[x][y];
                DFS(map,ans,visited,temp,x,y,n,m,cur);
            }
            if(temp.size() > 1){
                ans.push_back(temp);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout << "第" << i+1 << "个连通块:"; 
        vector<Point> temp = ans[i];
        for(int j=0;j<temp.size();j++){
            cout << "x " << temp[j].x << " y " << temp[j].y << ";";
        }
        cout << endl;
    }
    
    return 0;
}