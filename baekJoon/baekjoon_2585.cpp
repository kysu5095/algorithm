// 경비행기

#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
#include <math.h>
#define MAX 10000

using namespace std;

int n, k, res = 0;
bool visited[1005];
vector<pair<int, int>> v;

int dist(pair<int, int>& a, pair<int, int>& b) {
	int y = a.first - b.first;
	int x = a.second - b.second;
	return (int)ceil(sqrt(y * y + x * x) / 10);
}

bool bfs(int& fuel) {
	queue<int> q;
	q.push(0);
	memset(visited, false, sizeof(visited));
	visited[0] = true;

	int idx, f, len, t = 0;
	while (!q.empty()) {
		if (t > k) break;
		t++;
		len = q.size();
		while (len--) {
			idx = q.front();
			q.pop();
			for (int next = 1; next < v.size(); next++) {
				if (visited[next]) continue;
				f = dist(v[idx], v[next]);
				if (f > fuel) continue;
				if (next == v.size() - 1) return true;
				q.push(next);
				visited[next] = true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &k);
	v.resize(n + 2);
	for (int i = 1; i <= n; i++) 
		scanf(" %d %d", &v[i].first, &v[i].second);
	v[0] = make_pair(0, 0);
	v[n + 1] = make_pair(MAX, MAX);
	int left = 0, right = MAX * MAX;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (bfs(mid)) {
			res = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	printf("%d\n", res);
	return 0;
}