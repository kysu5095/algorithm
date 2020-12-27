// 소수 경로
// 2:30

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int test_case, from, to, n;
bool is_num[10000] = { false, };
bool visited[10000];

void bfs() {
	queue<int> q;
	q.push(from);
	visited[from] = true;
	int a, val, len, t = 0;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			val = q.front();
			q.pop();
			if (val == to) {
				n = t;
				return;
			}
			a = val % 1000;
			for (int i = 1000; i < 10000; i += 1000) {
				if (!is_num[a + i] && !visited[a + i]) {
					visited[a + i] = true;
					q.push(a + i);
				}
			}
			a = ((val / 1000) * 1000) + (val % 100);
			for (int i = 0; i < 1000; i += 100) {
				if (!is_num[a + i] && !visited[a + i]) {
					visited[a + i] = true;
					q.push(a + i);
				}
			}
			a = ((val / 100) * 100) + (val % 10);
			for (int i = 0; i < 100; i += 10) {
				if (!is_num[a + i] && !visited[a + i]) {
					visited[a + i] = true;
					q.push(a + i);
				}
			}
			a = ((val / 10) * 10);
			for (int i = 0; i < 10; i++) {
				if (!is_num[a + i] && !visited[a + i]) {
					visited[a + i] = true;
					q.push(a + i);
				}
			}
		}
		t++;
	}
}

int main() {
	int j, cnt, res;
	for (int i = 2; i < 10000; i++) {
		if (!is_num[i]) {
			for (int j = 2; i * j < 10000; j++)
				is_num[i * j] = true;
		}
	}
	cin >> test_case;
	while (test_case--) {
		cin >> from >> to;
		n = -1;
		memset(visited, false, sizeof(visited));
		bfs();
		if (n == -1) cout << "Impossible\n";
		else cout << n << '\n';
	}
}