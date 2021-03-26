// 호석이 두 마리 치킨

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <limits.h>

using namespace std;

int n, m, res;
bool visited[101];
vector<int> v[101];

int bfs(int& start, int& end) {
	queue<int> sq, eq;
	sq.push(start);
	eq.push(end);
	visited[start] = true;
	visited[end] = true;
	int node, len, sz = 0, t = 0;
	while (!sq.empty() || !eq.empty()) {
		t++;
		len = sq.size();
		while (len--) {
			node = sq.front();
			sq.pop();
			for (auto& next : v[node]) {
				if (visited[next]) continue;
				sq.push(next);
				visited[next] = true;
				sz += t << 1;
			}
		}

		len = eq.size();
		while (len--) {
			node = eq.front();
			eq.pop();
			for (auto& next : v[node]) {
				if (visited[next]) continue;
				eq.push(next);
				visited[next] = true;
				sz += t << 1;
			}
		}
	}
	return sz;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int start, end;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		v[start].push_back(end);
		v[end].push_back(start);
	}
	res = INT_MAX;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			memset(visited, false, sizeof(visited));
			int val = bfs(i, j);
			if (val < res) {
				start = i;
				end = j;
				res = val;
			}
		}
	}
	cout << start << " " << end << " " << res << '\n';
	return 0;
}