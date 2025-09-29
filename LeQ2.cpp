#include <bits/stdc++.h>
using namespace std;

int GetMaxGold(int M, vector<vector<int> >& mines) {
    int n = mines.size();
    sort(mines.begin(), mines.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    });
    vector<vector<int>> consumeDP(n, vector<int>(M + 1, 0));
    vector<vector<int>> goldDP(n, vector<int>(M + 1, 0));
    for(int i = 0; i < n; i++){
        vector<int>& mine = mines[i];
        int consume = mine[2];
        int totalConsume = mine[0] + consume;
        if(totalConsume <= M){
            goldDP[i][totalConsume] = max(mine[1], goldDP[i][totalConsume]);
            consumeDP[i][totalConsume] = consume;
        }
        for (int j = 0; j <= M; j++) {
            if(i > 0){
                if(consumeDP[i-1][j] != 0){
                    consumeDP[i][j] = max(consumeDP[i][j], consumeDP[i-1][j]);
                    goldDP[i][j] = max(goldDP[i][j], goldDP[i-1][j]);
                    if(totalConsume + consumeDP[i-1][j] <= M){
                        int newConsume = totalConsume + consumeDP[i-1][j];
                        int newGold = mine[1] + goldDP[i-1][j];
                        if(newGold > goldDP[i][newConsume]){
                            goldDP[i][newConsume] = newGold;
                            consumeDP[i][newConsume] = consume + consumeDP[i-1][j];
                        }else if(newGold == goldDP[i][newConsume]){
                            consumeDP[i][newConsume] = min(consumeDP[i][newConsume], consume + consumeDP[i-1][j]);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int j = 0; j <= M; j++){
        ans = max(ans, goldDP[n-1][j]);
    }
    return ans;
}

int main() {
    // 10,[[1,1,2],[5,1,0],[4,2,4],[10,1,4]]
    int M = 10;
    vector<vector<int> > mines = {{1,1,2},{5,1,0},{4,2,4},{10,1,4}};
    int ans = GetMaxGold(M, mines);
    cout<<ans<<endl;
    
    return 0;
}