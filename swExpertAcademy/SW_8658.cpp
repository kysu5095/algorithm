// Summation

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

int main() {
	//freopen("sample_input (15).txt", "r", stdin);
	int test_case;
	std::string s;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		int maxV = -987654321, minV = 987654321, sum = 0;
		for (int i = 0; i < 10; i++) {
			std::cin >> s;
			int len = s.size();
			sum = 0;
			for (int j = 0; j < len; j++) 
				sum += s[j] - '0';

			maxV = std::max(maxV, sum);
			minV = std::min(minV, sum);
		}
		printf("#%d %d %d\n", tc, maxV, minV);
	}
	return 0;
}