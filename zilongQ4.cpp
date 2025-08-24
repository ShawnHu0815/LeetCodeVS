#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int V;
    cin >> V;
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<vector<bool>> dp(n+1, vector<bool>(V+1, false));
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=V;j++){
            if(dp[i-1][j]){
                dp[i][j] = true;
                if(j+v[i] <= V){
                    dp[i][j+v[i]] = true;
                }
            }
        }
    }

    int ans = 0;
    for(int j=0;j<=V;j++){
        if(dp[n][j]){
            ans = max(ans, j);
        }
    }
    cout << V - ans << endl;

    return 0;
}