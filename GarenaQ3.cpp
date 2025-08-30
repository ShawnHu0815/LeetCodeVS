#include <bits/stdc++.h>
using namespace std;

// 前缀树
class Tree{
private:
    vector<Tree*> child;
    bool bIsEnd;
    int count;
public:
    Tree(){
        this->bIsEnd = false;
        this->child = vector<Tree*>(26, nullptr);
    }
    void insert(const string& word){
        Tree* cur = this;
        for(auto c : word){
            int idx = c - 'a';
            if(cur->child[idx] == nullptr){
                cur->child[idx] = new Tree();
            }
            cur = cur->child[idx];
        }
        cur->bIsEnd = true;
    };
    Tree* searchWord(const string& word){
        Tree* cur = this;
        for(auto c : word){
            int idx = c - 'a';
            if(cur->child[idx] == nullptr){
                return nullptr;
            }
            cur = cur->child[idx];
        }
        return cur;
    }
    int searchAndCount(const string& word){
        this->count = 0;
        Tree* cur = searchWord(word);
        if(cur != nullptr){
            this->count = dfs(cur);
        }
        return this->count;
    }
    int dfs(Tree* node){
        if(node == nullptr) return 0;
        int ans = node->bIsEnd ? 1 : 0;
        for(auto child : node->child){
            ans += dfs(child);
        }
        return ans;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    string input;
    Tree* tree = new Tree();
    while(n--){
        cin >> input;
        tree->insert(input);
    }
    string require;
    while(m--){
        cin >> require;
        if(tree->searchWord(require) != nullptr){
            int count = tree->searchAndCount(require);
            cout << count << endl;
        } else {
            tree->insert(require);
        }
    }
    return 0;
}