// 스타트 링크

#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

int f, s, g, u, d, res = INT_MAX;
int visited[1000001] = { 0, };

void bfs(int _cnt) {
	queue<int> q;
	q.push(_cnt);
	visited[_cnt] = 1;
	int cnt, next;
	while (!q.empty()) {
		cnt = q.front();
		if (cnt == g) {
			res = visited[cnt] - 1;
			return;
		}
		q.pop();
		next = cnt + u;
		if (next >= 1 && next <= f && !visited[next]) {
			visited[next] = visited[cnt] + 1;
			q.push(next);
		}
		next = cnt - d;
		if (next >= 1 && next <= f && !visited[next]) {
			visited[next] = visited[cnt] + 1;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> f >> s >> g >> u >> d;
	visited[s] = true;
	bfs(s);
	if (res == INT_MAX) cout << "use the stairs\n";
	else cout << res << '\n';
	return 0;
}