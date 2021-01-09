#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int n, m, maxCost;

int mem[105], cost[105];
int maxMem[10005];
//index 비용으로 최대 value 바이트 수를 확보할 수 있다
//cost가 0에서 100 사이 값이니까 값이 다 100일 때 n이 100이면 최대 될 수 있는 cost합은 10000

/*
	5 60
	35 40 30 10 20
	5 4 3 0 3 일때

	costmem[5]=35

	costmem[9]=75
	costmem[4]= 40

	costmem[8]=65
	costmem[12]=105
	costmem[7]= 70
	costmem[3]=30
*/

int findMaxMem() {
	//전체 돌면서 만들 수 있는 조합 만들기
	for (int i = 0; i < n; i++) {
		//그동안 돈 애들로 만들 수 있는 최대 바이트 수 저장해놓고 그 안에만 돌자!
		maxCost += cost[i];

		//기존에 만든 조합에 i번째 애가 들어가서 더 최대 값을 만들 수 있냐?
		for (int j = maxCost; j > 0; j--) {
			if (maxMem[j] != 0) {
				//0이 아니면 예전에 이 값일 때 어떤지 봤었음
				maxMem[j + cost[i]] = max(maxMem[j] + mem[i], maxMem[j + cost[i]]);
			}
		}

		//i번째 애만 있는 경우에 더 최대 값을 만들 수 있냐?
		maxMem[cost[i]] = max(mem[i], maxMem[cost[i]]);
	}

	//cost가 작을 때 부터 확인하면서 원하는 크기 이상 메모리를 만들 수 있으면 반환
	for (int i = 0; i <= maxCost; i++) {
		if (maxMem[i] >= m) {
			return i;
		}
	}

	return 0;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> mem[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	cout << findMaxMem();

	return 0;
}