// IQ Test

#include <iostream>

using namespace std;

int n, a, b;
int arr[51];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	if (n == 1) {
		cout << "A\n";
		return 0;
	}
	if (n == 2) {
		if (arr[0] == arr[1]) cout << arr[0] << '\n';
		else cout << "A\n";
		return 0;
	}
	if (arr[1] - arr[0]) a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
	else a = 0;
	b = arr[1] - arr[0] * a;

	return 0;
}