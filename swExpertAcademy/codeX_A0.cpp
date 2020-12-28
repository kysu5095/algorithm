// 배열 구간의 합 구하기 //
/////////////////////////

#include <iostream>
#include <vector>

using namespace std;

int n, q;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tmp, x, y;
	int sum = 0;
	v.push_back(0);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum += tmp;
		v.push_back(sum);
	}
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		
		cout << v[y] - v[x - 1] << '\n';
	}

	return 0;
}