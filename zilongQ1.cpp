#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int len;
    cin >> len;
    int n = s.length();
    double ratio = 0;
    string ans = "";
    for(int i=0;i+len < n;i++){
        string sub = s.substr(i,len);
        int count  = 0;
        for(int j=0;j<len;j++){
            if(sub[j] == 'G' || sub[j] == 'C'){
                count++;
            }
        }
        double curRatio = (double)count / len;
        if(curRatio > ratio){
            ratio = curRatio;
            ans = sub;
        }
    }
    cout << ans << endl;
    return 0;
}