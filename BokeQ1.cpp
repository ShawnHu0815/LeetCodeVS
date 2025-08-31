#include <bits/stdc++.h>
using namespace std;

bool hasMoreThan3ConnectionsInSameRow(const vector<vector<int>>& grid, vector<vector<bool>>& mark) {
    bool flag = false;
    for(int i = 0; i < grid.size(); i++) {
        int count = 0;
        for(int j = 0; j < grid[i].size(); j++) {
            int cur = grid[i][j];
            if(j > 0 && j+1 < grid[i].size() && cur != 0 && grid[i][j-1] == cur && grid[i][j+1] == cur && !mark[i][j]) {
                mark[i][j] = true;
                mark[i][j-1] = true;
                mark[i][j+1] = true;
                int k = j+1;
                while(k < grid[i].size() && grid[i][k] == cur) {
                    mark[i][k] = true;
                    k++;
                }
                flag = true;
            }
        }
    }
    return flag;
}

void disappearAndCalculate(vector<vector<int>>& grid, vector<vector<bool>>& mark, long &score) {
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(mark[i][j]){
                score += grid[i][j];
            }
        }
    }
    for(int i=grid.size()-1;i>=0;i--){
        for(int j=0;j<grid[i].size();j++){
            if(mark[i][j]){
                int k = i-1;
                while(k>=0 && mark[k][j]){
                    k--;
                }
                grid[i][j] = (k >= 0) ? grid[k][j] : 0;
                if(k >= 0) mark[k][j] = true;
            }
        }
    }
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            mark[i][j] = false;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int H;
        cin >> H;
        vector<vector<int>> grid(H, vector<int>(5));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> grid[i][j];
            }
        }
        vector<vector<bool>> mark(H, vector<bool>(5, false));
        long score = 0;
        while (hasMoreThan3ConnectionsInSameRow(grid, mark)) {
            disappearAndCalculate(grid, mark, score);
        }
        cout << score << endl;
    }
    return 0;
}