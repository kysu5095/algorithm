// 울타리

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int n;
bool finish = false;
bool visited[41] = { false, };
vector<pair<int, pair<int, int>>> v;

bool promising() {
	int len = 0;
	int down_y = INT_MAX, up_y = 0;
	int left_x = INT_MAX, right_x = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			len -= v[i].first;
			continue;
		}
		down_y = min(down_y, v[i].second.first);
		up_y = max(up_y, v[i].second.first);
		left_x = min(left_x, v[i].second.second);
		right_x = max(right_x, v[i].second.second);
	}
	int width = right_x - left_x;
	int height = up_y - down_y;
	if (((width + height) * 2) <= len) return true;
	else return false;
}

void dfs(int idx, int cnt, int& goal) {
	if (finish) return;
	if (cnt == goal) {
		if (promising()) finish = true;
		return;
	}
	for (int i = idx; i < n; i++) {
		visited[i] = true;
		dfs(i + 1, cnt + 1, goal);
		visited[i] = false;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	v.resize(n);
	int y, x, len;
	for (int i = 0; i < n; i++) {
		cin >> y >> x >> len;
		v[i].first = -len;
		v[i].second.first = y;
		v[i].second.second = x;
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		dfs(0, 0, i);
		if (finish) {
			cout << i << '\n';
			break;
		}
	}
	return 0;
}