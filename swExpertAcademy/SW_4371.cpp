// 항구에 들어오는 배

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>

int res;
int enjoy_day[5005];

int main() {
	int test_case, n;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		std::vector<bool> v[1000000001];
		scanf(" %d", &n);
		for (int i = 0; i < n; i++)
			scanf(" %d", &enjoy_day[i]);
		for (int i = 0; i < n; i++) {
			if (v[enjoy_day[i]].empty()) {
				v[enjoy_day[i]].push_back(true);
				for (int j = enjoy_day[i]; j < v->size(); j += enjoy_day[i])
					v[j].push_back(true);
				res++;
			}
		}
		printf("#%d %d\n", tc, res);
	}
	return 0;
}