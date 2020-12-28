// 연속부분최대곱  //
//////////////////

#include <iostream>
#include <cstring>

using namespace std;

int n;
double maxV = 0;
double arr[10001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fill_n(arr, sizeof(arr)/sizeof(arr[0]), 1);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] = arr[i] * arr[i - 1] > arr[i] ? arr[i] * arr[i - 1] : arr[i];
		maxV = maxV > arr[i] ? maxV : arr[i];
	}

	cout << fixed;
	cout.precision(3);
	cout << maxV << '\n';
	return 0;
}