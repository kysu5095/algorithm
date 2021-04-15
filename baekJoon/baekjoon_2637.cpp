// 장난감조립

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int n, c;
int arr[101], need[101][101];
vector<pair<int, int>> v[101];

int main() {
	scanf("%d", &n);
	scanf(" %d", &c);
	while (c--) {
		int x, y, k;
		scanf(" %d %d %d", &x, &y, &k);
		v[y].push_back(make_pair(x, k));
		arr[x]++;
	}
	queue<int> q;
	for (int i = 1; i < n; i++) {
		if (!arr[i]) {
			q.push(i);
			need[i][i] = 1;
		}
	}
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		for (auto& it : v[num]) {
			arr[it.first]--;
			for (int i = 1; i < n; i++)
				need[it.first][i] += need[num][i] * it.second;
			if (!arr[it.first])
				q.push(it.first);
		}
	}
	for (int i = 1; i < n; i++)
		if (need[n][i]) printf("%d %d\n", i, need[n][i]);
	return 0;
}