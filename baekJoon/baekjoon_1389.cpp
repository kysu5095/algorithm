// 케빈 베이컨의 6단계 법칙
// 3:26

#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int n, m;
int arr[101][101] = { {0,}, };

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				else if (arr[i][k] && arr[k][j]) {
					if (!arr[i][j])
						arr[i][j] = arr[i][k] + arr[k][j];
					else
						arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int node1, node2;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2;
		arr[node1][node2] |= 1;
		arr[node2][node1] |= 1;
	}
	floyd();
	int p, res = INT_MAX;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++)
			sum += arr[i][j];
		if (res > sum) {
			res = sum;
			p = i;
		}
	}
	cout << p << '\n';
	return 0;
}