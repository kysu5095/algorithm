// 전생했더니 슬라임 연구자였던 건에 대하여 (Hard)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#define MOD 1000000007
#define ll long long

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int n;
		priority_queue<ll> pq;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			ll val;
			scanf("%lld", &val);
			pq.push(-val);
		}
		ll res = 1;
		while (pq.size() > 1) {
			ll val = -pq.top();
			pq.pop();
			val *= -pq.top();
			pq.pop();
			res = res * (val % MOD) % MOD;
			pq.push(-val);
		}
		printf("%lld\n", res);
	}
	return 0;
}