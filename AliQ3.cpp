#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    vector<bool> valid(n,false);
    for(int i=0;i<n;i++) {
        cin>>vec[i];
        if(i > 0 && abs(vec[i] - vec[i-1]) <= k){
            valid[i] = true;
        }
    }
    int ans = INT_MIN;
    vector<int> ansVec;
    for(int i=0;i<n;i++){
        for(int len=2;len+i<=n;len++){
            bool flag = true;
            vector<int> subvec(vec.begin()+i,vec.begin()+i+len);
            vector<bool> subvalid(valid.begin()+i,valid.begin()+i+len);
            int sum = 0;
            for(int j=0;j<subvec.size();j++){
                sum += subvec[j];
            }
            if(sum %2 == 1){
                flag = false;
            }
            for(int j=1;j<subvec.size();j++){
                if(!subvalid[j]){
                    flag = false;
                    break;
                }
            }
            if(len > ans && flag){
                ansVec = subvec;
                ans = len;
            }
        }
    }
    if(ans == INT_MIN)
        cout << 0 << endl;
    else
        cout << ans << endl;

    for(int i=0;i<ansVec.size();i++){
        cout << ansVec[i] << " ";
    }
    return 0;
}