#include <bits/stdc++.h>
#include <iterator>
using namespace std;

void deleteMax(vector<int>& count, unordered_set<int>& set) {
    int maxCount = 0;
    for (int i : set) {
        maxCount = max(maxCount, count[i]);
    }
    for (int i : set) {
        if (count[i] == maxCount) {
            count[i] = 0;
            set.erase(i);
        }
    }
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n,d;
        cin >> n >> d;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        cin.ignore();

        // int n = 4,d = 0;
        // vector<int> vec = {1, 1, 2, 5};

        sort(vec.begin(), vec.end());
        vector<int> count(n,0);
        vector<unordered_set<int>> similar;
        unordered_set<int> temp;
        for(int i = 0; i < vec.size(); i++) {
            // 检查是否有相似的观点
            if ((abs(vec[i+1] - vec[i]) <= d)) {
                count[i]++;
                count[i+1]++;
                temp.insert(i);
                temp.insert(i+1);
            }
            else{
                similar.push_back(temp);
                temp = unordered_set<int>();
            }
        }
        int num = 0;
        for(int i=0;i<similar.size();i++){
            unordered_set<int>* tempSet = &similar[i];
            // 检查一个 Set 中是否还有相似的观点，如果有的话就删除
            for (auto it = tempSet->begin(); it != tempSet->end(); ++it) {
                for (auto jt = next(it); jt != tempSet->end(); ++jt) {
                    if ((abs(vec[*it] - vec[*jt]) <= d)) {
                        deleteMax(count, *tempSet);
                        num++;
                    }
                }
            }
        }
        if(num%2 == 1)num++;
        cout << n - num << endl;
    }
    return 0;
}