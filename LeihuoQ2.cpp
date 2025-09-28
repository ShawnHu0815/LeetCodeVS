#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int M;
    cin>>M;
    while(M--){
        int HP, LowerHP, UpperHP, n;
        cin>>HP>>LowerHP>>UpperHP>>n;
        vector<int> damage(n);
        for(int i=0;i<n;i++){
            cin>>damage[i];
        }
        vector<vector<int>> dp(n, vector<int>(HP+1, INT_MAX));
        for(int i=0;i<n;i++){
            int curTime = 0;
            for(int j=0;j<=HP;j+=damage[i],curTime++){
                dp[i][j] = min(dp[i][j], curTime);
            }
            if(i > 0){
                int curHP = 0;
                curTime = 0;
                while(curHP <= HP){
                    for(int j=0;j<=HP;j++){
                        if(dp[i-1][j] != INT_MAX && j + curHP <= HP){
                            dp[i][j] = dp[i-1][j];
                            dp[i][j + curHP] = min(dp[i][j + curHP], dp[i-1][j] + curTime);
                        }
                    }
                    curHP += damage[i];
                    curTime++;
                }
            }
        }
        int ans = INT_MAX;
        for(int i=HP-UpperHP;i<=HP-LowerHP;i++){
            if(dp[n-1][i] != INT_MAX){
                ans = min(ans, dp[n-1][i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}