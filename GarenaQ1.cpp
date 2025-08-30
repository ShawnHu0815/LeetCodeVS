#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int ansCnt = 1;
    while(n--){
        int num1;
        cin >> num1;
        vector<int> list(num1);
        for(int i = 0; i < num1; i++) {
            cin >> list[i];
        }
        int num2;
        cin >> num2;
        list.resize(num1 + num2);
        for(int i = 0; i < num2; i++) {
            cin >> list[num1 + i];
        }
        sort(list.begin(), list.end(), greater<int>());
        cout << ansCnt++ << " ";
        for(int i = 0; i < list.size(); i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }

    return 0;
}