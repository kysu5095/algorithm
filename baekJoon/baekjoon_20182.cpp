// 골목 대장 호석 - 효율성 1

#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int n, m, A, B, C;
vector<pair<int, int>> v[100001];
vector<int> bill;
bool visited[100001];

bool bfs(int& mid) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, A));
	vector<int> visited(n + 1, INT_MAX);
	visited[A] = 0;
	int node, cost, next_node, next_cost;
	while (!pq.empty()) {
		node = pq.top().second;
		cost = -pq.top().first;
		pq.pop();
		if (node == B) return true;
		if (cost > visited[node]) continue;
		for (int i = 0; i < v[node].size(); i++) {
			next_node = v[node][i].first;
			next_cost = v[node][i].second;
			if (next_cost > mid) continue;
			if (cost + next_cost > C) continue;
			if (cost + next_cost >= visited[next_node]) continue;
			pq.push(make_pair(-(cost + next_cost), next_node));
			visited[next_node] = cost + next_cost;
		}
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int node1, node2, cost;
	cin >> n >> m >> A >> B >> C;
	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2 >> cost;
		v[node1].push_back(make_pair(node2, cost));
		v[node2].push_back(make_pair(node1, cost));
		bill.push_back(cost);
	}
	sort(bill.begin(), bill.end());
	bill.erase(unique(bill.begin(), bill.end()), bill.end());
	int l = 0, r = bill.size() - 1;
	int res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (bfs(bill[mid])) {
			r = mid - 1;
			res = bill[mid];
		}
		else
			l = mid + 1;
	}
	cout << res << '\n';
	return 0;
}