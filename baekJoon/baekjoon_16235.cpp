//  나무 재테크  //
//////////////////

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k;
int surviveTree = 0;
int s2d2[11][11];    
int arr[11][11];
vector<int> v[11][11];

class Point{
    public:
        int x, y;
};
Point p[8] = {{1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

void summer(int x, int y, int dead){  // 죽은 나무가 양분으로 변하기
    arr[y][x] += dead;
}

void spring(){  // 영양분 흡수하기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!v[i][j].empty()){   // 해당칸에 나무가 있을 경우
                int dead = 0;

                //////////// 나무가 한개인 경우 ////////////
                if(v[i][j].size() == 1){
                    if(v[i][j][0] <= arr[i][j]){
                        arr[i][j] -= v[i][j][0];
                        v[i][j][0] += 1;
                    }
                    else{   // 땅에있는 양분보다 나이가 많으면 죽음
                        dead += (v[i][j][0] / 2);
                        v[i][j].pop_back(); 
                    }
                }
                //////////// 나무가 두개 이상인 경우 ////////////
                else if(v[i][j].size() > 1){
                    sort(v[i][j].begin(), v[i][j].end());

                    for(int k = 0; k < v[i][j].size(); k++){
                        if(v[i][j][k] <= arr[i][j]){
                            arr[i][j] -= v[i][j][k];
                            v[i][j][k] += 1;
                        }
                        else{  // else로 들어오면 그 뒤 벡터는 다 뒤짐
                            for(int l = k; l < v[i][j].size(); l++){
                                dead += (v[i][j][l] / 2);
                            }
                            v[i][j].erase(v[i][j].begin() + k, v[i][j].end());
                            break;
                        }
                    }
                }
                summer(j, i, dead);
            }
        }
    }
}

void fall(){    // 번식하기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!v[i][j].empty()){
                for(int k = 0; k < v[i][j].size(); k++){
                    if(v[i][j][k] % 5 == 0){
                        for(int l = 0; l < 8; l++){
                            int nextX = j + p[l].x;
                            int nextY = i + p[l].y;
                            if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < n)
                                v[nextY][nextX].push_back(1);
                        }
                    }
                }
            }
        }
    }
}

void winter(){  // 땅에 양분 추가
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] += s2d2[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s2d2[i][j];
            arr[i][j] = 5;
        }
    }
    for(int i = 0; i < m; i++){
        int x, y, age;
        cin >> x >> y >> age;
        v[x - 1][y - 1].push_back(age);
    }
    for(int i = 0; i < k; i++){
        spring();
        fall();
        winter();
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!v[i][j].empty())
                surviveTree += v[i][j].size();
        }
    }

    cout << surviveTree << '\n';

    return 0;
}

// #include <iostream>
// #include <deque>
// #include <algorithm>
// #include <queue>

// using namespace std;

// int n, m, k;
// int arr[11][11] = { {0, }, };

// bool desc(int a, int b) {
// 	return a < b;
// }

// class Point {
// public:
// 	int y, x;
// };
// Point p[8] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };
// priority_queue<int, vector<int>, greater<int>> pq[11][11];

// void spring() {
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			queue<int> tmp_q;
// 			int dead = 0;
// 			while (!pq[i][j].empty()) {
// 				int tmp = pq[i][j].top();
// 				if (tmp <= arr[i][j]) {
// 					arr[i][j] -= tmp++;
// 					tmp_q.push(tmp);
// 				}
// 				else
// 					dead += (tmp / 2);
// 				pq[i][j].pop();
// 			}
// 			while (!tmp_q.empty()) {
// 				pq[i][j].push(tmp_q.front());
// 				tmp_q.pop();
// 			}
// 			arr[i][j] += dead;
// 		}
// 	}

// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			if (!pq[i][j].empty()) {

// 			}
// 		}
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int y, x, age;

// 	cin >> n >> m >> k;
// 	for (int i = 0; i < n; i++) 
// 		for (int j = 0; j < n; j++) 
// 			cin >> arr[i][j];

// 	for (int i = 0; i < m; i++) {
// 		cin >> y >> x >> age;
// 		pq[y - 1][x - 1].push(age);
// 	}
// 	while (k--)
// 		spring();

// 	return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int n, m, k;
// int arr[11][11], map[11][11];
// int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
// int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
// vector<int> v[11][11];

// void spring_and_summer() {
// 	int len, val;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			if (v[i][j].empty()) continue;
// 			sort(v[i][j].begin(), v[i][j].end());
// 			len = v[i][j].size();
// 			for (int idx = 0; idx < len; idx++) {
// 				val = v[i][j][idx];
// 				if (arr[i][j] - val >= 0) {
// 					v[i][j][idx]++;
// 					arr[i][j] -= val;
// 				}
// 				else {
// 					for (int idx2 = idx; idx2 < len; idx2++) 
// 						arr[i][j] = arr[i][j] + (v[i][j][idx2] / 2);
// 					v[i][j].erase(v[i][j].begin() + idx, v[i][j].end());
// 					break;
// 				}
// 			}
// 		}
// 	}
// }

// void fall() {
// 	int len, y, x;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			len = v[i][j].size();
// 			for (int idx = 0; idx < len; idx++) {
// 				if (v[i][j][idx] % 5 == 0) {
// 					for (int idx2 = 0; idx2 < 8; idx2++) {
// 						y = i + dy[idx2];
// 						x = j + dx[idx2];
// 						if (y < 0 || y == n || x < 0 || x == n) continue;
// 						v[y][x].push_back(1);
// 					}
// 				}
// 			}
// 		}
// 	}
// }

// void winter() {
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < n; j++)
// 			arr[i][j] += map[i][j];
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int y, x, age;
// 	cin >> n >> m >> k;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> map[i][j];
// 			arr[i][j] = 5;
// 		}
// 	}
// 	for (int i = 0; i < m; i++) {
// 		cin >> y >> x >> age;
// 		v[y - 1][x - 1].push_back(age);
// 	}
// 	while (k--) {
// 		spring_and_summer();
// 		fall();
// 		winter();
// 	}
// 	int res = 0;
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < n; j++)
// 			res += v[i][j].size();
// 	cout << res << '\n';
// 	return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int n, m, k;
// int arr[11][11], seed[11][11];
// int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
// int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
// vector<int> v[11][11];

// void spring() {
// 	int val, len;
// 	for (int y = 0; y < n; y++) {
// 		for (int x = 0; x < n; x++) {
// 			if (v[y][x].empty()) continue;
// 			sort(v[y][x].begin(), v[y][x].end());
// 			len = v[y][x].size();
// 			for (int z = 0; z < len; z++) {
// 				val = v[y][x][z];
// 				if (arr[y][x] - val < 0) {
// 					for (int idx = z; idx < len; idx++) 
// 						arr[y][x] += (v[y][x][idx] >> 1);
// 					m -= (len - z);
// 					v[y][x].erase(v[y][x].begin() + z, v[y][x].end());
// 					break;
// 				}
// 				arr[y][x] -= val;
// 				v[y][x][z] += 1;
// 			}
// 		}
// 	}
// }

// void fall() {
// 	int ny, nx, len;
// 	for (int y = 0; y < n; y++) {
// 		for (int x = 0; x < n; x++) {
// 			if (v[y][x].empty()) continue;
// 			len = v[y][x].size();
// 			for (int z = 0; z < len; z++) {
// 				if (v[y][x][z] % 5 == 0) {
// 					for (int idx = 0; idx < 8; idx++) {
// 						ny = y + dy[idx];
// 						nx = x + dx[idx];
// 						if (ny < 0 || ny == n || nx < 0 || nx == n) continue;
// 						v[ny][nx].push_back(1);
// 						m++;
// 					}
// 				}
// 			}
// 		}
// 	}
// }

// void winter() {
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < n; j++)
// 			arr[i][j] += seed[i][j];
// }

// void TREE() {
// 	while (k--) {
// 		if (!m) break;
// 		spring();
// 		fall();
// 		winter();
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int y, x, z;
// 	cin >> n >> m >> k;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> seed[i][j];
// 			arr[i][j] = 5;
// 		}
// 	}
// 	for (int i = 0; i < m; i++) {
// 		cin >> y >> x >> z;
// 		v[y - 1][x - 1].push_back(z);
// 	}
// 	TREE();
// 	cout << m << '\n';
// 	return 0;
// }