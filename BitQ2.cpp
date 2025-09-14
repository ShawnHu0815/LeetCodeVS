#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int ans = 0;
    deque<pair<int,int>> dq;
    while (n--){
        int l,r;
        cin >> l >> r;
        pair<int,int> p = {l,r};
        if(dq.empty() || dq.front().first > r){
            dq.push_front(p);
            ans++;
        } else{
            int i=0;
            int n = dq.size();
            int flag = false;
            while(i<n){
                if(i+1 < n && dq[i].second < l && dq[i+1].first > r){
                    dq.insert(dq.begin()+i+1, p);
                    ans++;
                    flag = true;
                    break;
                }
                i++;
            }
            if(!flag && dq.back().second < l){
                dq.push_back(p);
                ans++;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}