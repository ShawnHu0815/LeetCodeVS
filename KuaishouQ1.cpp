#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    sort(heights.begin(), heights.end());
    int total = 0;
    for (int i = 0; i < n ; i++) {
        total += heights[i];
    }
    int target = total / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j >= heights[i - 1]) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - heights[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for(int j = target; j >= 0; j--){
        if(dp[n][j]){
            cout << j << endl;
            break;
        }
    }

    return 0;
}