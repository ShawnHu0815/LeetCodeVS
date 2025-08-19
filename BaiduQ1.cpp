#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--){
        int l,r;
        cin >> l >> r;
        l = l-1;
        int countR = (r/3)*2 + r%3;
        int countL = (l/3)*2 + l%3;
        cout << countR - countL << endl;
    }
}
// 64 位输出请用 printf("%lld")