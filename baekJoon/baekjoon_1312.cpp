// 소수

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b, n;
	cin >> a >> b >> n;
	double value = (double)a / b;
	value -= (int)value;
	for (int i = 1; i < n; i++) {
		value *= 10;
		value -= (int)value;
	}
	value *= 10;
	cout << (int)value << '\n';
	return 0;
}