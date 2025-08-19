#include <bits/stdc++.h>
using namespace std;

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        // int n;
        // cin >> n;
        // vector<int> arr1(n);
        // for(int i = 0; i < n; i++) {
        //     cin >> arr1[i];
        // }
        // vector<int> arr2(n);
        // for(int i = 0; i < n; i++) {
        //     cin >> arr2[i];
        // }

        int n = 4;
        vector<int> arr1 = {1, 2, 3, 4};
        vector<int> arr2 = {1, 2, 5, 6};

        vector<bool> match(n, false);
        if(arr1[0] == arr2[0]) {
            match[0] = true;
        }
        for(int i = 1; i < arr1.size(); i++) {
            if(arr1[i] == arr2[i]) {
                match[i] = true;
                match[i-1] = true;
            }else if(arr1[i] == arr1[i-1]){
                match[i-1] = true;
            }else if(arr2[i] == arr2[i-1]){
                match[i-1] = true;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(match[i]) {
                ans++;
            }
        }
        if (n >= 3) {
            for (int i = 0; i < arr1.size() - 2; i++) {
                if(arr1[i] == arr1[i+2] && match[i+1] == false){
                    ans++;
                    break;
                }else if(arr2[i] == arr2[i+2] && match[i+1] == false){
                    ans++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}
// 64 位输出请用 printf("%lld")