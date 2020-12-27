// 치즈
// 11:40

#include <iostream>
#include <queue>

using namespace std;

int n, m, res, t;
int arr[101][101];
bool visited[101][101] = { {false, }, };

class Point {
public:
	int y, x;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
queue<pair<int, int>> q;

void bfs() {
	int y, x, ny, nx, len;
	t = 0;
	while (!q.empty()) {
		len = q.size();
		res = len;
		t++;
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			arr[y][x] = 0;
			for (int i = 0; i < 4; i++) {
				ny = y + p[i].y;
				nx = x + p[i].x;
				if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx]) {
					visited[ny][nx] = true;
					if (arr[ny][nx])
						q.push(make_pair(ny, nx));
					else {
						queue<pair<int, int>> tq;
						tq.push(make_pair(ny, nx));
						while (!tq.empty()) {
							int ty = tq.front().first;
							int tx = tq.front().second;
							tq.pop();
							for (int j = 0; j < 4; j++) {
								int nty = ty + p[j].y;
								int ntx = tx + p[j].x;
								if (nty >= 0 && nty < n && ntx >= 0 && ntx < m && !visited[nty][ntx]) {
									visited[nty][ntx] = true;
									if (arr[nty][ntx])
										q.push(make_pair(nty, ntx));
									else
										tq.push(make_pair(nty, ntx));
								}
							}
						}
					}
				}
			}
		}
	}
}

void find_cheese() {
	queue<pair<int, int>> tmp;
	tmp.push(make_pair(0, 0));
	visited[0][0] = true;
	int y, x, ny, nx;
	while (!tmp.empty()) {
		y = tmp.front().first;
		x = tmp.front().second;
		tmp.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + p[i].y;
			nx = x + p[i].x;
			if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx]) {
				visited[ny][nx] = true;
				if (arr[ny][nx])
					q.push(make_pair(ny, nx));
				else
					tmp.push(make_pair(ny, nx));
			}
		}
	}
	bfs();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];
	find_cheese();
	cout << t << '\n';
	cout << res << '\n';
	return 0;
}