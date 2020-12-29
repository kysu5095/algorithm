// 바나나킥을 잡아라!

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n, m, m2, x;
class Point {
public:
	int y, x, d;
	bool operator < (const Point& p) const {
		if (y < p.y) return true;
		else if (y == p.y) {
			if (x < p.x) return true;
			else return false;
		}
		else return false;
	}
};
vector<Point> v;
map<int, pair<int, int>> banana;
class Compare {
public:
	int cnt, sec;
	bool operator < (const Compare& c) const {
		if (cnt > c.cnt) return true;
		else if (cnt == c.cnt) {
			if (sec < c.sec) return true;
			else return false;
		}
		else return false;
	}
};
vector<Compare> c;
priority_queue<Compare> pq;

void get_colum(int& col, int sec, int& d) {
	sec %= m2;
	while (true) {
		if (d > 0) {
			if (m - col >= sec) {
				col += sec;
				break;
			}
			else {
				sec -= (m - col + 1);
				col = m;
				d = -1;
			}
		}
		else {
			if (col - sec >= 1) {
				col -= sec;
				break;
			}
			else {
				sec -= col;
				col = 1;
				d = 1;
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int row, col, d, cnt;
	cin >> n >> m >> x;
	m2 = (m << 1);
	for (int i = 0; i < x; i++) {
		cin >> row >> col >> d;
		v.push_back({ row, col, d });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < x; i++) {
		row = v[i].y;
		col = v[i].x;
		d = v[i].d;
		get_colum(col, row - 1, d);
		if (banana.find(col) != banana.end()) {
			cnt = banana[col].second;
			banana[col] = make_pair(row - 1, cnt + 1);
		}
		else banana[col] = make_pair(row - 1, 1);
	}
	map<int, pair<int, int>>::iterator iter;
	for (iter = banana.begin(); iter != banana.end(); iter++)
		c.push_back({ iter->second.second, iter->second.first });
//		pq.push({ -iter->second.second, -iter->second.first });
	sort(c.begin(), c.end());
	cout << c[0].cnt << " " << c[0].sec << '\n';
//	cout << -pq.top().cnt << " " << -pq.top().sec << '\n';
	return 0;
}