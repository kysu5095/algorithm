// 팰린드롬
// 1:10

#include <iostream>

using namespace std;

int n, m;
int arr[2002];
bool cache[2002][2002] = { {false,}, };

void palindrome() {
	for (int i = 1; i <= n; i++)
		cache[i][i] = true;
	for (int i = 1; i < n; i++)
		if (arr[i] == arr[i + 1])
			cache[i][i + 1] = true;
	for (int i = 2; i < n; i++)
		for (int j = 1; j <= n - i; j++)
			if (arr[j] == arr[j + i] && cache[j + 1][j + i - 1])
				cache[j][j + i] = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	palindrome();
	cin >> m;
	while (m--) {
		cin >> a >> b;
		cout << cache[a][b] << '\n';
	}
	return 0;
}