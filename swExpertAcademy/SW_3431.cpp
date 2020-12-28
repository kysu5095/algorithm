// 준환이의 운동관리

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int test_case, result;
	float L, U, X;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		result = 0;
		scanf("%f %f %f", &L, &U, &X);
		if(X >= L && X <= U)
			printf("#%d 0\n", tc);
		else if(X < L)
			printf("#%d %.0f\n", tc, L - X);
		else if(X > U)
			printf("#%d -1\n", tc);
	}
	return 0;
}