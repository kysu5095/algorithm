// 특정한 최단 경로

#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

int n, e, v1, v2;
int arr[801];
vector<pair<int, int>> v[200001];

int bfs() {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 1));
	arr[1] = 0;
	int node, d, next_node, nd, len;
	while (!pq.empty()) {
		node = pq.top().second;
		d = -pq.top().first;
		pq.pop();
		if (arr[node] < d) continue;

		len = v[node].size();
		for (int i = 0; i < len; i++) {
			next_node = v[node][i].first;
			nd = v[node][i].second;
			if (d + nd < arr[next_node]) {
				arr[next_node] = d + nd;
				pq.push(make_pair(-(d + nd), next_node));
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	cin >> v1>> v2;/*
	for (int i = 0; i < v[v1].size(); i++) {
		if (v[v1][i].first == v2) {
			v[v1][i].second -= 1;
			break;
		}
	}
	for (int i = 0; i < v[v2].size(); i++) {
		if (v[v2][i].first == v1) {
			v[v2][i].second -= 1;
			break;
		}
	}*/
	for (int i = 1; i <= n; i++) 
		arr[i] = INT_MAX;

	cout << bfs() << '\n';
	return 0;
}