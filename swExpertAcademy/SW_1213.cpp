// String

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>

int main() {
	//freopen("test_input.txt", "r", stdin);
	int test_case, cnt = 0;
	std::string s, input;
	for (int tc = 1; tc <= 10; tc++) {
		std::cin >> test_case;
		std::cin >> input;
		std::cin >> s;
		cnt = 0;
		int len = s.length() - input.length() + 1;
		for (int i = 0; i < len; i++) {
			if (s[i] == input[0]) {
				if (s.substr(i, input.length()).compare(input) == 0) {
					cnt++;
					i += (input.length() - 1);
				}
			}
		}
		std::cout << "#" << tc << " " << cnt << '\n';
	}
	return 0;
}