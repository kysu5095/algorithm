// Intercity

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <set>
#define ll long long

using namespace std;

int n, k, A, B;
vector<vector<int>> v;

int bfs_new() {
	queue<int> q;
	q.push(1);
	vector<int> visited(n + 1, INT_MAX);
	visited[1] = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto& next : v[node]) {
			if (visited[next] != INT_MAX) continue;
			q.push(next);
			visited[next] = visited[node] + 1;
		}
	}
	return visited[n];
}

int bfs_old() {
	queue<int> q;
	q.push(1);
	vector<int> visited(n + 1, INT_MAX);
	visited[1] = 0;
	set<int> s;
	for (int i = 2; i <= n; i++) s.insert(i);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto it = s.begin(); it != s.end();) {
			if (!binary_search(v[node].begin(), v[node].end(), *it)) {
				q.push(*it);
				visited[*it] = visited[node] + 1;
				it = s.erase(it);
			}
			else it++;
		}
	}
	return visited[n];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> A >> B;
	v.resize(n + 1);
	int node1, node2;
	for (int i = 0; i < k; i++) {
		cin >> node1 >> node2;
		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}
	for (int i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end());
	cout << min(1LL * bfs_new() * A, 1LL * bfs_old() * B) << '\n';
	return 0;
}