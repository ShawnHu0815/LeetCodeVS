#include <bits/stdc++.h>
using namespace std;

void backtrack(const vector<vector<long long>>& costs, const vector<vector<long long>>& performances, int idx, long long costSum, long long performanceSum, long long x, long long n, long long& maxPerformance) {
    if (idx == n) {
        if (costSum <= x) {
            maxPerformance = max(maxPerformance, performanceSum);
        }
        return;
    }
    for (int i = 0; i < costs[idx].size(); i++) {
        backtrack(costs, performances, idx + 1, costSum + costs[idx][i], performanceSum + performances[idx][i], x, n, maxPerformance);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    long long n,x;
    cin >> n >> x;
    vector<vector<long long>> costs;
    vector<vector<long long>> performances;
    int temp = n;
    while (temp--)
    {
        int num;
        cin >> num;
        vector<long long> cost(num);
        vector<long long> performance(num);
        for (int i = 0; i < num; i++) {
            cin >> cost[i];
        }
        for (int i = 0; i < num; i++) {
            cin >> performance[i];
        }
        costs.push_back(cost);
        performances.push_back(performance);
    }
    long long maxPerformance = 0;
    backtrack(costs, performances, 0, 0, 0, x, n, maxPerformance);
    cout << maxPerformance << endl;
    return 0;
}