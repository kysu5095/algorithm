// 원재의 메모리 복구하기

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	int test_case, result;
	bool flag;
	string s;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		result = 0, flag = false;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] - '0' != flag) {
				result++;
				flag = !flag;
			}
		}
		cout << "#" << tc << " " << result << '\n';
	}
	return 0;
}