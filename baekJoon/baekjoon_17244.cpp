// 아맞다우산
// 3:00

#include <iostream>
#include <queue>

using namespace std;

int n, m, idx = 1, cnt = 0;
char arr[51][51];
bool visited[51][51][1 << 5 + 1] = { { {false,},}, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs(int _y, int _x) {
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(_y, _x)));
	visited[_y][_x][0] = true;
	int y, x, ny, nx, item, nitem, len, t = 0;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			y = q.front().second.first;
			x = q.front().second.second;
			item = q.front().first;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny >= 0 && ny < m && nx >= 0 && nx < n && arr[ny][nx] != '#') {
					if (arr[ny][nx] == '.') {
						if (!visited[ny][nx][item]) {
							q.push(make_pair(item, make_pair(ny, nx)));
							visited[ny][nx][item] = true;
						}
					}
					else if (arr[ny][nx] == 'E') {
						if(item == cnt)
							return t;
					}
					else {
						nitem = item | (arr[ny][nx] - '0');
						q.push(make_pair(nitem, make_pair(ny, nx)));
						visited[ny][nx][nitem] = true;
					}
				}
			}
		}
	}
	return t;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(NULL);
	int y, x;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'S') {
				y = i, x = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'X') {
				arr[i][j] = idx + '0';
				cnt += idx;
				idx <<= 1;
			}
		}
	}
	idx >>= 1;
	cout << bfs(y, x) << '\n';
	return 0;
}