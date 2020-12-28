// 견우와 직녀
// 3:15

#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[11][11];
bool visited[11][11][2] = { { {false, } ,}, };
int dy[5] = { 0, 0, 0, 1, -1 };
int dx[5] = { 0, 1, -1, 0, 0 };

void find_no_bridge() {
	int row, colum, sum;
	int r_max = 20, c_max = 20;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > 1) continue;
			sum += arr[i][j];
		}
		if (sum < r_max) {
			row = i;
			r_max = sum;
		}
	}
	for (int j = 0; j < n; j++) {
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i][j] > 1) continue;
			sum += arr[i][j];
		}
		if (sum < c_max) {
			colum = j;
			c_max = sum;
		}
	}
	arr[row][colum] = -1;
}

int bfs() {
	queue < pair<pair<int, int>, pair<bool, bool>>> q;
	q.push(make_pair(make_pair(0, 0), make_pair(true, false)));
	visited[0][0][0] = true;
	int y, x, ny, nx, len, t = 0;
	// flag : 다리를 건널 수 있냐, is_bridge : 한번이라도 다리를 건넌적 있냐
	bool flag, is_bridge;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().first.first;
			x = q.front().first.second;
			flag = q.front().second.first;
			is_bridge = q.front().second.second;
			q.pop();
			if (y == n - 1 && x == n - 1) return t;
			
			for (int i = 0; i < 5; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx][is_bridge]) {
					// 이동할 수 있는 일반적인 땅
					if (arr[ny][nx] == 1) {
						q.push(make_pair(make_pair(ny, nx), make_pair(true, is_bridge)));
						visited[ny][nx][is_bridge] = true;
					}
					// 건널 수 없는 절벽
					else if (arr[ny][nx] == 0 && !is_bridge && !visited[ny][nx][true]) {
						if ((t + 1) % m == 0 && flag) {
							q.push(make_pair(make_pair(ny, nx), make_pair(false, true)));
							visited[ny][nx][true] = true;
						}
						// 그 자리에 가만히 있기
						else if ((t + 1) % m != 0 && flag)
							q.push(make_pair(make_pair(y, x), make_pair(true, is_bridge)));
					}
					// 적혀있는 수 만큼의 주기를 가지는 오작교
					else if (arr[ny][nx] > 1 && flag) {
						if ((t + 1) % arr[ny][nx] == 0) {
							q.push(make_pair(make_pair(ny, nx), make_pair(false, is_bridge)));
							visited[ny][nx][is_bridge] = true;
						}
						// 그 자리에 가만히 있기
						else if ((t + 1) % arr[ny][nx] != 0 && flag)
							q.push(make_pair(make_pair(y, x), make_pair(true, is_bridge)));
					}
				}
			}
		}
		t++;
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	find_no_bridge();
	cout << bfs() << '\n';
	return 0;
}