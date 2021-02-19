// 타임머신

#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#define ll long long
#define MAX 0x7f

using namespace std;

int n, m;
ll arr[501];
bool inQ[501];
queue<int> q;
vector<pair<int, int>> v[501];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= n; i++)
		arr[i] = LLONG_MAX;
	q.push(1);
	inQ[1] = true;
	arr[1] = 0;
	int cnt = 0, len;
	while (!q.empty()) {
		if (cnt == n) {
			cout << "-1\n";
			return 0;
		}
		len = q.size();
		while (len--) {
			int node = q.front();
			q.pop();
			inQ[node] ^= 1;
			for (auto& next : v[node]) {
				if (arr[next.first] > arr[node] + next.second) {
					arr[next.first] = arr[node] + next.second;
					if (!inQ[next.first]) {
						q.push(next.first);
						inQ[next.first] ^= 1;
					}
				}
			}
		}
		cnt++;
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i] == LLONG_MAX) arr[i] = -1;
		cout << arr[i] << '\n';
	}
	return 0;
}