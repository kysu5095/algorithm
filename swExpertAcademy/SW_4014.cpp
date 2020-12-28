// 복습 - 확주로 건설
// 7:10

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int test_case, n, x, res;
int arr[21][41];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);
	int h, i, j;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		cin >> n >> x;
		res = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				cin >> arr[i][j];
		for (j = 0; j < n; j++)
			for (i = 0; i < n; i++)
				arr[j][i + n] = arr[i][j];

		for (j = 0; j < n + n; j++) {
			h = 1;
			for (i = 0; i < n - 1; i++) {
				if (arr[i][j] == arr[i + 1][j]) h++;
				else if (arr[i][j] - 1 == arr[i + 1][j] && h >= 0) h = 1 - x;
				else if (arr[i][j] + 1 == arr[i + 1][j] && h >= x) h = 1;
				else break;
			}
			if (i == n - 1 && h >= 0)
				res++;
		}
		cout << "#" << tc << " " << res << '\n';
	}
	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <math.h>

// using namespace std;

// int n, d;
// int arr[41][21];

// bool available(int& y) {
// 	int rest = 1, cur = arr[y][0];
// 	bool flag = false;
// 	for (int x = 1; x < n; x++) {
// 		if (abs(cur - arr[y][x]) >= 2) return false;
// 		/* 높이 동일 */
// 		if (arr[y][x] == cur) {
// 			rest++;
// 			if (flag && rest == 0) flag = false;
// 		}
// 		/* 다음칸이 더 높다 */
// 		else if (cur < arr[y][x]) {
// 			if (flag) return false; /* 다리 짓는중 */
// 			if (rest - d < 0) return false; /* 자리 부족 */
// 			rest = 1;
// 			cur = arr[y][x];
// 		}
// 		/* 다음칸이 더 낮다 */
// 		else {
// 			if (flag) return false; /* 다리 짓는중 */
// 			flag = true;
// 			rest = -(d - 1);
// 			cur = arr[y][x];
// 		}
// 	}
// 	if (rest >= 0) return true;
// 	else return false;
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	//freopen("sample_input.txt", "r", stdin);
// 	int test_case, ret;
// 	cin >> test_case;
// 	for (int tc = 1; tc <= test_case; tc++) {
// 		ret = 0;
// 		cin >> n >> d;
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < n; j++)
// 				cin >> arr[i][j];
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < n; j++)
// 				arr[i + n][j] = arr[n - 1 - j][i];
// 		for (int i = 0; i < n + n; i++)
// 			if (available(i))
// 				ret++;
// 		cout << "#" << tc << " " << ret << '\n';
// 	}
// 	return 0;
// }