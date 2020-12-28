// 인구이동 //
////////////////

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, l, r;
int countryCnt = 0;	// 연합의 개수
int movePeople = 0;	// 인구이동 횟수
int isUnion = 0;    // 연합의 존재 유무
int arr[55][55];
bool jud = false;

class Point {
public:
	int x, y;
};
Point p[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void dfs(int x, int y, bool (* visited)[55], vector<Point> alli[55]) {
	if (jud) {
		alli[countryCnt].push_back({ x, y });
	}

	for (int k = 0; k < 4; k++) {
		int nx = x + p[k].x;
		int ny = y + p[k].y;

		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx]) {
			if (abs(arr[y][x] - arr[ny][nx]) >= l && abs(arr[y][x] - arr[ny][nx]) <= r) {
				if(!jud) alli[countryCnt].push_back({ x, y });
				isUnion = 1;
				visited[ny][nx] = true;
				jud = true;
				dfs(nx, ny, visited, alli);
			}
		}
	}
}

bool unionDay() {
	bool visited[55][55] = { {false, } };
	vector<Point> alli[2001];	// 동맹국 저장 좌표
	countryCnt = 0;

	/*cout << "============열기 전=============\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				isUnion = 0;
				visited[i][j] = true;
				dfs(j, i, visited, alli);
				jud = false;
				if (isUnion == 1) countryCnt++;
			}
		}
	}

	if (countryCnt != 0) {
		movePeople++;
		for (int i = 0; i < countryCnt; i++) {
			int sum = 0;
			for (int j = 0; j < alli[i].size(); j++) {
				sum += arr[alli[i][j].y][alli[i][j].x];
				//cout << "x : " << alli[i][j].x << "  y : " << alli[i][j].y << '\n';
			}
			//cout << i << "sum : " << sum << "  size : " << alli[i].size() << '\n';

			sum /= alli[i].size();
			for (int j = 0; j < alli[i].size(); j++) {
				arr[alli[i][j].y][alli[i][j].x] = sum;
			}
		}

		/*cout << '\n';
		cout << "============열 후=============\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}
			cout << '\n';
		}*/

		return true;
	}
	else 
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		if (!unionDay()) break;
	}

	cout << movePeople << '\n';

	return 0;
}

// #include <iostream>
// #include <string.h>
// #include <vector>
// #include <queue>

// using namespace std;

// int result = 0;
// int n, L, R;
// bool flag = false;
// int arr[51][51] = { {0, }, };
// bool visited[51][51] = { {false, }, };

// class Point {
// public:
// 	int y, x;
// };
// Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
// vector<Point> unite_state;
// queue<Point> q;

// void union_state(int sum) {
// 	int size = unite_state.size();
// 	if (size == 1) 
// 		return;

// 	int val = sum / size;
// 	for (int i = 0; i < size; i++) 
// 		arr[unite_state[i].y][unite_state[i].x] = val;

// 	flag = true;
// }

// void bfs(int _y, int _x) {
// 	q.push({ _y, _x });
// 	int sum = arr[_y][_x];
// 	while (!q.empty()) {
// 		int y = q.front().y;
// 		int x = q.front().x;
// 		q.pop();

// 		for (int i = 0; i < 4; i++) {
// 			int ny = y + p[i].y;
// 			int nx = x + p[i].x;
// 			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx]) {
// 				if (abs(arr[y][x] - arr[ny][nx]) >= L && abs(arr[y][x] - arr[ny][nx]) <= R) {
// 					visited[ny][nx] = true;
// 					unite_state.push_back({ ny, nx });
// 					sum += arr[ny][nx];
// 					q.push({ ny, nx });
// 				}
// 			}
// 		}
// 	}
// 	union_state(sum);
// }

// bool unite() {
// 	flag = false;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			if (!visited[i][j]) {
// 				visited[i][j] = true;
// 				unite_state.push_back({ i, j });
// 				bfs(i, j);
// 				unite_state.clear();
// 			}
// 		}
// 	}
// 	if (flag)
// 		return true;
// 	else
// 		return false;
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cin >> n >> L >> R;
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < n; j++)
// 			cin >> arr[i][j];
// 	while (true) {
// 		memset(visited, false, sizeof(visited));
// 		if (!unite()) break;
// 		result++;
// 	}

// 	cout << result << '\n';

// 	return 0;
// }

// #include <iostream>
// #include <queue>
// #include <vector>
// #include <string.h>
// #include <math.h>

// using namespace std;

// int n, l, r, cnt = 0;
// int arr[51][51];
// bool visited[51][51];
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };

// void bfs(int y, int x, vector<pair<int, vector<pair<int, int>>>> &v) {
// 	int ny, nx, val, total = arr[y][x];
// 	vector<pair<int, int>> people;
// 	people.push_back(make_pair(y, x));
// 	queue<pair<int, int>> q;
// 	visited[y][x] = true;
// 	for (int i = 0; i < 4; i++) {
// 		ny = y + dy[i];
// 		nx = x + dx[i];
// 		if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx]) continue;
// 		val = abs(arr[y][x] - arr[ny][nx]);
// 		if (val < l || val > r) continue;
// 		q.push(make_pair(ny, nx));
// 		people.push_back(make_pair(ny, nx));
// 		visited[ny][nx] = true;
// 		total += arr[ny][nx];
// 	}
// 	if (people.size() <= 1) return;
// 	while (!q.empty()) {
// 		y = q.front().first;
// 		x = q.front().second;
// 		q.pop();
// 		for (int i = 0; i < 4; i++) {
// 			ny = y + dy[i];
// 			nx = x + dx[i];
// 			if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx]) continue;
// 			val = abs(arr[y][x] - arr[ny][nx]);
// 			if (val < l || val > r) continue;
// 			q.push(make_pair(ny, nx));
// 			people.push_back(make_pair(ny, nx));
// 			visited[ny][nx] = true;
// 			total += arr[ny][nx];
// 		}
// 	}
// 	v.push_back(make_pair(total, people));
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int len, plen, val, y, x;
// 	cin >> n >> l >> r;
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < n; j++)
// 			cin >> arr[i][j];
// 	while (true) {
// 		memset(visited, false, sizeof(visited));
// 		vector<pair<int, vector<pair<int, int>>>> v;
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < n; j++) {
// 				if (!visited[i][j])
// 					bfs(i, j, v);
// 			}
// 		}
// 		len = v.size();
// 		if (len == 0) break;
// 		cnt++;
// 		for (int i = 0; i < len; i++) {
// 			val = v[i].first;
// 			plen = (int)v[i].second.size();
// 			val /= plen;
// 			for (int j = 0; j < plen; j++) {
// 				y = v[i].second[j].first;
// 				x = v[i].second[j].second;
// 				arr[y][x] = val;
// 			}
// 		}
// 	}
// 	cout << cnt << '\n';
// 	return 0;
// }