/*
No. 1 : Tutorial : 합병(병합)정렬(Merge Sort)
[merge sort]
0. base case
1. divide
2. conquer
3. merge
4. copy
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int SIZE = 1001;

int N;
int A[SIZE], trr[SIZE];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
}

void output() {
	for (int i = 0; i < N; i++) cout << A[i] << " ";
	cout << '\n';
}

void mergeSort(int* arr, int s, int e) {
	if (s >= e) return;

	int m = (s + e) / 2;
	mergeSort(arr, s, m);
	mergeSort(arr, m + 1, e);

	int i = s, j = m + 1, k = s;
	while (i <= m && j <= e) {
		if (arr[i] <= arr[j]) trr[k++] = arr[i++];
		else trr[k++] = arr[j++];
	}
	while (i <= m) trr[k++] = arr[i++];
	while (j <= e) trr[k++] = arr[j++];

	for (int i = 0; i <= e; i++) arr[i] = trr[i];

	output();
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	input();
	mergeSort(A, 0, N - 1);
	return 0;
}