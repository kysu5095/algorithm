// 코딩 토너먼트1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <cmath>
#include <algorithm>

int main() {
	freopen("sample_input (16).txt", "r", stdin);
	int test_case, k, input, sum, res;
	std::queue<int> q;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		scanf("%d", &k);
		for (int i = 0; i < pow(2, k); i++) {
			scanf("%d", &input);
			q.push(input);
		}
		while (!(q.size() == 1)) {
			int tmp = q.front();
			sum = tmp;
			q.pop();
			tmp = std::max(tmp, q.front());
			sum -= q.front();
			q.pop();
			q.push(abs(tmp));
			res += abs(sum);
		}
		printf("#%d %d\n", tc, res);
		q.pop();
	}
	return 0;
}