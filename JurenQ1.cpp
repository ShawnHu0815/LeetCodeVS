#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;
    Point(int xx, int yy) : x(xx), y(yy) {}
};

int maxRectArea(vector<Point>& rects) {
    auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> areas(
                comp);
    for (int i = 0; i < rects.size(); i++) {
        areas.push({rects[i].x* rects[i].y, i});
    }
    vector<vector<bool>> covered(1024, vector<bool>(1024, false));
    int maxArea = 0;
    int curArea = 0;
    while (!areas.empty()) {
        auto [area, idx] = areas.top();
        areas.pop();
        if (rects[idx].x <= 1024 && rects[idx].y <= 1024) {
            for (int i = 0; i < 1024; i++) {
                for (int j = 0; j < 1024; j++) {
                    if (i + rects[idx].x <= 1024 && j + rects[idx].y <= 1024 && !covered[i][j] &&
                            !covered[i + rects[idx].x - 1][j] && !covered[i][j + rects[idx].y - 1] &&
                            !covered[i + rects[idx].x - 1][j + rects[idx].y - 1]) {
                        for (int x = i; x < i + rects[idx].x; x++) {
                            for (int y = j; y < j + rects[idx].y; y++) {
                                covered[x][y] = true;
                            }
                        }
                        curArea += area;
                        break;
                    }
                }
            }
        }
    }
    maxArea = max(maxArea, curArea);
    curArea = 0;
    for (int i = 0; i < rects.size(); i++) {
        areas.push({rects[i].x* rects[i].y, i});
    }
    vector<vector<bool>> covered2(1024, vector<bool>(1024, false));
    areas.pop(); // 直接去掉最大的
    while (!areas.empty()) {
        auto [area, idx] = areas.top();
        areas.pop();
        if (rects[idx].x <= 1024 && rects[idx].y <= 1024) {
            for (int i = 0; i < 1024; i++) {
                for (int j = 0; j < 1024; j++) {
                    if (i + rects[idx].x <= 1024 && j + rects[idx].y <= 1024 && !covered2[i][j] &&
                            !covered2[i + rects[idx].x - 1][j] && !covered2[i][j + rects[idx].y - 1] &&
                            !covered2[i + rects[idx].x - 1][j + rects[idx].y - 1]) {
                        for (int x = i; x < i + rects[idx].x; x++) {
                            for (int y = j; y < j + rects[idx].y; y++) {
                                covered2[x][y] = true;
                            }
                        }
                        curArea += area;
                        break;
                    }
                }
            }
        }
    }
    maxArea = max(maxArea, curArea);
    return maxArea;

}


int main() {
    // freopen("input.txt", "r", stdin);
    // vector<Point> rects1 = {Point(700, 700), Point(500, 500), Point(400, 400), Point(10, 300)};
    // int maxArea = maxRectArea(rects1);
    // cout << "Max Rectangle Area: " << maxArea << endl;
    // vector<Point> rects2 = {Point(1000, 1000), Point(24, 1000), Point(1000, 24), Point(24, 24)};
    // maxArea = maxRectArea(rects2);
    // cout << "Max Rectangle Area: " << maxArea << endl;
    // cout << 1024 * 1024 << endl;
    vector<Point> rects3 = {Point(1000,1000), Point(512,512), Point(512,512), Point(512,512), Point(512,512), Point(512,512)};
    int maxArea = maxRectArea(rects3);
    cout << "Max Rectangle Area: " << maxArea << endl;
    return 0;
}