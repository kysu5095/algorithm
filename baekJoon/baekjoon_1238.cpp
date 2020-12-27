// 파티

#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

int n, m, x;
int arr1[1001];
int arr2[1001];
vector<pair<int, int>> v1[1001];
vector<pair<int, int>> v2[1001];

int bfs() {
	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= n; i++) arr1[i] = INT_MAX;
	arr1[x] = 0;
	pq.push(make_pair(0, x));
	int node, cost, len;
	while (!pq.empty()) {
		node = pq.top().second;
		cost = -pq.top().first;
		pq.pop();
		if (cost > arr1[node]) continue;
		len = v1[node].size();
		for (int i = 0; i < len; i++) {
			if (cost + v1[node][i].second < arr1[v1[node][i].first]) {
				arr1[v1[node][i].first] = cost + v1[node][i].second;
				pq.push(make_pair(-arr1[v1[node][i].first], v1[node][i].first));
			}
		}
	}
	for (int i = 1; i <= n; i++) arr2[i] = INT_MAX;
	arr2[x] = 0;
	pq.push(make_pair(0, x));
	while (!pq.empty()) {
		node = pq.top().second;
		cost = -pq.top().first;
		pq.pop();
		if (cost > arr2[node]) continue;
		len = v2[node].size();
		for (int i = 0; i < len; i++) {
			if (cost + v2[node][i].second < arr2[v2[node][i].first]) {
				arr2[v2[node][i].first] = cost + v2[node][i].second;
				pq.push(make_pair(-arr2[v2[node][i].first], v2[node][i].first));
			}
		}
	}
	int retval = 0;
	for (int i = 1; i <= n; i++)
		retval = retval < (arr1[i] + arr2[i]) ? (arr1[i] + arr2[i]) : retval;
	return retval;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int s, l, w;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		cin >> s >> l >> w;
		v1[s].push_back(make_pair(l, w));
		v2[l].push_back(make_pair(s, w));
	}
	cout << bfs() << '\n';
	return 0;
}