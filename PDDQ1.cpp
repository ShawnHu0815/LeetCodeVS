#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string map(n, ' ');
        int playerPos = -1;
        for(int i=0;i<n;i++){
            char c;
            cin >> c;
            if(c == 'D'){
                map[i] = '.';
                playerPos = i;
            }else{
                map[i] = c;
            }   
        }
        bool bCross = false;
        bool bEscape = false;
        int cur = playerPos;
        // 向右逃跑
        while(cur < n){
            while(cur<n && map[cur] == '.'){
                if((cur>1 && map[cur-1] == '.') || (cur<n-1 && map[cur+1] == '.')){
                    bCross = true;
                }
                cur++;
            }
            if(bCross){
                while(cur<n && map[cur] == '.'){
                    cur++;
                }
                while(cur<n && map[cur] == '#'){
                    cur++;
                }
                if(cur == n){
                    bEscape = true;
                    break;
                }
                bCross = false;
            }else{
                if(cur > n-1) bEscape = true;
                break;
            }
        }
        // 向左逃跑
        cur = playerPos;
        bCross = false;
        while(cur >= 0){
            while(cur>=0 && map[cur] == '.'){
                if((cur>1 && map[cur-1] == '.') || (cur<n-1 && map[cur+1] == '.')){
                    bCross = true;
                }
                cur--;
            }
            if(bCross){
                while(cur>=0 && map[cur] == '.'){
                    cur--;
                }
                while(cur>=0 && map[cur] == '#'){
                    cur--;
                }
                if(cur < 0){
                    bEscape = true;
                    break;
                }
                bCross = false;
            }else{
                if(cur < 0) bEscape = true;
                break;
            }
        }
        if(bEscape){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}