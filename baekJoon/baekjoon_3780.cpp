// 네트워크 연결

#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int T, n;
char input;
int arr[200001], len[200001];

int Distance(int x) {
	if (arr[x] == x) return x;
	int idx = Distance(arr[x]);
	len[x] += len[arr[x]];
	return arr[x] = idx;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> T;
	while (T--) {
		memset(len, 0, sizeof(len));
		cin >> n;
		for (int i = 1; i <= n; i++)
			arr[i] = i;
		while (true) {
			cin >> input;
			if (input == 'O') break;
			if (input == 'E') {
				cin >> a;
				Distance(a);
				cout << len[a] << '\n';
			}
			else {
				cin >> a >> b;
				arr[a] = b;
				len[a] = abs(a - b) % 1000;
			}
		}
	}
	return 0;
}