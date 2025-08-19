#include <bits/stdc++.h>
using namespace std;

bool isReachable(string a, string b){
    int diff = 0;
    for(int i=0;i<8;i++){
        if(a[i] != b[i]){
            diff++;
        }
    }
    return diff == 1;
}

int minMutation(string startGene, string endGene, vector<string>& bank) {
    int n = bank.size(); 
    if(n==0)return -1;
    int endIdx = -1;
    for(int i=0;i<n;i++){
        if(bank[i] == endGene){
            endIdx = i;
            break;
        }
    }
    if(endIdx == -1)return -1;

    vector<vector<int>> graph(n+1);
    for(int i=0;i<bank.size();i++){
        if(isReachable(startGene, bank[i])){
            graph[n].push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(isReachable(bank[i],bank[j])){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    queue<int> q;
    bool flag = false;
    int minPath = INT_MAX;
    q.push(n);
    int size = 1;
    int ans = 0;
    vector<bool> visited(n+1);
    while(!q.empty()){
        for(int i=0;i<size;i++){
            int cur = q.front();
            q.pop();
            if(cur == endIdx)return ans;
            visited[cur] = true;
            for(auto i : graph[cur]){
                if(!visited[i]){
                    q.push(i);
                }
            }
        }
        ans++;
        size = q.size();
    }
    return -1;
}

int main() {
    string startGene = "AAAAAAAT";
    string endGene = "CCCCCCCT";
    vector<string> bank = {"AAAAAAAC","AAAAAAAA","CCCCCCCC"};
    int result = minMutation(startGene, endGene, bank);
    cout << result << endl;
    return 0;
}