#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        vector<int> freq(3, 0);
        for (char c : s) {
            if(c == 'A')freq[0]++;
            else if(c == 'L')freq[1]++;
            else if(c == 'I')freq[2]++;
        }
        if(freq[0] == 0 && freq[1] == 0 && freq[2] == 0) {
            cout << "-1" << endl;
            continue;
        }
        while(freq[0] > 0 || freq[1] > 0 || freq[2] > 0) {
            if(freq[0] > 0) {
                cout << 'A';
                freq[0]--;
            }
            if(freq[1] > 0) {
                cout << 'L';
                freq[1]--;
            }
            if(freq[2] > 0) {
                cout << 'I';
                freq[2]--;
            }
        }
        cout << endl;
    }

    return 0;
}