// 최단 경로

#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

int V, E;
int arr[20001];
vector<pair<int, int>> vec[20001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int start;
	cin >> V >> E >> start;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= V; i++)
		arr[i] = INT_MAX;
	arr[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	int node, cost;
	while (!pq.empty()) {
		node = pq.top().second;
		cost = -pq.top().first;
		pq.pop();
		if (cost > arr[node]) continue;
		int len = vec[node].size();
		for (int i = 0; i < len; i++) {
			int next_node = vec[node][i].first;
			int next_cost = vec[node][i].second;
			if (cost + next_cost < arr[next_node]) {
				arr[next_node] = cost + next_cost;
				pq.push(make_pair(-arr[next_node], next_node));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (arr[i] == INT_MAX) cout << "INF\n";
		else cout << arr[i] << '\n';
	}
	return 0;
}