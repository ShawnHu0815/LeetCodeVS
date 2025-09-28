#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<long long> sum(1000005, 0);
    vector<int> startTime(n);
    vector<int> value(n);
    for (int i = 0; i < n; i++) {
        cin >> startTime[i] >> value[i];
    }
    long long ans = -1;
    for(int i=0;i<n;i++){
        for(int j=startTime[i];j<=m;j++){
            sum[j]+=value[i];
            ans = max(ans, sum[j]);
        }
    }
    cout << ans << endl;
    return 0;
}