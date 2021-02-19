// 양파깡 만들기

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define INF 1000

using namespace std;

int n, m;
int arr[31][31];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

class Point {
public:
	int val, sy, sx, fy, fx;
};
vector<Point> v;

int cut(int& sy, int& sx, int& fy, int& fx, bool flag) {
	int y = sy, x = sx;
	int val = arr[y][x];
	int sequence[4] = { fx - sx, fy - sy, fx - sx, fy - sy };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < sequence[i]; j++) {
			y += dy[i];
			x += dx[i];
			if (arr[y][x] == INF) return -INT_MAX;
			if(flag) val += arr[y][x];
			else arr[y][x] = INF;
		}
	}
	val -= arr[sy][sx];
	return val;
}

bool find() {
	int ret = -INT_MAX;
	Point p;
	for (int sy = 1; sy <= n - 2; sy++) {
		for (int sx = 1; sx <= n - 2; sx++) {
			for (int fy = sy + 2; fy <= n; fy++) {
				for (int fx = sx + 2; fx <= n; fx++) {
					int val = cut(sy, sx, fy, fx, true);
					if (ret < val) {
						ret = val;
						p.val = val;
						p.sy = sy, p.sx = sx;
						p.fy = fy, p.fx = fx;
					}
				}
			}
		}
	}
	if (ret != -INT_MAX) {
		v.push_back(p);
		cut(p.sy, p.sx, p.fy, p.fx, false);
		return true;
	}
	else return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	while (m--) {
		if (!find()) {
			cout << "0\n";
			return 0;
		}
	}
	for (auto& p : v)
		cout << p.val << " " << p.sy << " " << p.sx << " " << p.fy << " " << p.fx << '\n';
	return 0;
}