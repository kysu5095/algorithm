// 트리의 지름

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, far, res = 0;
bool visited[10001];
vector<pair<int, int>> v[10001];

void dfs(int node, int cost) {
	if (visited[node]) return;
	visited[node] = true;
	if (res < cost) {
		res = cost;
		far = node;
	}
	for (auto p : v[node])
		dfs(p.first, cost + p.second);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	memset(visited, false, sizeof(visited));
	dfs(1, 0);
	res = 0;
	memset(visited, false, sizeof(visited));
	dfs(far, 0);
	cout << res << '\n';
	return 0;
}