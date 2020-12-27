// 텀 프로젝트

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int test_case, n, cnt;
bool flag;
int arr[100001];
bool visited[100001];
bool is_ok[100001];

void dfs(int node) {
	visited[node] = true;
	int next = arr[node];
	if (!visited[next])
		dfs(next);
	else {
		if (!is_ok[next]) {
			for (int i = next; i != node; i = arr[i])
				cnt++;
			cnt++;
		}
	}
	is_ok[node] = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		cnt = 0; 
		memset(visited, false, sizeof(visited));
		memset(is_ok, false, sizeof(is_ok));
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		for (int i = 1; i <= n; i++) {
			if (!visited[i])
				dfs(i);
		}
		cout << n - cnt << '\n';
	}
	return 0;
}