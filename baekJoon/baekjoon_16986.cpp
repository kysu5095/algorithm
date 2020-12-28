// 인싸들의 가위바위보

#include <iostream>
#include <algorithm>

using namespace std;

int n, k, res = 0;
int arr[10][10];
int game[3][20];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= 2; i++)
		for (int j = 0; j < 20; j++)
			cin >> game[i][j];
	for (int i = 0; i < 10; i++) game[0][i] = i + 1;
	do {
		int win[3] = { 0, 0, 0 };
		int idx[3] = { 0 ,0 ,0 };
		int idx1 = 0, idx2 = 1;
		int which1, which2;
		while (true) {
			if (idx1 == 0 && idx[idx1] == n) break;
			if (idx2 == 0 && idx[idx2] == n) break;
			which1 = game[idx1][idx[idx1]++];
			which2 = game[idx2][idx[idx2]++];
			if (arr[which1][which2] == 2) {
				if (++win[idx1] == k) break;
				for (int i = 0; i < 3; i++) {
					if (i != idx1 && i != idx2) {
						idx2 = i;
						break;
					}
				}
			}
			else if (arr[which1][which2] == 1) {
				if (idx1 < idx2) {
					if (++win[idx2] == k) break;
					for (int i = 0; i < 3; i++) {
						if (i != idx1 && i != idx2) {
							idx1 = i;
							break;
						}
					}
				}
				else {
					if (++win[idx1] == k) break;
					for (int i = 0; i < 3; i++) {
						if (i != idx1 && i != idx2) {
							idx2 = i;
							break;
						}
					}
				}
			}
			else {
				if (++win[idx2] == k) break;
				for (int i = 0; i < 3; i++) {
					if (i != idx1 && i != idx2) {
						idx1 = i;
						break;
					}
				}
			}
		}
		if (win[0] == k) {
			res = 1;
			break;
		}
	} while (next_permutation(game[0], game[0] + n));
	cout << res << '\n';
	return 0;
}