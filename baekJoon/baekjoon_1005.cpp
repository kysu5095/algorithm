// ACM Craft
// 10:20

#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int n, k, w;
int arr[1001];
int time[1001];
int table[1001];

int craft(vector<vector<int>>& v) {
	int b, t, len;
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		if (!arr[i]) 
			q.push(make_pair(i, time[i]));
	}
	while (!q.empty()) {
		b = q.front().first;
		t = q.front().second;
		q.pop();
		if (b == w) return t;

		len = v[b].size();
		for (int i = 0; i < len; i++) {
			arr[v[b][i]]--;
			table[v[b][i]] = table[v[b][i]] < t ? t : table[v[b][i]];
			if (!arr[v[b][i]]) {
				table[v[b][i]] += time[v[b][i]];
				q.push(make_pair(v[b][i], table[v[b][i]]));
			}
		}
	}
	return time[w];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T, first, second;
	cin >> T;
	while (T--) {
		memset(arr, 0, sizeof(arr));
		memset(table, 0, sizeof(table));
		cin >> n >> k;
		vector<vector<int>> v(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> time[i];
		for (int i = 1; i <= k; i++) {
			cin >> first >> second;
			v[first].push_back(second);
			arr[second]++;
		}
		cin >> w;
		cout << craft(v) << '\n';
	}
	return 0;
}