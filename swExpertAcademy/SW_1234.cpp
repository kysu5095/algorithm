// 비밀번호

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>

int main() {
	freopen("input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		std::vector<int> v;
		int n;
		int input[101];
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%1d", &input[i]);
			if (i != 0 && !v.empty() && v.back() == input[i])
				v.pop_back();
			else
				v.push_back(input[i]);
		}
		printf("#%d ", tc);
		for (int i = 0; i < v.size(); i++)
			printf("%d", v[i]);
		printf("\n");
	}
	return 0;
}