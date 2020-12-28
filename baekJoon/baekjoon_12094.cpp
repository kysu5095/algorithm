// 2048(Hard)

#include <iostream>
#include <algorithm>

using namespace std;

int n, max_value = 0;
int arr[21][21][2] = { { {0, }, }, };

void rotate(int arrA[][21][2], bool flag) {
	// turn array
	if (flag) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arrA[i][j][0] = arr[n - 1 - j][i][0];
				arr[i][j][1] = 0;
			}
		}
	}
	// copy
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j][0] = arrA[i][j][0];
		}
	}
}

void cal() {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[i][j][0] != 0) {
				int tmp = j;
				while (true) {
					tmp--;
					// 앞 숫자와 동일한 숫자일 경우
					if (arr[i][tmp][0] == arr[i][j][0]) {
						// 겹쳐진 적이 없는 경우
						if (arr[i][tmp][1] == 0) {
							arr[i][tmp][0] <<= 1;
							arr[i][tmp][1] = 1;
							arr[i][j][0] = 0;
							break;
						}
						// 겹쳐진 적이 있는 경우
						else {
							arr[i][tmp + 1][0] = arr[i][j][0];
							arr[i][j][0] = 0;
							break;
						}
					}
					// 앞 숫자가 다른 숫자일 경우
					if (arr[i][tmp][0] != 0) {
						if (tmp == j - 1) break;
						arr[i][tmp + 1][0] = arr[i][j][0];
						arr[i][j][0] = 0;
						break;
					}
					// 끝까지 왔을 경우
					if (tmp == 0) {
						arr[i][tmp][0] = arr[i][j][0];
						arr[i][j][0] = 0;
						break;
					}
				}
			}
		}
	}
}

bool isSame(int arrA[][21][2]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j][0] != arrA[i][j][0]) return false;

	return true;
}

int maxValue() {
	int val = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			val = max(val, arr[i][j][0]);

	return val;
}

void dfs(int cnt) {
	if (cnt == 10) {
		max_value = max(max_value, maxValue());
		return;
	}
	int tmpArr[21][21][2] = { { {0,}, }, };
	for (int i = 0; i < 4; i++) {
		rotate(tmpArr, true);
		cal();
		if(!isSame(tmpArr) && (maxValue() * (1 << (9 - cnt))) > max_value)
			dfs(cnt + 1);
		rotate(tmpArr, false);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j][0];
			max_value = max(max_value, arr[i][j][0]);
		}
	}
	dfs(0);
	cout << max_value << '\n';

	return 0;
}