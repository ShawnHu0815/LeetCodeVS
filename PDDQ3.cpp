#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int n = s.size();
        int count0 = 0, count1 = 0;
        int maxCount = 0;
        vector<int> maxCounts(n, 0);
        for(int i=0;i<n;i++){
            if(s[i] == '0') count0++;
            else count1++;
            maxCount = max(count0, count1);
            maxCounts[i] = maxCount;
        }
        if(maxCounts[n-1] == n/2){
            cout << "0" << endl;
        }else{
            for(int i=0;i<n;i++){
                if(maxCounts[n-1-i] == n - maxCount){
                    cout << i << endl;
                    break;
                }
                if(i == n-1){
                    cout << n << endl;
                }
            }
        }
    }
    return 0;
}