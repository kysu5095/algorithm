// 미확인 도착지

#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

int n, m, t, s, g, h;
int arr[2001] = { 0, };
bool visited[2001] = { false, };
vector<pair<int, int>> v[2001];

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));
	int node, cost, len;
	while (!pq.empty()) {
		node = pq.top().second;
		cost = -pq.top().first;
		pq.pop();
		if (cost > arr[node]) continue;
		len = v[node].size();
		for (int i = 0; i < len; i++) {
			int next_node = v[node][i].first;
			int next_cost = v[node][i].second;
			if (arr[next_node] > cost + next_cost) {
				arr[next_node] = cost + next_cost;
				pq.push(make_pair(-arr[next_node], next_node));
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int test_case, a, b, d;
	cin >> test_case;
	while (test_case--) {
		cin >> n >> m >> t >> s >> g >> h;
		for (int i = 1; i <= n; i++) {
			arr[i] = INT_MAX;
			visited[i] = false;
		}
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			d <<= 1;
			if ((a == g && b == h) || (a == h && b == g)) d--;
			v[a].push_back(make_pair(b, d));
			v[b].push_back(make_pair(a, d));
		}
		for (int i = 0; i < t; i++) {
			cin >> a;
			visited[a] = true;
		}
		dijkstra();
		for (int i = 1; i <= n; i++) {
			if (arr[i] == INT_MAX) continue;
			if (visited[i] && arr[i] % 2 != 0)
				cout << i << " ";
		}
		cout << '\n';
		for (int i = 1; i <= n; i++)
			v[i].clear();
	}
	return 0;
}