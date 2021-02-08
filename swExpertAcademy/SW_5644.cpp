// 무선 충전

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

int m, a;
bool visited_a[101], visited_b[101];
int dy[5] = { 0, -1, 0, 1, 0 };
int dx[5] = { 0, 0, 1, 0, -1 };
vector<int> move_a, move_b;

class BC {
public:
	int y, x, c, p;
};
vector<BC> v;

int move() {
	int ay = 1, ax = 1;
	int by = 10, bx = 10;
	int total_sum = 0;
	for (int idx = 0; idx <= m; idx++) {
		memset(visited_a, false, sizeof(visited_a));
		memset(visited_b, false, sizeof(visited_b));
		for (int i = 0; i < v.size(); i++) {
			if (abs(ay - v[i].y) + abs(ax - v[i].x) <= v[i].c) visited_a[i] = true;
			if (abs(by - v[i].y) + abs(bx - v[i].x) <= v[i].c) visited_b[i] = true;
		}

		int max_sum = 0;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				if (visited_a[i] || visited_b[i]) {
					int tick_sum = 0;
					if (i == j) {
						tick_sum += v[i].p;
					}
					else {
						if (visited_a[i]) tick_sum += v[i].p;
						if (visited_b[j]) tick_sum += v[j].p;
					}
					max_sum = max(max_sum, tick_sum);
				}
			}
		}

		total_sum += max_sum;
		ay += dy[move_a[idx]]; ax += dx[move_a[idx]];
		by += dy[move_b[idx]]; bx += dx[move_b[idx]];
	}
	return total_sum;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> m >> a;
		move_a.clear(); move_b.clear();
		move_a.resize(m + 1); move_b.resize(m + 1);
		move_a[m] = 0; move_b[m] = 0;
		for (int i = 0; i < m; i++) cin >> move_a[i];
		for (int i = 0; i < m; i++) cin >> move_b[i];
		v.clear();
		v.resize(a);
		for (int i = 0; i < a; i++)
			cin >> v[i].x >> v[i].y >> v[i].c >> v[i].p;
		cout << "#" << tc << " " << move() << '\n';
	}
	return 0;
}