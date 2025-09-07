#include <bits/stdc++.h>
using namespace std;

long long findMinDisappear(vector<long long>& vec){
    sort(vec.begin(), vec.end());
    for(int i=0;i<vec.size();i++){
        if(vec[i]!=i) return i;
    }
    return vec.size();
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n,k,x;
        cin >> n >> k >> x;
        vector<long long> vec(n);
        for(int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        vector<long long> disappear(n+1, 0);
        unordered_set<long long> elem;
        int cur = 0;
        for(int i=n-1;i>=0;i--){
            elem.insert(vec[i]);
            while(elem.count(cur)){
                cur++;
            }
            disappear[i] = cur;
        }
        long long cost = LLONG_MAX;
        for(int i=0;i<n;i++){
            long long cur = x*i + k*disappear[i];
            cost = min(cost, cur);
        }
        cost = min(cost, (long long)x*n);
        cout << cost << endl;
    }
    return 0;
}