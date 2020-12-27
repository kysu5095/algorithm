// 완전 이진 트리

#include <iostream>

using namespace std;

int k, idx = 0;
int input[1025] = { 0, }, output[1025] = { 0, };
int level_idx[11] = { 0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023 };

void dfs(int level) {
	if (level == k - 1) {
		output[level_idx[level]++] = input[idx++];
		return;
	}
	dfs(level + 1);
	output[level_idx[level]++] = input[idx++];
	dfs(level + 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	for (int i = 0; i < (1 << k) - 1; i++)
		cin >> input[i];
	dfs(0);
	idx = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 1 << i; j++)
			cout << output[idx++] << " ";
		cout << '\n';
	}
	return 0;
}