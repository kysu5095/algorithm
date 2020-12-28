// D4 : 방향 전환

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int y3, x3, y2, x2;
bool visited[2][201][201];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs() {
	if (y2 == y3 && x2 == x3) return 0;
	queue<pair<bool, pair<int, int>>> q1, q2;
	q1.push(make_pair(true, make_pair(y3, x3)));
	q2.push(make_pair(true, make_pair(y3, x3)));
	visited[0][y3][x3] = true;
	visited[1][y3][x3] = true;
	int y, x, ny, nx, len, cnt = 1;
	bool flag;
	while (!q1.empty() || !q2.empty()) {
		len = q1.size();
		while (len--) {
			y = q1.front().second.first;
			x = q1.front().second.second;
			flag = q1.front().first;
			q1.pop();

			for (int i = 0; i < 4; i++) {
				if (flag && i >= 2) continue;
				if (!flag && i <= 1) continue;
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny > 200 || nx < 0 || nx > 200) continue;
				if (ny == y2 && nx == x2) return cnt;
				if (visited[0][ny][nx]) continue;
				visited[0][ny][nx] = true;
				q1.push(make_pair(!flag, make_pair(ny, nx)));
			}
		}

		len = q2.size();
		while (len--) {
			y = q2.front().second.first;
			x = q2.front().second.second;
			flag = q2.front().first;
			q2.pop();

			for (int i = 0; i < 4; i++) {
				if (flag && i <= 1) continue;
				if (!flag && i >= 2) continue;
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny > 200 || nx < 0 || nx > 200) continue;
				if (ny == y2 && nx == x2) return cnt;
				if (visited[1][ny][nx]) continue;
				visited[1][ny][nx] = true;
				q2.push(make_pair(!flag, make_pair(ny, nx)));
			}
		}
		cnt++;
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("sample_input.txt", "r", stdin);
	int test_case;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		memset(visited, false, sizeof(visited));
		cin >> x3 >> y3 >> x2 >> y2;
		x3 += 100, y3 += 100;
		x2 += 100, y2 += 100;
		cout << "#" << tc << " " << bfs() << '\n';
	}
	return 0;
}