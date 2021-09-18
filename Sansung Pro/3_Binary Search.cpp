#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 500004

using namespace std;

int N, Q;
int arr[MAX];

int binarySearch(int target) {
	int s = 0, e = N - 1;
	
	while (s <= e) {
		int m = (s + e) / 2;
		if (arr[m] == target) return m;
		if (arr[m] < target) s = m + 1;
		else e = m - 1;
	}
	return -1;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void query() {
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int input;
		cin >> input;
		cout << binarySearch(input) << " ";
	}
	cout << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	input();
	query();
	return 0;
}