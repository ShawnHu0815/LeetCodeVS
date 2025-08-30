#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> cost({{2,{1}},{3,{7}},{4,{4}},{5,{5,3,2}},{6,{9,6}},{7,{8}}});
vector<int> costVec({0,2,5,5,4,5,6,3,7,6});

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int m;
    cin >> m;
    int temp;
    vector<bool> available(10, false);
    int minCost = INT_MAX;
    int minCostIdx = -1;
    int maxCost = INT_MIN;
    int maxCostIdx = -1;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        available[temp] = true;
        if(costVec[temp] < minCost) {
            minCost = costVec[temp];
            minCostIdx = temp;
            cout << minCost << " " << minCostIdx << endl;
        }
        if(costVec[temp] > maxCost) {
            maxCost = costVec[temp];
            maxCostIdx = temp;
            cout << maxCost << " " << maxCostIdx << endl;
        }
    }
    string result = "";
    while(n > maxCost){
        n -= minCost;
        result += to_string(minCostIdx);
    }
    if(n > 0) {
        for(int i=0;i<cost[n].size();i++){
            if(available[cost[n][i]]){
                result += to_string(cost[n][i]);
                break;
            }
            
        }
    }
    cout << result << endl;
    return 0;
}