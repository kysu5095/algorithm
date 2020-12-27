// 수 이어쓰기 2

#include <iostream>
#include <string>

using namespace std;

long long calc(int n) {
	long long ans = 0;
	int len = 1, end;
	for (int i = 1; i <= n; i *= 10) {
		end = i * 10 - 1;
		if (end < n) ans += (long long)(end - i + 1) * len;
		else ans += (long long)(n - i + 1) * len;
		len++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;

	if (calc(n) < k) // n까지 이어 쓴 수의 길이가 k보다 작으면 불가능
	{
		cout << -1 << '\n';
		return 0;
	}
	int left = 1;
	int right = n;
	int ans = 0;
	while (left <= right) // 이분 탐색
	{ // 어떤 수까지를 이어 써야 k번째 수가 나오는지 확인
		int mid = (left + right) / 2;
		long long len = calc(mid);
		if (k > len)
		{
			left = mid + 1;
		}
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}
	string s = to_string(ans);
	long long l = calc(ans);
	// l - k를 구해서 마지막 수의 길이에서 뺀다.
	cout << s[s.size() - (l - k) - 1] << '\n';
	return 0;
}