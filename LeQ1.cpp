#include <bits/stdc++.h>
using namespace std;

vector<int> rangeAnimal(int* animal, int animalLen) {
    int wrong1 = -1;
    int wrong2 = -1;
    int cur = 0;
    while(cur < animalLen){
        bool flag1 = false;
        bool flag2 = false;
        while(cur < animalLen && (!flag1 || !flag2)){
            if(cur % 2 == 0 && animal[cur]== 2){
                wrong2 = cur;
                flag2 = true;
            }
            if(cur %2 == 1 && animal[cur]== 1){
                wrong1 = cur;
                flag1 = true;
            }
            cur++;
        }
        if(flag1 && flag2){
            swap(animal[wrong1],animal[wrong2]);
        }
    }
    vector<int> ans(animalLen);
    for(int i=0;i<animalLen;i++){
        ans[i] = animal[i];
    }
    return ans;
}

int main() {
    int animal[] = {1,1,2,2,1,2,1,2,1};
    int animalLen = sizeof(animal)/sizeof(animal[0]);
    vector<int> ans = rangeAnimal(animal, animalLen);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}