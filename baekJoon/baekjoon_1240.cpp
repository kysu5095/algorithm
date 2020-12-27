// 노드사이의 거리

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> v[1001];

int bfs(int node1, int node2) {
	queue<pair<int, int>> q;
	q.push(make_pair(node1, 0));
	bool visited[1001] = { false, };
	visited[node1] = true;
	int node, d, len;
	while (!q.empty()) {
		node = q.front().first;
		d = q.front().second;
		q.pop();
		if (node == node2) return d;
		len = v[node].size();
		for (int i = 0; i < len; i++) {
			if (!visited[v[node][i].first]) {
				visited[v[node][i].first] = true;
				q.push(make_pair(v[node][i].first, d + v[node][i].second));
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int node1, node2, distance;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		cin >> node1 >> node2 >> distance;
		v[node1].push_back(make_pair(node2, distance));
		v[node2].push_back(make_pair(node1, distance));
	}
	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2;
		cout << bfs(node1, node2) << '\n';
	}
	return 0;
}