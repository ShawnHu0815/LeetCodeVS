#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<long long> diff(1005, 0);
    vector<int> startTime(n);
    vector<int> value(n);
    for (int i = 0; i < n; i++) {
        cin >> startTime[i] >> value[i];
    }
    for(int i=0;i<n;i++){
        diff[startTime[i]]+=value[i];
        diff[startTime[i]+m]-=value[i];
    }
    long long ans = -1;
    vector<long long> sum(1006,0);
    for(int i=1;i<1005;i++){
        sum[i]=sum[i-1]+diff[i];
        ans = max(ans, sum[i]);
    }
    cout << ans << endl;
    return 0;
}