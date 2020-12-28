// 보호 필름
// 8:40

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits.h>

using namespace std;

int test_case, d, w, k, res;
int arr[14][21];
int tmp_arr[14][21];

bool check() {
	int val, cnt;
	for (int j = 0; j < w; j++) {
		val = arr[0][j];
		cnt = 1;
		for (int i = 1; i < d; i++) {
			if (cnt == k) break;
			if (val == arr[i][j]) cnt++;
			else {
				val = arr[i][j];
				cnt = 1;
			}
		}
		if (cnt != k)
			return false;
	}
	return true;
}

void dfs(int idx, int cnt, int goal) {
	if (cnt == goal) {
		if (check())
			res = cnt;
		return;
	}
	for (int i = idx; i < d; i++) {
		for (int j = 0; j < w; j++)
			arr[i][j] = 0;
		dfs(i + 1, cnt + 1, goal);
		for (int j = 0; j < w; j++)
			arr[i][j] = tmp_arr[i][j];

		for (int j = 0; j < w; j++)
			arr[i][j] = 1;
		dfs(i + 1, cnt + 1, goal);
		for (int j = 0; j < w; j++)
			arr[i][j] = tmp_arr[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("sample_input.txt", "r", stdin);
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		res = INT_MAX;
		cin >> d >> w >> k;
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				tmp_arr[i][j] = arr[i][j];
			}
		}

		if (k == 1 || check()) {
			cout << "#" << tc << " 0\n";
			continue;
		}
		for (int i = 1; i <= k; i++) {
			dfs(0, 0, i);
			if (res != INT_MAX) break;
		}
		cout << "#" << tc << " " << res << '\n';
	}
	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <string.h>

// using namespace std;

// int d, w, k, finish;
// bool is_pass;
// bool arr[14][21], copy_arr[14][21];

// bool is_passed() {
// 	for (int x = 0; x < w; x++) {
// 		bool cur = arr[0][x];
// 		int cnt = 1;
// 		bool pass = false;
// 		for (int y = 1; y < d; y++) {
// 			if (cur == arr[y][x]) cnt++;
// 			else {
// 				cur = arr[y][x];
// 				cnt = 1;
// 			}
// 			if (cnt >= k) {
// 				pass = true;
// 				break;
// 			}
// 		}
// 		if (!pass) return false;
// 	}
// 	return true;
// }

// void dfs(int idx, int cnt) {
// 	if (is_pass) return;
// 	if (cnt == finish) {
// 		if (is_passed()) is_pass = true;
// 		return;
// 	}
// 	for (int i = idx; i < d; i++) {
// 		memset(arr[i], true, sizeof(arr[i]));
// 		dfs(i + 1, cnt + 1);
// 		memset(arr[i], false, sizeof(arr[i]));
// 		dfs(i + 1, cnt + 1);
// 		for (int j = 0; j < w; j++)
// 			arr[i][j] = copy_arr[i][j];
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	//freopen("sample_input.txt", "r", stdin);
// 	int test_case;
// 	cin >> test_case;
// 	for (int tc = 1; tc <= test_case; tc++) {
// 		finish = 0;
// 		is_pass = false;
// 		cin >> d >> w >> k;
// 		for (int i = 0; i < d; i++) {
// 			for (int j = 0; j < w; j++) {
// 				cin >> arr[i][j];
// 				copy_arr[i][j] = arr[i][j];
// 			}
// 		}
// 		while (true) {
// 			dfs(0, 0);
// 			if (is_pass) break;
// 			finish++;
// 		}
// 		cout << "#" << tc << " " << finish << '\n';
// 	}
// 	return 0;
// }