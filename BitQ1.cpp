#include <bits/stdc++.h>
using namespace std;

bool check(string s){
    int len = s.size();
    stack<char> stk;
    for(auto c : s){
        if(c == 'a'){
            stk.push(c);
        } else if(c == 'b'){
            if(stk.empty() || stk.top() != 'a') return false;
            stk.pop();
        } else {
            return false;
        }
    }
    return stk.empty();
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string s;
    while(n--){
        cin >> s;
        bool isValid = check(s);
        cout << (isValid ? "YES" : "NO") << endl;
    }
    
    return 0;
}