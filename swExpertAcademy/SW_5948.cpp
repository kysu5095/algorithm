// 새샘이의 7-3-5 게임

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int res_idx = 0;
bool is_exist[301];
int arr[7];
int res[211];
bool jud[7] = { false, };

void dfs(int cnt, int idx, int val) {
	if (cnt == 3) {
		if (!is_exist[val]) {
			is_exist[val] = true;
			res[res_idx++] = val;
		}
		return;
	}

	for (int i = idx; i < 7; i++) {
		if (!jud[i]) {
			jud[i] = true;
			dfs(cnt + 1, idx + 1, val + arr[i]);
			jud[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		res_idx = 0;
		memset(is_exist, false, sizeof(is_exist));
		for (int i = 0; i < 7; i++)
			cin >> arr[i];
		dfs(0, 0, 0);
		sort(res, res + res_idx);
		cout << "#" << tc << " " << res[res_idx - 5] << '\n';
	}

	return 0;
}