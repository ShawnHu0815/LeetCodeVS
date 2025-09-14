#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    int left = 1,right = n+1;
    long long minDiff = INT_MAX,ansL = -1,ansR = -1;
    long long leftSum = arr[left],rightSum = arr[right-1];
    while(left < right){
        long long diff = abs(leftSum - rightSum);
        if(diff < minDiff){
            minDiff = diff;
            ansL = left;
            ansR = right-1;
        }
        if(leftSum < rightSum){
            left++;
            leftSum += arr[left];
        } else {
            right--;
            rightSum += arr[right-1];
        }
    }
    cout << minDiff << " " << ansL << " " << ansR << endl;
    return 0;
}