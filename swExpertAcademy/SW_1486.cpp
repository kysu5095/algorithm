// D4 : 장훈이의 높은 선반

#include <iostream>
#include <algorithm>

using namespace std;

int test_case, n, b, max_v;
int arr[21];

void dfs(int cnt, int sum) {
	if (cnt == n) {
		if (sum >= b)
			max_v = min(max_v, sum);
		return;
	}
	dfs(cnt + 1, sum);
	if (sum + arr[cnt] < max_v)
		dfs(cnt + 1, sum + arr[cnt]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		max_v = 1000000;
		cin >> n >> b;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		dfs(0, 0);
		cout << "#" << tc << " " << max_v - b << '\n';;
	}
	return 0;
}