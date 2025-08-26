#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    // int j=1;
    // while(j<=n){
    //     if(obstacleGrid[1][j] != 1){
    //         dp[0][j] = 1; 
    //         j++;
    //     }else{
    //         break;
    //     }
    // }    
    // int i=1;
    // while(i<=m){
    //     if(obstacleGrid[i][1] != 1){
    //         dp[i][0] = 1;
    //         i++;
    //     }else{
    //         break;
    //     }
    // }
    if(obstacleGrid[0][0] == 0){
        dp[1][1] = 1;
    }else{
        dp[1][1] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i==1 && j==1)continue;
            if(obstacleGrid[i-1][j-1] == 1){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
    }
    return dp[m][n];
}

int main() {
    vector<vector<int>> matrix = {
        {1}
    };

    cout << uniquePathsWithObstacles(matrix) << endl;

    return 0;
}