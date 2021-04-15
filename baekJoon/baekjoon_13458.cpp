// 시험 감독

#include <stdio.h>
#define ll long long

int n, B, C;
int arr[1000001];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
	scanf(" %d %d", &B, &C);
	ll ret = 0;
	for (int i = 0; i < n; i++) {
		ret += 1;
		arr[i] -= B;
		if (arr[i] <= 0) continue;
		if (arr[i] % C) ret += (arr[i] / C) + 1;
		else ret += (arr[i] / C);
	}
	printf("%lld\n", ret);
	return 0;
}