#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, m, L;
    cin >> n >> m >> L;
    vector<int> gains(n);
    for (int i = 0; i < n; i++) {
        cin >> gains[i];
    }
    if(m <= n){
        int maxGain = 0;
        int maxIndex = 0;
        for(int i=0;i<m;i++){
            if(gains[i] > maxGain){
                maxGain = gains[i];
                maxIndex = i;
            }
        }
        cout << maxIndex+1 << endl;
    }else{
        vector<long long> totalGains(m, 0);
        int oneCycle = lcm(n, m);
        int fullCycles = L / oneCycle;
        int remainingSteps = L % oneCycle;
        int offset = 0;
        if(fullCycles > 0){
            for (int i = 0; i < oneCycle; i++) {
                for (int j = 0; j < n; j++) {
                    totalGains[(j + offset) % m] += gains[j];
                }
                offset += m - n + 1;
                offset = (offset % m + m) % m;
                }
                for(int i=0;i<m;i++){
                    totalGains[i] *= fullCycles;
            }
        }
        offset = 0;
        for (int i = 0; i < remainingSteps; i++) {
            for(int j=0;j<n;j++){
                totalGains[(j + offset) % m] += gains[j];
            }
            offset += n;
            offset = (offset % m + m) % m;
        }
        long long maxGain = 0;
        int maxIndex = 0;
        for (int i = 0; i < m; i++) {
            if (totalGains[i] > maxGain) {
                maxGain = totalGains[i];
                maxIndex = i;
            }
        }
        cout << maxIndex + 1 << endl;
    }
    return 0;
}