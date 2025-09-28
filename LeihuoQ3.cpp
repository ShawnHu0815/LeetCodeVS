#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> functionIDs(n);
    vector<string> functionNames(n);
    vector<string> functionParams(n);
    for (int i = 0; i < n; i++) {
        cin >> functionIDs[i];
        cin >> functionNames[i];
        cin >> functionParams[i];
    }
    string hexString;
    cin >> hexString;
    int curIndex = 0;
    while (curIndex < hexString.size()) {
        int funcID = stoi(hexString.substr(curIndex, 2), nullptr, 16);
        curIndex += 2;
        string funcName = functionNames[funcID];
        cout << funcName << "(";
        string funcParam = functionParams[funcID];
        vector<int> stringLengths;
        if(funcParam.find('s') != string::npos){
            int totalStringCount = count(funcParam.begin(), funcParam.end(), 's');
            for(int i=0;i<totalStringCount;i++){
                int len = stoi(hexString.substr(curIndex, 2), nullptr, 16);
                curIndex += 2;
                stringLengths.push_back(len);
            }
        }
        for(int i=0;i<funcParam.size();i++){
            if(funcParam[i] == 'i'){
                string paramString = hexString.substr(curIndex, 8);
                int param = (int)strtol(paramString.c_str(), nullptr, 16);
                curIndex += 8;
                cout << param;
                if(i != funcParam.size() - 1)cout << ",";
            } else if(funcParam[i] == 's'){
                int len = stringLengths.front();
                stringLengths.erase(stringLengths.begin());
                string paramString = hexString.substr(curIndex, len * 2);
                curIndex += len * 2;
                cout << "\"" << paramString << "\"";
                if(i != funcParam.size() - 1)cout << ",";
            }
        }
        cout << ")" << endl;
    }
    return 0;
}