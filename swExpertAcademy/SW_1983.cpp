// 조교의 성적 매기기
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

bool desc(double a, double b) {
	return a > b;
}

int main() {
	int test_case, n, k;
	float middle, final, project;
	char str[10][3] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };
	scanf("%d", &test_case);
	for (int t = 0; t < test_case; t++) {
		float arr[101] = { 0, };
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%f", &middle);
            scanf("%f", &final);
            scanf("%f", &project);
			arr[i] = (middle * 0.35) + (final * 0.45) + (project * 0.2);
        }
		float target = arr[k - 1];
		int cutLine = n / 10;
		int cut = 0;
		sort(arr, arr + n, desc);
		for (int i = 0; i < n; i++) {
			if (arr[i] == target) {
				printf("#%d %s\n", t + 1, str[cut]);
				break;
			}
			if ((i + 1) % cutLine == 0)
				cut++;
		}
	}
}