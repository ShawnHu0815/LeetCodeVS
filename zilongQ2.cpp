#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> letters(n, vector<int>(2));
    for(int i=0;i<n;i++){
        cin >> letters[i][0] >> letters[i][1];
    }
    sort(letters.begin(), letters.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    });
    int ans = 1;
    int curMin0 = letters[0][0];
    int curMin1 = letters[0][1];
    for(int i=0;i<n;i++){
        if(letters[i][0] > curMin0 && letters[i][1] > curMin1){
            ans++;
            curMin0 = letters[i][0];
            curMin1 = letters[i][1];
        }
    }
    cout << ans << endl;

    return 0;
}