#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x;
	int y;
	Point(int xx, int yy) : x(xx), y(yy) {}
};

vector<vector<int> > query(vector<vector<Point>>& walls, vector<Point>& players, vector<vector<Point> >& monsters) {
    vector<vector<int>> lines;
    for(int i=0;i<walls.size();i++){
        vector<int> line(3);
        // ax + by + c = 0
        line[0] = walls[i][1].y - walls[i][0].y;
        line[1] = walls[i][0].x - walls[i][1].x;
        line[2] = walls[i][1].x * walls[i][0].y - walls[i][0].x * walls[i][1].y;
        lines.push_back(line);
    }
}

int main() {
    // [     [(48, 5), (-91, -63)],      [(1, 84), (-22, 43)] ],[     (52, -3),      (49, -5),      (-25, -24),      (-25, -34),      (-45, -8) ],[     [(-51, -18), (-353, 488)],      [(18, -74), (595, 985)],      [(5, 46), (562, -300)],      [(-70, 96), (-681, 700)],      [(39, -82), (-544, -602)] ]
    vector<vector<Point>> walls = {
        {Point(48, 5), Point(-91, -63)},
        {Point(1, 84), Point(-22, 43)}
    };
    vector<Point> players = {
        Point(52, -3),
        Point(49, -5),
        Point(-25, -24),
        Point(-25, -34),
        Point(-45, -8)
    };
    vector<vector<Point>> monsters = {
        {Point(-51, -18), Point(-353, 488)},
        {Point(18, -74), Point(595, 985)},
        {Point(5, 46), Point(562, -300)},
        {Point(-70, 96), Point(-681, 700)},
        {Point(39, -82), Point(-544, -602)}
    };
    return 0;
}