// 보스몬스터 전리품

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, p, HP;
char arr[1001][1001];
int attack[26];
bool visited[26][1001][1001] = { { {false, }, }, };
bool check[26] = { false, };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
pair<int, int> person[26];
queue<pair<int, pair<int, int>>> q;

int bfs() {
	int y, x, ny, nx, num, len, cnt = 0;
	vector<int> v;
	while ((!v.empty() || !q.empty()) && HP > 0) {
		len = q.size();
		while (len--) {
			num = q.front().first;
			y = q.front().second.first;
			x = q.front().second.second;
			q.pop();
			if (check[num]) continue;
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == m || visited[num][ny][nx]) continue;
				if (arr[ny][nx] == 'X') continue;
				if (arr[ny][nx] == 'B') {
					v.push_back(num);
					check[num] = true;
					cnt++;
					continue;
				}
				q.push(make_pair(num, make_pair(ny, nx)));
				visited[num][ny][nx] = true;
			}
		}
		for (auto idx : v) {
			HP -= attack[idx];
			if (HP <= 0) break;
		}
	}
	return cnt;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	char num;
	int damage;
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			if (arr[i][j] >= 'a' && arr[i][j] <= 'z')
				person[arr[i][j] - 'a'] = make_pair(i, j);
		}
	}
	for (int i = 0; i < p; i++) {
		cin >> num >> damage;
		q.push(make_pair(num - 'a', make_pair(person[num - 'a'].first, person[num - 'a'].second)));
		visited[num - 'a'][person[num - 'a'].first][person[num - 'a'].second] = true;
		attack[num - 'a'] = damage;
	}
	cin >> HP;
	cout << bfs() << '\n';
	return 0;
}