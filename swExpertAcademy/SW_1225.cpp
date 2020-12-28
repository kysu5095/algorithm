// 암호 생성기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <deque>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	int test_case;
	deque<int> dq;
	for (int tc = 1; tc <= 10; tc++) {
		dq.clear();
		scanf("%d", &test_case);
		for (int i = 0; i < 8; i++) {
			scanf("%d", &test_case);
			dq.push_back(test_case);
		}

		int cnt = 0;
		while (true) {
			dq[0] -= ((cnt++ % 5) + 1);
			if (dq[0] < 0)
				dq[0] = 0;
			dq.push_back(dq.front());
			dq.pop_front();
			if (dq.back() == 0)
				break;
		}

		printf("#%d ", tc);
		for (int i = 0; i < 8; i++)
			printf("%d ", dq[i]);
		printf("\n");
	}
}