// 통나무 옮기기

#include <iostream>
#include <queue>

using namespace std;

int n;
char arr[51][51];
bool visited[2][51][51] = { { {false, }, }, };
int dy[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dx[8] = { 1, -1, 0, 0, -1, 1, 1, -1 };

bool isRight(int y, int x, int& d) {
	if (visited[d][y][x]) return false;
	if (!d) {
		x--;
		for (int i = 0; i < 3; i++) {
			if (y < 0 || y == n || x < 0 || x == n || arr[y][x] == '1') return false;
			x++;
		}
	}
	else {
		y--;
		for (int i = 0; i < 3; i++) {
			if (y < 0 || y == n || x < 0 || x == n || arr[y][x] == '1') return false;
			y++;
		}
	}
	return true;
}

int bfs(pair<int, int>& B_pair, int& B_d, int& E_d) {
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(B_d, make_pair(B_pair.first, B_pair.second)));
	visited[B_d][B_pair.first][B_pair.second] = true;

	int y, x, ny, nx, d, len, t = 0;
	bool flag;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().second.first;
			x = q.front().second.second;
			d = q.front().first;
			q.pop();
			if (arr[y][x] == 'E' && d == E_d) return t;
			
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (!isRight(ny, nx, d)) continue;
				q.push(make_pair(d, make_pair(ny, nx)));
				visited[d][ny][nx] = true;
			}

			if (visited[d ^ 1][y][x]) continue;
			flag = true;
			for (int i = 0; i < 8; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == n || arr[ny][nx] == '1') {
					flag = false;
					break;
				}
			}
			if (!flag) continue;
			q.push(make_pair(d ^ 1, make_pair(y, x)));
			visited[d ^ 1][y][x] = true;
		}
		t++;
	}

	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	pair<int, int> B[3], E[3];
	int B_idx = 0, E_idx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'B') {
				B[B_idx++] = make_pair(i, j);
				arr[i][j] = '0';
			}
			else if (arr[i][j] == 'E') {
				E[E_idx++] = make_pair(i, j);
				arr[i][j] = '0';
			}
		}
	}
	int B_d, E_d;
	if (B[0].first == B[1].first) B_d = 0;
	else B_d = 1;
	if (E[0].first == E[1].first) E_d = 0;
	else E_d = 1;
	arr[E[1].first][E[1].second] = 'E';

	cout << bfs(B[1], B_d, E_d) << '\n';
	return 0;
}