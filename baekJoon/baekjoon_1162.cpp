// 도로포장

#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int n, m, K;
long long arr[10001][21];
vector<pair<int, long long>> v[10001];

void bfs() {
	//                    length        node  k 
	priority_queue<pair<long long, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(1, 0)));
	arr[1][0] = 0;
	int node, k;
	long long len;
	while (!pq.empty()) {
		node = pq.top().second.first;
		len  = -pq.top().first;
		k    = pq.top().second.second;
		pq.pop();
		if (len > arr[node][k]) continue;

		for (int i = 0; i < v[node].size(); i++) {
			int next_node = v[node][i].first;
			long long next_len = v[node][i].second;
			/* 도로 포장 안할거 */
			if (len + next_len < arr[next_node][k]) {
				arr[next_node][k] = len + next_len;
				pq.push(make_pair(-(len + next_len), make_pair(next_node, k)));
			}
			/* 도로 포장 할거 */
			if (k < K && len < arr[next_node][k + 1]) {
				arr[next_node][k + 1] = len;
				pq.push(make_pair(-len, make_pair(next_node, k + 1)));
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int start, last;
	long long len;
	cin >> n >> m >> K;
	for (int i = 0; i < m; i++) {
		cin >> start >> last >> len;
		v[start].push_back(make_pair(last, len));
		v[last].push_back(make_pair(start, len));
	}

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= K; j++)
			arr[i][j] = LLONG_MAX;

	bfs();
	long long res = LLONG_MAX;
	for (int i = 0; i <= K; i++)
		res = min(res, arr[n][i]);
	cout << res << '\n';
	return 0;
}