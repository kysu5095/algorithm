// 보석 줍기

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k, res = 0;
int island[101];
bool visited[101][1 << 15] = { {false,}, };
vector<pair<int, int>> v[101];

void bfs() {
	       /* index,   cristal, weight */
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(1, make_pair(0, 0)));
	visited[1][0] = true;
	int idx, next_idx, cristal, n_cristal, wgt, bridge, len;
	while (!q.empty()) {
		idx = q.front().first;
		cristal = q.front().second.first;
		wgt = q.front().second.second;
		q.pop();
		if (idx == 1) res = max(res, wgt);
		
		len = v[idx].size();
		for (int i = 0; i < len; i++) {
			next_idx = v[idx][i].first;
			bridge = v[idx][i].second;
			if (visited[next_idx][cristal]) continue;
			if (wgt > bridge) continue;

			/* 보석이 없거나 줍지 않는 경우 */
			visited[next_idx][cristal] = true;
			q.push(make_pair(next_idx, make_pair(cristal, wgt)));
			/* 보석 줍기 */
			if (island[next_idx] != -1 && ((cristal & (1 << island[next_idx])) == 0)) {
				n_cristal = (cristal | (1 << island[next_idx]));
				if (!visited[next_idx][n_cristal]) {
					visited[next_idx][n_cristal] = true;
					q.push(make_pair(next_idx, make_pair(n_cristal, wgt + 1)));
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int input, a, b, c, cnt = 0;
	memset(island, -1, sizeof(island));
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> input;
		island[input] = cnt++;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	bfs();
	cout << res << '\n';
	return 0;
}