// 플로이드

#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int n, m;
int arr[101][101] = { {0,}, };

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			arr[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < m; i++) {
		int s, d, c;
		cin >> s >> d >> c;
		arr[s][d] = min(arr[s][d], c);
	}
	for (int via = 1; via <= n; via++) {
		for (int from = 1; from <= n; from++) {
			for (int to = 1; to <= n; to++) {
				if (arr[from][via] != INT_MAX && arr[via][to] != INT_MAX)
					arr[from][to] = min(arr[from][to], arr[from][via] + arr[via][to]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "0 ";
			else {
				if (arr[i][j] == INT_MAX) cout << "0 ";
				else cout << arr[i][j] << " ";
			}
		}
		cout << '\n';
	}
	return 0;
}