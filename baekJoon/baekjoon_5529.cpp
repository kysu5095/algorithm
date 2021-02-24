// 저택

#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <math.h>
#define ll long long

using namespace std;

int n, m, k;
vector<vector<int>> x_axis;
vector<vector<int>> y_axis;
class Point {
public:
	int y, x;
	ll t = LLONG_MAX;
};
vector<Point> v;

ll bfs(int first, int last) {
	queue<pair<int, bool>> q;
	for (auto& p : x_axis[1]) {
		if (v[p].y == 1) continue;
		q.push(make_pair(p, false));
		v[p].t = v[p].y;
	}
	if (first) {
		for (auto& p : y_axis[1]) {
			if (v[p].x == 1) continue;
			q.push(make_pair(p, true));
			v[p].t = v[p].x + 1;
		}
	}

	int node, y, x;
	ll t, nt;
	bool flag;
	while (!q.empty()) {
		node = q.front().first;
		flag = q.front().second;
		q.pop();

		y = v[node].y;
		x = v[node].x;
		t = v[node].t;
		if (flag) {
			for (auto& p : x_axis[x]) {
				if (v[p].y == y) continue;
				nt = t + abs(v[p].y - y) + 1;
				if (x == m && v[p].y == n) nt--;
				if (v[p].t <= nt) continue;
				q.push(make_pair(p, false));
				v[p].t = nt;
			}
		}
		else {
			for (auto& p : y_axis[y]) {
				if (v[p].x == x) continue;
				nt = t + abs(v[p].x - x) + 1;
				if (y == n && v[p].x == m) nt--;
				if (v[p].t <= nt) continue;
				q.push(make_pair(p, true));
				v[p].t = nt;
			}
		}
	}
	if (v[last].t == LLONG_MAX) return -1;
	return v[last].t;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int y, x, first = 0, last = 0;
	cin >> m >> n >> k;
	x_axis.resize(m + 1);
	y_axis.resize(n + 1);
	v.resize(k + 2);
	for (int i = 1; i <= k; i++) {
		cin >> x >> y;
		x_axis[x].push_back(i);
		y_axis[y].push_back(i);
		v[i] = { y, x, LLONG_MAX };
		if (x == 1 && y == 1) {
			first = i;
			v[i].t = 0;
		}
		if (x == m && y == n) {
			last = i;
		}
	}
	if (!last) {
		last = k + 1;
		x_axis[m].push_back(k + 1);
		y_axis[n].push_back(k + 1);
		v[k + 1] = { n, m, LLONG_MAX };
	}
	cout << bfs(first, last) << '\n';
	return 0;
}