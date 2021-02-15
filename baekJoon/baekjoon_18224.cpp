// 미로에 갇힌 건후

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m;
bool arr[501][501], visited[501][501];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

bool promising(int& y, int& x) {
	if (y < 0 || y == n || x < 0 || x == n || visited[y][x]) return false;
	else return true;
}

//void bfs() {
//	queue<pair<int, int>> q;
//	q.push(make_pair(0, 0));
//	visited[0][0] = true;
//	int y, x, ny, nx, t, len, cnt = 0;
//	bool isSun = true;
//
//	while (!q.empty()) {
//		cnt++;
//		len = q.size();
//		while (len--) {
//			y = q.front().first;
//			x = q.front().second;
//			q.pop();
//			if (y == n - 1 && x == n - 1) {
//				int day = cnt / (m * 2) + 1;
//				string sun = isSun ? "sun" : "moon";
//				cout << day << " " << sun << '\n';
//				return;
//			}
//			for (int i = 0; i < 4; i++) {
//				ny = y + dy[i];
//				nx = x + dx[i];
//				if (!promising(ny, nx)) continue;
//				if (isSun) {
//					if (arr[ny][nx]) continue;
//					q.push(make_pair(ny, nx));
//					visited[ny][nx] = true;
//				}
//				else {
//					if (arr[ny][nx]) {
//						while (true) {
//							ny += dy[i];
//							nx += dx[i];
//							if (!promising(ny, nx)) break;
//							if (!arr[ny][nx]) {
//								q.push(make_pair(ny, nx));
//								visited[ny][nx] = true;
//								break;
//							}
//						}
//					}
//					else {
//						q.push(make_pair(ny, nx));
//						visited[ny][nx] = true;
//					}
//				}
//			}
//		}
//		if (cnt % m == 0) 
//			isSun ^= 1;
//	}
//	cout << "-1\n";
//}

int getTime(int t) {
	bool flag = true;
	while (true) {
		flag ^= 1;
		t++;
		if (t % m == 0) break;
	}
	if (flag) return t;
	else return t + 1;
}

void MOON(int& y, int& x, int t, priority_queue<pair<int, pair<int, int>>>& pq) {
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx]) continue;
		if (arr[ny][nx]) {
			while (true) {
				ny += dy[i];
				nx += dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx]) break;
				if (!arr[ny][nx]) {
					pq.push(make_pair(-(t + 1), make_pair(ny, nx)));
					visited[ny][nx] = true;
					break;
				}
			}
		}
		else {
			pq.push(make_pair(-(t + 1), make_pair(ny, nx)));
			visited[ny][nx] = true;
		}
	}
}

void SUN(int& y, int& x, int t, priority_queue<pair<int, pair<int, int>>>& pq) {
	int ny, nx, cnt = 0;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny == n || nx < 0 || nx == n || arr[ny][nx]) continue;
		if (!visited[ny][nx]) {
			pq.push(make_pair(-(t + 1), make_pair(ny, nx)));
			visited[ny][nx] = true;
		}
		cnt++;
	}
	if (!cnt) return;

	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny == n || nx < 0 || nx == n) continue;
		if (arr[ny][nx]) {
			int next_t = getTime(t);
			MOON(ny, nx, next_t, pq);
		}
	}
}

void bfs() {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(-1, make_pair(0, 0)));
	visited[0][0] = true;
	
	int y, x, ny, nx, t, cnt;
	bool is_sun;
	while (!pq.empty()) {
		y = pq.top().second.first;
		x = pq.top().second.second;
		t = -pq.top().first;
		pq.pop();
		if (t % (m * 2) >= 1 && t % (m * 2) <= m) is_sun = true;
		else is_sun = false;
		if (y == n - 1 && x == n - 1) {
			int day = (t / (m * 2)) + 1;
			string sun = is_sun ? "sun" : "moon";
			cout << day << " " << sun << '\n';
			return;
		}

		if (is_sun) SUN(y, x, t, pq);
		else MOON(y, x, t, pq);
	}
	cout << "-1\n";
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	bfs();
	return 0;
}