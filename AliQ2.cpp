#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> preSum(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        preSum[i] = (i == 0 ? vec[i] : preSum[i - 1] + vec[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int leftSum = 0;
        int rightSum = 0;
        for(int j = 0; j < i; j++) {
            leftSum += vec[j];
        }
        for(int j = i + 1; j < n; j++) {
            rightSum += vec[j];
        }
        if(leftSum == rightSum) {
            ans++;
            vec.erase(vec.begin() + i);
        }
        
    }
    cout << ans << endl;

    return 0;
}