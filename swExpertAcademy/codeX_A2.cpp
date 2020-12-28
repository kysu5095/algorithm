// 용액-SPJ //
//////////////

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, minX, minY, minV = 2000000001;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int start = 0, last = n - 1;
	while (start != last) {
		int tmp = arr[start] + arr[last];
		if (minV > abs(tmp)) {
			minX = start;
			minY = last;
			minV = abs(tmp);
		}
		if (tmp < 0) start++;
		else last--;
	}
	cout << arr[minX] << " " << arr[minY] << '\n';

	return 0;
}