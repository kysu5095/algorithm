// 최소비용 구하기

#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

int n, m, start, last;
int arr[1001];
vector<pair<int, int>> v[1001];

void bfs() {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	int bus, cost, len;
	while (!pq.empty()) {
		bus = pq.top().second;
		cost = -pq.top().first;
		pq.pop();
		len = v[bus].size();
		for (int i = 0; i < len; i++) {
			if (cost + v[bus][i].second < arr[v[bus][i].first]) {
				arr[v[bus][i].first] = cost + v[bus][i].second;
				pq.push(make_pair(-arr[v[bus][i].first], v[bus][i].first));
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int s, l, cost;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		arr[i] = INT_MAX;
	for (int i = 0; i < m; i++) {
		cin >> s >> l >> cost;
		v[s].push_back(make_pair(l, cost));
	}
	cin >> start >> last;
	bfs();
	cout << arr[last] << '\n';
	return 0;
}