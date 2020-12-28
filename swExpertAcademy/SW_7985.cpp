// Rooted Binary Tree 재구성

#include<iostream>
#include<cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case, k;
	int arr[1025];
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		cin >> k;
		for (int i = 1; i < pow(2, k); i++)
			cin >> arr[i];
		cout << "#" << tc << " ";
		for (int i = 0; i < k; i++) {
			int start = pow(2, k - 1 - i);
			for (int j = 0; j < pow(2, i); j++) {
				int end = start + (start * 2 * j);
				cout << arr[end] << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}