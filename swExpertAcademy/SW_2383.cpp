// 점심 식사시간
// 3:30

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int test_case, n, len, res;
int arr[11][11];
int team[11];

class Point {
public:
	int y, x;
};
vector<Point> v;
vector<Point> door;
vector<int> team_a;
vector<int> team_b;

int get_a_door() {
	if (team_a.empty()) return -1;
	int len_a = team_a.size();
	sort(team_a.begin(), team_a.end());
	int door_a[3] = { 0, };
	int t = team_a[0];
	int idx = 0;
	while (idx != len_a) {
		t++;
		for (int i = 0; i < 3; i++) {
			if (door_a[i])
				door_a[i]--;
		}
		if (team_a[idx] >= t) continue;

		for (int i = 0; i < 3; i++) {
			if (!door_a[i] && idx != len_a && team_a[idx] < t) {
				door_a[i] = arr[door[0].y][door[0].x];
				idx++;
			}
		}
	}
	t += arr[door[0].y][door[0].x];
	return t;
}

int get_b_door() {
	if (team_b.empty()) return -1;
	int len_b = team_b.size();
	sort(team_b.begin(), team_b.end());
	int door_b[3] = { 0, };
	int t = team_b[0];
	int idx = 0;
	while (idx != len_b) {
		t++;
		for (int i = 0; i < 3; i++) {
			if (door_b[i])
				door_b[i]--;
		}
		if (team_b[idx] >= t) continue;

		for (int i = 0; i < 3; i++) {
			if (!door_b[i] && idx != len_b && team_b[idx] < t) {
				door_b[i] = arr[door[1].y][door[1].x];
				idx++;
			}
		}
	}
	t += arr[door[1].y][door[1].x];
	return t;
}

void dfs(int idx) {
	if (idx == len) {
		for (int i = 0; i < len; i++) {
			if (team[i]) team_a.push_back({ abs(v[i].y - door[0].y) + abs(v[i].x - door[0].x) });
			else team_b.push_back({ abs(v[i].y - door[1].y) + abs(v[i].x - door[1].x) });
		}
		int a = get_a_door();
		int b = get_b_door();
		a = a < b ? b : a;
		res = res > a ? a : res;

		team_a.clear();
		team_b.clear();
		return;
	}
	team[idx] = 0;
	dfs(idx + 1);
	team[idx] = 1;
	dfs(idx + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		res = INT_MAX;
		v.clear();
		door.clear();
		team_a.clear();
		team_b.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1)
					v.push_back({ i, j });
				else if (arr[i][j] > 1)
					door.push_back({ i, j });
			}
		}
		len = v.size();
		dfs(0);

		cout << "#" << tc << " " << res << '\n';
	}
	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <math.h>
// #include <limits.h>
// #include <string.h>
// #include <queue>

// using namespace std;

// int n, res;
// int arr[10][10];
// int sequence[10];
// int visited[3];
// vector<pair<int, int>> person, stair;

// int get_time(int s_idx, vector<int>& v) {
// 	memset(visited, 0, sizeof(visited));
// 	int t = 0, idx, len, m_time, flag;
// 	int s_time = arr[stair[s_idx].first][stair[s_idx].second];
// 	idx = 0;
// 	len = v.size();
// 	while (true) {
// 		/* visited[i][0] : arrive time */
// 		/* visited[i][1] : person idx  */
// 		for (int i = 0; i < 3; i++) {
// 			if (!visited[i]) {
// 				if (idx == len) break;
// 				if (v[idx] >= t) {
// 					t = v[idx];
// 					visited[i] = t;
// 				}
// 				else
// 					visited[i] = t - 1;
// 				idx++;
// 			}
// 		}
// 		flag = 0;
// 		for (int i = 0; i < 3; i++) flag += visited[i];
// 		if (!flag) break;
// 		m_time = INT_MAX;
// 		for (int i = 0; i < 3; i++)
// 			if (visited[i]) m_time = min(m_time, visited[i]);
// 		if (t < m_time + s_time + 1) t = m_time + s_time + 1;
// 		for (int i = 0; i < 3; i++)
// 			if (visited[i] + s_time + 1 <= t) visited[i] = 0;
// 	}
// 	return t;
// }

// int down_stair() {
// 	vector<int> v1, v2;
// 	for (int i = 0; i < person.size(); i++) {
// 		if (sequence[i] == 0) v1.push_back(abs(person[i].first - stair[0].first) + abs(person[i].second - stair[0].second));
// 		else v2.push_back(abs(person[i].first - stair[1].first) + abs(person[i].second - stair[1].second));
// 	}
// 	sort(v1.begin(), v1.end());
// 	sort(v2.begin(), v2.end());
// 	int t1 = get_time(0, v1);
// 	int t2 = get_time(1, v2);
// 	return max(t1, t2);
// }

// void dfs(int cnt) {
// 	if (cnt == person.size()) {
// 		int val = down_stair();
// 		res = min(res, val);
// 		return;
// 	}
// 	sequence[cnt] = 0;
// 	dfs(cnt + 1);
// 	sequence[cnt] = 1;
// 	dfs(cnt + 1);
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	//freopen("sample_input.txt", "r", stdin);
// 	int test_case;
// 	cin >> test_case;
// 	for (int tc = 1; tc <= test_case; tc++) {
// 		res = INT_MAX;
// 		person.clear();
// 		stair.clear();
// 		cin >> n;
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < n; j++) {
// 				cin >> arr[i][j];
// 				if (arr[i][j] == 1) person.push_back(make_pair(i, j));
// 				else if (arr[i][j] >= 2) stair.push_back(make_pair(i, j));
// 			}
// 		}
// 		dfs(0);
// 		cout << "#" << tc << " " << res << '\n';
// 	}
// 	return 0;
// }