// 중량제한
// 2:20

#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int n, m, s, d;
long long res = 0;
bool visited[10001] = { false, };
vector<pair<int, long long>> v[100001];

bool bfs(long long cost) {
	queue<int> q;
	q.push(s);
	visited[s] = true;
	int node, len;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node == d)
			return true;
		len = v[node].size();
		for (int i = 0; i < len; i++) {
			if (!visited[v[node][i].first] && v[node][i].second >= cost) {
				visited[v[node][i].first] = true;
				q.push(v[node][i].first);
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int node1, node2;
	long long cost;
	long long max_c = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2 >> cost;
		v[node1].push_back(make_pair(node2, cost));
		v[node2].push_back(make_pair(node1, cost));
		max_c = max_c < cost ? cost : max_c;
	}
	cin >> s >> d;
	long long start = 0, end = max_c, mid;
	while (start <= end) {
		mid = (start + end) / 2;
		memset(visited, false, sizeof(visited));
		if (bfs(mid)) start = mid + 1;
		else end = mid - 1;
	}
	cout << end << '\n';
	return 0;
}