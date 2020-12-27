// 로또
// 7:00

#include <iostream>

using namespace std;

int k;
int arr[14];
int print[14];

void dfs(int idx, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++)
			cout << print[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = idx; i < k; i++) {
		print[cnt] = arr[i];
		dfs(i + 1, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		cin >> k;
		if (!k) break;
		for (int i = 0; i < k; i++)
			cin >> arr[i];
		dfs(0, 0);
		cout << '\n';
	}
	return 0;
}