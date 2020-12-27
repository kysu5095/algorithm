// KCM Travel

#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int test_case, n, m, k; 
int dp[101][10001];
vector<pair<int, pair<int, int>>> v[101];

void bfs() {
	priority_queue<pair<int, pair<int, int>>> pq;
	// 시간, 노드, 비용
	pq.push(make_pair(0, make_pair(1, 0)));
	dp[1][0] = 0;
	int node, cost, time, len;
	while (!pq.empty()) {
		node = pq.top().second.first;
		cost = pq.top().second.second;
		time = -pq.top().first;
		pq.pop();
		if (dp[node][cost] < time) continue;
		len = v[node].size();
		for (int i = 0; i < len; i++) {
			if (cost + v[node][i].second.first <= m) {
				if (time + v[node][i].second.second < dp[v[node][i].first][cost + v[node][i].second.first]) {
					dp[v[node][i].first][cost + v[node][i].second.first] = time + v[node][i].second.second;
					pq.push(make_pair(-(time + v[node][i].second.second), make_pair(v[node][i].first, cost + v[node][i].second.first)));
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int s, l, c, d;
	cin >> test_case;
	while (test_case--) {
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			cin >> s >> l >> c >> d;
			v[s].push_back(make_pair(l, make_pair(c, d)));
		}
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= m; j++)
				dp[i][j] = INT_MAX;
		bfs();
		int retval = INT_MAX;
		for (int i = 0; i <= m; i++)
			retval = min(retval, dp[n][i]);
		if (retval == INT_MAX) cout << "Poor KCM\n";
		else cout << retval << '\n';

		for (int i = 1; i <= n; i++)
			v[i].clear();
	}
	return 0;
}