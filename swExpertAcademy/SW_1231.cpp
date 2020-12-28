// D4 : 중위순회

#include<iostream>

using namespace std;

char t[101];
int N;

void in_order(int x);

int main(int argc, char** argv)
{
	int test_case;
	int i, nu;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		scanf("%d", &N);

		for (i = 1; i <= N; i++) {
			scanf("%d", &nu);
			scanf(" %c", &t[nu]);
			if (i < N / 2) {
				scanf("%d", &nu);
				scanf("%d", &nu);
			}
			else if (i == N / 2) {
				scanf("%d", &nu);
				if (N % 2)scanf("%d", &nu);
			}
		}

		printf("#%d ", test_case);
		in_order(1);
		printf("\n");
	}
	return 0;
}

void in_order(int x) {
	if (x > N) return;

	in_order(x * 2);
	printf("%c", t[x]);
	in_order(x * 2 + 1);
}