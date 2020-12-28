// 다이나믹 롤러

#include <iostream>
#define SZ 500000

using namespace std;

int n;
long long A[SZ + 1], B[SZ + 1];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int start, last, mid, res;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++)
		cin >> B[i];
	for (int i = 0; i < n; i++) {
		start = i;
		last = n - 1;
		res = 0;
		while (start < last) {
			mid = (start + last) >> 1;
			if (A[i] >= B[mid]) start = mid + 1;
			else last = mid;
		}
		cout << last << '\n';
	}
	return 0;
}