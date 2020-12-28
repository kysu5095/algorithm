// 다양성 측정

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

int main() {
	//freopen("sample_input (13).txt", "r", stdin);
	int test_case, cnt;
	std::string arr;
	bool jud[10];
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		memset(jud, false, sizeof(jud));
		cnt = 0;
		std::cin >> arr;
		int len = arr.size();
		for (int i = 0; i < len; i++) {
			if (jud[arr[i] - '0'] == false) {
				cnt++;
				jud[arr[i] - '0'] = true;
				if (cnt == 9)
					break;
			}
		}
		printf("#%d %d\n", tc, cnt);
	}
	return 0;
}