#include <bits/stdc++.h>
using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        int block = isLeaf(grid, 0, 0, n - 1, n - 1);
        if(block == -1)return Help(grid,0,0,n-1,n-1);
        else return new Node(block, true);
    }

    Node* Help(vector<vector<int>>& grid,int x1, int y1, int x2, int y2){
        int midX = x1 + (x2 - x1) / 2;
        int midY = y1 + (y2 - y1) / 2;

        int block1 = isLeaf(grid,x1,y1,midX,midY);
        Node* topLeft;
        if(block1 == -1){
            topLeft = Help(grid,x1,y1,midX,midY);
        }else{
            topLeft = new Node(block1,true);
        }
        
        Node* topRight;
        int block2 = isLeaf(grid,x1,midY+1,midX,y2);
        if(block2 == -1){
            topRight = Help(grid,x1,midY+1,midX,y2);
        }else{
            topRight = new Node(block2,true);
        }

        Node* bottomLeft;
        int block3 = isLeaf(grid,midX+1,y1,x2,midY);
        if(block3 == -1){
            bottomLeft = Help(grid,midX+1,y1,x2,midY);
        }else{
            bottomLeft = new Node(block3,true);
        }

        Node* bottomRight;
        int block4 = isLeaf(grid,midX+1,midY+1,x2,y2);
        if(block4 == -1){
            bottomRight = Help(grid,midX+1,midY+1,x2,y2);
        }else{
            bottomRight = new Node(block4,true);
        }

        return new Node(1,false,topLeft,topRight,bottomLeft,bottomRight);
    }
    
    int isLeaf(vector<vector<int>>& grid,int x1, int y1, int x2, int y2){
        int sum = 0;
        int full = (x2-x1+1) * (y2-y1+1);
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                sum += grid[i][j];
            }
        }
        if(sum == 0)return 0;
        else if(sum == full)return 1;
        else return -1;
    }
};

// 辅助函数：按层序遍历输出四叉树（LeetCode标准格式，去掉末尾的null）
void printQuadTree(Node* root) {
    if (!root) {
        cout << "[]" << endl;
        return;
    }
    
    vector<string> result;
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        
        if (node == nullptr) {
            result.push_back("null");
        } else {
            result.push_back("[" + to_string(node->isLeaf ? 1 : 0) + "," + to_string(node->val ? 1 : 0) + "]");
            
            if (!node->isLeaf) {
                // 非叶子节点加入实际的子节点
                q.push(node->topLeft);
                q.push(node->topRight);
                q.push(node->bottomLeft);
                q.push(node->bottomRight);
            } else {
                // 叶子节点的4个子节点都是null，但只在需要时添加
                // 检查队列中是否还有非null节点，如果有才添加null
                bool hasMoreNodes = false;
                queue<Node*> temp = q;
                while (!temp.empty()) {
                    if (temp.front() != nullptr) {
                        hasMoreNodes = true;
                        break;
                    }
                    temp.pop();
                }
                
                if (hasMoreNodes) {
                    q.push(nullptr);
                    q.push(nullptr);
                    q.push(nullptr);
                    q.push(nullptr);
                }
            }
        }
    }
    
    // 去掉末尾的null
    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }
    
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // 测试样例
    vector<vector<int>> grid = {
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0}
    };
    
    cout << "Input grid:" << endl;
    for (auto& row : grid) {
        cout << "[";
        for (int i = 0; i < row.size(); i++) {
            cout << row[i];
            if (i < row.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    Node* result = solution.construct(grid);
    
    cout << "\nQuadTree output:" << endl;
    printQuadTree(result);
    
    cout << "\nExpected output:" << endl;
    cout << "[[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]" << endl;
    
    return 0;
}