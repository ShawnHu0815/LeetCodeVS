#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    while(n != 0){
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int curMin = INT_MAX;
        int flag = true;
        for(int i = 0; i < n; i++) {
            curMin = min(curMin, v[i]);
            if(v[i] > 2 * curMin-1) {
                flag = false;
                break;
            }
        }
        cout << flag << endl;
        cin >> n;
    }
    return 0;
}