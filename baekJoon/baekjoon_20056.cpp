// 마법사 상어와 파이어볼

#include <iostream>
#include <deque>

using namespace std;

int n, input, cnt;
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
class Point {
public:
	int m, s, d; // m:질량, s:속력, d:방향
};
deque<Point> dq[51][51];
deque<Point> tmp[51][51];

void move() {
	int r, c, m, s, d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (auto p : dq[i][j]) {
				r = i + n, c = j + n;
				m = p.m, s = p.s, d = p.d;
				r = r + (dy[d] * (s % n));
				c = c + (dx[d] * (s % n));
				r %= n;
				c %= n;
				tmp[r][c].push_back({ m, s, d });
			}
			dq[i][j].clear();
		}
	}
}

void devide() {
	int m, s, d, len;
	bool odd, even;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp[i][j].empty()) continue;
			if (tmp[i][j].size() == 1) dq[i][j].push_back(tmp[i][j][0]);
			else {
				m = s = d = 0;
				odd = even = false;
				for (auto p : tmp[i][j]) {
					m += p.m;
					s += p.s;
					if (p.d % 2 == 0) even = true;
					else odd = true;
				}
				m /= 5;
				if (m) {
					s /= (int)tmp[i][j].size();
					if (odd && even) d = 1;
					else d = 0;
					for (int k = d; k < 8; k += 2)
						dq[i][j].push_back({ m, s, k });
				}
			}
			tmp[i][j].clear();
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int r, c, m, s, d;
	cin >> n >> input >> cnt;
	for (int i = 0; i < input; i++) {
		cin >> r >> c >> m >> s >> d;
		dq[r - 1][c - 1].push_back({ m, s, d });
	}
	while (cnt--) {
		move();
		devide();
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (auto p : dq[i][j])
				res += p.m;
	cout << res << '\n';
	return 0;
}