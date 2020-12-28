// 암호문1

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>

int main() {
	//freopen("input.txt", "r", stdin);
	int n, x, y, s;
	char I;
	for (int tc = 1; tc <= 10; tc++) {
		std::vector<int> v;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			v.push_back(x);
		}
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> I >> x >> y;
			for (int j = 0; j < y; j++) {
				scanf("%d", &s);
				v.insert(v.begin() + x + j, s);
			}
		}
		printf("#%d ", tc);
		for (int i = 0; i < 10; i++)
			printf("%d ", v[i]);
		printf("\n");
	}
	return 0;
}