// 배열 돌리기 4
// 5:20

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int n, m, k, res = INT_MAX;
int arr[51][51];
int t_arr[51][51];

class Point {
public:
	int y, x, s;
};
Point p[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
vector<Point> turn;
int seq[7] = { 0, };

void print() {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

void copy_arr() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = t_arr[i][j];
}

void cal() {
	int m_val = INT_MAX;
	int cnt;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < m; j++) 
			cnt += arr[i][j];
		m_val = m_val > cnt ? cnt : m_val;
	}
	res = res > m_val ? m_val : res;
}

void turn_array() {
	int y, x, s, sy, sx, ny, nx, d, idx, val, nval;
	for (int i = 0; i < k; i++) {
		y = turn[seq[i] - 1].y;
		x = turn[seq[i] - 1].x;
		s = turn[seq[i] - 1].s;
		sy = y - s;
		sx = x - s;
		ny = sy;
		nx = sx;
		idx = 0;
		d = 0;
		nval = arr[ny][nx];
		while (s) {
			val = nval;
			idx++;
			if (idx > (s << 1)) {
				idx &= 1;
				d += 1;
				if (d > 3) d = 0;
			}
			ny += p[d].y;
			nx += p[d].x;
			nval = arr[ny][nx];
			arr[ny][nx] = val;

			if (ny == sy && nx == sx) {
				s--;
				sy = y - s;
				sx = x - s;
				ny = sy;
				nx = sx;
				idx = 0;
				d = 0;
				nval = arr[ny][nx];
			}
		}
	}
	cal();
}

void dfs(int cnt) {
	if (cnt == k + 1) {
		copy_arr();
		turn_array();
		return;
	}
	for (int i = 0; i < k; i++) {
		if (!seq[i]) {
			seq[i] = cnt;
			dfs(cnt + 1);
			seq[i] &= 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int y, x, s;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			t_arr[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> y >> x >> s;
		turn.push_back({ y - 1, x - 1, s });
	}
	dfs(1);
	cout << res << '\n';
	return 0;
}