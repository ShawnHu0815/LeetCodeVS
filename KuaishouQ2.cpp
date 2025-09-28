#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    auto comp = [](const vector<long long>& a, const vector<long long>& b) {
        if (a[0] == b[0])return a[1] < b[1];
        return a[0] > b[0];
    };
    priority_queue<vector<long long>, vector<vector<long long>>, decltype(comp)> bottles(comp);
    for (int i = 0; i < n; i++) {
        vector<long long> bottle(2);
        cin >> bottle[0] >> bottle[1];
        bottles.push(bottle);
    }
    long long curV = 0;
    long long maxV = -1;
    long long leftV = 0;
    while (!bottles.empty())
    {
        if(leftV < bottles.top()[0]){
            curV += bottles.top()[0] - leftV;
            leftV += bottles.top()[0] - leftV;
            maxV = max(maxV, curV);
        }
        leftV += bottles.top()[1] - bottles.top()[0];
        bottles.pop();
    }
    cout << maxV << endl;
    return 0;
}