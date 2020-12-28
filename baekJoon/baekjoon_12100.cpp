// 2048 //

#include <iostream>
#include <iomanip>

using namespace std;

int n, maxV = 0;
int arr[21][21][2] = { { {0, }, }, };

void move(int d) {
	// 오른쪽
	if (d == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 2; j >= 0; j--) {
				if (arr[i][j][0] != 0) {
					int tmp = j;
					while (true) {
						tmp++;
						if (arr[i][tmp][0] == arr[i][j][0]) {
							if (arr[i][tmp][1] == 0) {
								arr[i][tmp][0] *= 2;
								arr[i][tmp][1] = 1;
								arr[i][j][0] = 0;
								break;
							}
							else {
								arr[i][tmp - 1][0] = arr[i][j][0];
								arr[i][j][0] = 0;
								break;
							}
						}
						if (arr[i][tmp][0] != 0) {
							if (tmp == j + 1) break;
							arr[i][tmp - 1][0] = arr[i][j][0];
							arr[i][j][0] = 0;
							break;
						}
						if (tmp == n - 1) {
							arr[i][tmp][0] = arr[i][j][0];
							arr[i][j][0] = 0;
							break;
						}
					}
				}
			}
		}
	}
	// 왼쪽
	else if (d == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (arr[i][j][0] != 0) {
					int tmp = j;
					while (true) {
						tmp--;
						if (arr[i][tmp][0] == arr[i][j][0]) {
							if (arr[i][tmp][1] == 0) {
								arr[i][tmp][0] *= 2;
								arr[i][tmp][1] = 1;
								arr[i][j][0] = 0;
								break;
							}
							else {
								arr[i][tmp + 1][0] = arr[i][j][0];
								arr[i][j][0] = 0;
								break;
							}
						}
						if (arr[i][tmp][0] != 0) {
							if (tmp == j - 1) break;
							arr[i][tmp + 1][0] = arr[i][j][0];
							arr[i][j][0] = 0;
							break;
						}
						if (tmp == 0) {
							arr[i][tmp][0] = arr[i][j][0];
							arr[i][j][0] = 0;
							break;
						}
					}
				}
			}
		}
	}
	// 아래쪽
	else if (d == 2) {
		for (int j = 0; j < n; j++) {
			for (int i = n - 2; i >= 0; i--) {
				if (arr[i][j][0] != 0) {
					int tmp = i;
					while (true) {
						tmp++;
						if (arr[tmp][j][0] == arr[i][j][0]) {
							if (arr[tmp][j][1] == 0) {
								arr[tmp][j][0] *= 2;
								arr[tmp][j][1] = 1;
								arr[i][j][0] = 0;
								break;
							}
							else {
								arr[tmp - 1][j][0] = arr[i][j][0];
								arr[i][j][0] = 0;
								break;
							}
						}
						if (arr[tmp][j][0] != 0) {
							if (tmp == i + 1) break;
							arr[tmp - 1][j][0] = arr[i][j][0];
							arr[i][j][0] = 0;
							break;
						}
						if (tmp == n - 1) {
							arr[tmp][j][0] = arr[i][j][0];
							arr[i][j][0] = 0;
							break;
						}
					}
				}
			}
		}
	}
	// 위쪽
	else if (d == 3) {
		for (int j = 0; j < n; j++) {
			for (int i = 1; i < n; i++) {
				if (arr[i][j][0] != 0) {
					int tmp = i;
					while (true) {
						tmp--;
						if (arr[tmp][j][0] == arr[i][j][0]) {
							if (arr[tmp][j][1] == 0) {
								arr[tmp][j][0] *= 2;
								arr[tmp][j][1] = 1;
								arr[i][j][0] = 0;
								break;
							}
							else {
								arr[tmp + 1][j][0] = arr[i][j][0];
								arr[i][j][0] = 0;
								break;
							}
						}
						if (arr[tmp][j][0] != 0) {
							if (tmp == i - 1) break;
							arr[tmp + 1][j][0] = arr[i][j][0];
							arr[i][j][0] = 0;
							break;
						}
						if (tmp == 0) {
							arr[tmp][j][0] = arr[i][j][0];
							arr[i][j][0] = 0;
							break;
						}
					}
				}
			}
		}
	}
}

void copyArray(int a[][21][2], int b[][21][2]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j][0] = b[i][j][0];
			arr[i][j][1] = 0;
		}
	}
}

void dfs(int cnt, int Arr[][21][2]) {
	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j][0] != 0)
					maxV = maxV < arr[i][j][0] ? arr[i][j][0] : maxV;
			}
		}
		return;
	}
	int copyArr[21][21][2] = { { {0, }, }, };
	copyArray(copyArr, arr);
	for (int i = 0; i < 4; i++) {
		move(i);
		dfs(cnt + 1, arr);
		copyArray(arr, copyArr);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j][0];
		}
	}
	dfs(0, arr);
	cout << maxV << '\n';

	return 0;
}

// #include <iostream>

// using namespace std;

// int n, max_value = 0;
// int arr[21][21][2] = { { {0, }, }, };

// void copyArr(int arrA[][21][2], int arrB[][21][2]) {
// 	for (int i = 0; i < 21; i++) {
// 		for (int j = 0; j < 21; j++) {
// 			arrA[i][j][0] = arrB[i][j][0];
// 			arr[i][j][1] = 0;
// 		}
// 	}
// }

// void rotate(int cnt) {
// 	int tmp[21][21] = { {0, }, };
// 	for (int k = 0; k < cnt; k++) {
// 		// copy
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < n; j++) {
// 				tmp[i][j] = arr[i][j][0];
// 			}
// 		}
// 		// turn right
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < n; j++) {
// 				arr[i][j][0] = tmp[n - 1 - j][i];
// 			}
// 		}
// 	}
// }

// void cal() {
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 1; j < n; j++) {
// 			if (arr[i][j][0] != 0) {
// 				int tmp = j;
// 				while (true) {
// 					tmp--;
// 					// 앞 숫자와 동일한 숫자일 경우
// 					if (arr[i][tmp][0] == arr[i][j][0]) {
// 						// 겹쳐진 적이 없는 경우
// 						if (arr[i][tmp][1] == 0) {
// 							arr[i][tmp][0] *= 2;
// 							arr[i][tmp][1] = 1;
// 							arr[i][j][0] = 0;
// 							break;
// 						}
// 						// 겹쳐진 적이 있는 경우
// 						else {
// 							arr[i][tmp + 1][0] = arr[i][j][0];
// 							arr[i][j][0] = 0;
// 							break;
// 						}
// 					}
// 					// 앞 숫자가 다른 숫자일 경우
// 					if (arr[i][tmp][0] != 0) {
// 						if (tmp == j - 1) break;
// 						arr[i][tmp + 1][0] = arr[i][j][0];
// 						arr[i][j][0] = 0;
// 						break;
// 					}
// 					// 끝까지 왔을 경우
// 					if (tmp == 0) {
// 						arr[i][tmp][0] = arr[i][j][0];
// 						arr[i][j][0] = 0;
// 						break;
// 					}
// 				}
// 			}
// 		}
// 	}
// }

// void dfs(int cnt) {
// 	if (cnt == 5) {
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < n; j++) {
// 				max_value = max_value < arr[i][j][0] ? arr[i][j][0] : max_value;
// 			}
// 		}
// 		return;
// 	}
// 	int tmpArr[21][21][2] = { { {0,}, }, };
// 	copyArr(tmpArr, arr);
// 	for (int i = 0; i < 4; i++) {
// 		rotate(i);
// 		cal();
// 		dfs(cnt + 1);
// 		copyArr(arr, tmpArr);
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> arr[i][j][0];
// 		}
// 	}
// 	dfs(0);
// 	cout << max_value << '\n';

// 	return 0;
// }

// 2048(Easy)

// #include <iostream>
// #include <string.h>
// #include <algorithm>

// using namespace std;

// int n, res = 0;
// int arr[21][21];
// int map[21][21];
// int tmp[21][21];
// int sequence[5] = { 0, };
// bool visited[21][21];
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };

// // 시계방향으로 direct번 만큼 90도 회전
// void rotation(int& direct) {
// 	for (int ro = 0; ro < direct; ro++) {
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < n; j++)
// 				tmp[i][j] = arr[n - 1 - j][i];
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < n; j++)
// 				arr[i][j] = tmp[i][j];
// 	}
// }

// // 반시계방향으로 direct번 만큼 90도 회전
// void derotation(int& direct) {
// 	for (int ro = 0; ro < direct; ro++) {
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < n; j++)
// 				tmp[i][j] = arr[j][n - 1 - i];
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < n; j++)
// 				arr[i][j] = tmp[i][j];
// 	}
// }

// void move() {
// 	int val, x;
// 	for (int i = 0; i < n; i++) {
// 		// 끝에 있는 원소부터 왼쪽으로 탐색
// 		for (int j = n - 2; j >= 0; j--) {
// 			if (!arr[i][j]) continue;
// 			val = arr[i][j];
// 			arr[i][j] = 0;
// 			x = j + 1;
// 			while (true) {
// 				// 끝까지 왔을경우
// 				if (x == n) {
// 					arr[i][x - 1] = val;
// 					break;
// 				}
// 				// 다음칸에 원소가 있을경우
// 				if (arr[i][x]) {
// 					// 현재값과 다음원소가 값이 같을 경우
// 					if (arr[i][x] == val) {
// 						// 이미 이전에 합쳐진 경우
// 						if (visited[i][x]) 
// 							arr[i][x - 1] = val;
// 						// 합쳐진적이 없어 합쳐야 함
// 						else {
// 							arr[i][x] <<= 1;
// 							visited[i][x] = true;
// 						}
// 					}
// 					// 현재값과 다음원소가 값이 다를 경우
// 					else {
// 						arr[i][x - 1] = val;
// 					}
// 					break;
// 				}
// 				x++;
// 			}
// 		}
// 	}
// }

// void dfs(int cnt) {
// 	if (cnt == 5) {
// 		for (int i = 0; i < 5; i++) {
// 			memset(visited, false, sizeof(visited));
// 			rotation(sequence[i]);   // 회전
// 			move();					 // 이동
// 			derotation(sequence[i]); // 원상복귀
// 		}
// 		int ret = 0;
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < n; j++)
// 				ret = max(ret, arr[i][j]);
// 		res = max(res, ret);
// 		memcpy(arr, map, sizeof(map));
// 		return;
// 	}
// 	// 회전 순서 구하기
// 	for (int i = 0; i < 4; i++) {
// 		sequence[cnt] = i;
// 		dfs(cnt + 1);
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> n;
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < n; j++)
// 			cin >> arr[i][j], map[i][j] = arr[i][j];
// 	dfs(0);
// 	cout << res << '\n';
// 	return 0;
// }

// #include <iostream>
// #include <algorithm>

// using namespace std;

// int n, res = 0;
// int arr[21][21], copy_arr[21][21];

// void turn_arr(int& cnt) {
// 	for (int tc = 0; tc < cnt; tc++) {
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < n; j++)
// 				copy_arr[i][j] = arr[n - j - 1][i];
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < n; j++)
// 				arr[i][j] = copy_arr[i][j];
// 	}
// }

// void return_arr(int& cnt) {
// 	for (int tc = 0; tc < cnt; tc++) {
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < n; j++)
// 				copy_arr[i][j] = arr[j][n - i - 1];
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < n; j++)
// 				arr[i][j] = copy_arr[i][j];
// 	}
// }

// void move() {
// 	bool visited[21][21] = { {false,}, };
// 	for (int y = 0; y < n; y++) {
// 		int x, _x = 1;
// 		while (_x != n) {
// 			if (arr[y][_x] == 0) { _x++; continue; }
// 			int val = arr[y][_x];
// 			arr[y][_x] = 0;
// 			x = _x - 1;
// 			while (x >= 0) {
// 				if (arr[y][x]) {
// 					if (val == arr[y][x]) {
// 						if (visited[y][x]) arr[y][x + 1] = val;
// 						else {
// 							arr[y][x] <<= 1;
// 							visited[y][x] = true;
// 						}
// 						break;
// 					}
// 					else {
// 						arr[y][x + 1] = val;
// 						break;
// 					}
// 				}
// 				else {
// 					if (x == 0) arr[y][x] = val;
// 					x--;
// 				}
// 			}
// 			_x++;
// 		}
// 	}
// }

// void dfs(int d, int cnt) {
// 	if (cnt == 5) {
// 		for (int i = 0; i < n; i++)
// 			for (int j = 0; j < n; j++)
// 				res = max(res, arr[i][j]);
// 		return;
// 	}
// 	turn_arr(d);
// 	move();
// 	return_arr(d);

// 	int tmp[21][21];
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < n; j++)
// 			tmp[i][j] = arr[i][j];

// 	for (int i = 0; i < 4; i++) {
// 		dfs(i, cnt + 1);
// 		for (int j = 0; j < n; j++)
// 			for (int k = 0; k < n; k++)
// 				arr[j][k] = tmp[j][k];
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int tmp[21][21];
// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> arr[i][j];
// 			tmp[i][j] = arr[i][j];
// 			res = max(res, arr[i][j]);
// 		}
// 	}
// 	for (int i = 0; i < 4; i++) {
// 		dfs(i, 0);
// 		for (int j = 0; j < n; j++)
// 			for (int k = 0; k < n; k++)
// 				arr[j][k] = tmp[j][k];
// 	}
// 	cout << res << '\n';
// 	return 0;
// }
