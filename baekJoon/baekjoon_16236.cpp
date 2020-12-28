// 아기상어 //
/////////////

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, mom = 0; // mom : 엄마상어를 부르는 시간
int maxX = 32, maxY = 32; // 가장 좌측 && 위쪽에 존재하는 먹을수있는 물고기 좌표
int arr[21][21] = { {0,}, };
bool visited[21][21] = { {false, }, };

class Point {
public:
	int x, y, size, cnt, eat; // cnt : 이동한 칸의 개수, eat : 먹은 물고기의 개수
};
Point p[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
deque<Point> shark;

void bfs() {
	while (!shark.empty()) {
		int x = shark.front().x;
		int y = shark.front().y;
		int size = shark.front().size;
		int cnt = shark.front().cnt;
		int eat = shark.front().eat;

		for (int i = 0; i < 4; i++) {
			int nx = x + p[i].x;
			int ny = y + p[i].y;
			// 범위 안에 있으며 방문하지 않았고 해당 물고기가 아기상어보다 크기가 작거나 같은 경우
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx] && arr[ny][nx] <= size) {
				//cout << cnt + 1 << "번째 물고기   " << ny << " " << nx << " " << arr[ny][nx] << '\n';
				visited[ny][nx] = true;
				shark.push_back({ nx, ny, size, cnt + 1, eat });
				// 물고기가 존재
				if (arr[ny][nx] != 0) {
					// 해당 물고기가 아기상어보다 크기가 작으면 먹을수 있다
					// 가장 좌측 && 위쪽 물고기의 좌표를 구한다
					if (arr[ny][nx] < size) {
						if (ny <= maxY) {
							if (ny < maxY) {
								maxX = nx;
								maxY = ny;
							}
							else {
								if (nx < maxX) {
									maxX = nx;
									maxY = ny;
								}
							}
						}
					}
				}
			}
		}
		shark.pop_front();
		// 큐의 한depth(cnt)를 다 돌았고, 먹을수있는 물고기가 있을경우
		if (!shark.empty() && shark.front().cnt != cnt && maxX != 32 && maxY != 32) {
			//cout << "물고기 먹음  " << maxY << " " << maxX;
			shark.clear();
			eat++;
			// 아기상어 크기 조작
			if (eat == size) 
				shark.push_back({ maxX, maxY, size + 1, cnt + 1, 0 });
			else 
				shark.push_back({ maxX, maxY, size, cnt + 1, eat });
			//cout << "  size : " << shark.front().size << "  eat : " << shark.front().eat << '\n';

			// 큐 초기화 후 먹은 물고기로 아기상어 이동
			// 배열, 초기값 초기화
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					visited[i][j] = false;
				}
			}
			visited[maxY][maxX] = true;
			arr[maxY][maxX] = 0;
			maxX = 32;
			maxY = 32;
			mom = shark.front().cnt;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				arr[i][j] = 0;
				shark.push_back({ j, i, 2, 0, 0 });
				visited[i][j] = true;
			}
		}
	}
	bfs();
	cout << mom << '\n';

	return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <string.h>
// #include <queue>
// #include <deque>

// using namespace std;

// int n, sec = 0;
// int arr[21][21] = { {0, }, };
// bool visited[21][21] = { {false, }, };

// class Point {
// public:
// 	int y, x, size;
// };
// Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
// deque<Point> fish;

// class Shark {
// public:
// 	int y, x, size, cnt, depth;
// };
// Shark shark;

// bool desc(Point p1, Point p2) {
// 	return p1.size < p2.size;
// }

// bool desc2(Point p1, Point p2) {
// 	if (p1.y < p2.y) return true;
// 	else if (p1.y == p2.y) {
// 		if (p1.x < p2.x) return true;
// 		else return false;
// 	}
// 	else return false;
// }

// bool bfs() {
// 	vector<Point> v;
// 	queue<Shark> q;
// 	q.push(shark);
// 	visited[shark.y][shark.x] = true;
// 	int y, x, size, cnt, depth;
// 	int ny, nx;
// 	while (!q.empty()) {
// 		y = q.front().y, x = q.front().x;
// 		size = q.front().size;
// 		cnt = q.front().cnt;
// 		depth = q.front().depth;

// 		for (int i = 0; i < 4; i++) {
// 			ny = y + p[i].y;
// 			nx = x + p[i].x;
// 			if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && arr[ny][nx] <= size) {
// 				visited[ny][nx] = true;
// 				q.push({ ny, nx, size, cnt, depth + 1 });

// 				if (arr[ny][nx] != 0 && arr[ny][nx] < size)
// 					v.push_back({ ny, nx });
// 			}
// 		}
// 		q.pop();
// 		if (!q.empty() && !v.empty() && q.front().depth != depth) {
// 			sort(v.begin(), v.end(), desc2);
// 			int _y = v[0].y, _x = v[0].x;
// 			arr[_y][_x] = 9;
// 			arr[shark.y][shark.x] = 0;
// 			for (int i = 0; i < fish.size(); i++) {
// 				if (_y == fish[i].y && _x == fish[i].x)
// 					fish.erase(fish.begin() + i);
// 			}

// 			shark.y = _y, shark.x = _x;
// 			shark.cnt++;
// 			if (shark.cnt == shark.size) {
// 				shark.cnt = 0;
// 				shark.size++;
// 			}
// 			sec += depth + 1;
// 			return true;
// 		}
// 	}
// 	return false;
// }

// void eat() {
// 	deque<Point> tmp;
// 	while (true) {
// 		if (fish.empty()) return;
// 		tmp.clear();
// 		tmp.assign(fish.begin(), fish.end());
// 		sort(tmp.begin(), tmp.end(), desc);
// 		if (tmp[0].size >= shark.size) return;
// 		if (!bfs()) return;
// 		memset(visited, false, sizeof(visited));
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> arr[i][j];
// 			if (arr[i][j] == 9) {
// 				shark.y = i, shark.x = j;
// 				shark.size = 2, shark.cnt = 0;
// 				shark.depth = 0;
// 			}
// 			if (arr[i][j] != 0 && arr[i][j] != 9)
// 				fish.push_back({ i, j, arr[i][j] });
// 		}
// 	}
// 	eat();
// 	cout << sec << '\n';

// 	return 0;
// }

// 아기 상어
// 11:30

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <string.h>
// #include <algorithm>

// using namespace std;

// int n, res;
// int arr[21][21];
// bool visited[21][21];

// class Point {
// public:
// 	int y, x, cnt;

// 	bool operator < (const Point &p) const {
// 		if (y < p.y) return false;
// 		else if (y == p.y) {
// 			if (x < p.x) return false;
// 			else return true;
// 		}
// 		else return true;
// 	}
// };
// Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
// vector<Point> fish;
// int sy, sx, ss, sc;

// bool desc(Point p1, Point p2) {
// 	return p1.cnt < p2.cnt;
// }

// bool bfs() {
// 	priority_queue<Point> pq;
// 	queue<Point> q;
// 	q.push({ sy, sx, 0 });
// 	visited[sy][sx] = true;
// 	int y, x, cnt, ny, nx;
// 	while (!q.empty()) {
// 		y = q.front().y;
// 		x = q.front().x;
// 		cnt = q.front().cnt;
// 		q.pop();
// 		for (int i = 0; i < 4; i++) {
// 			ny = y + p[i].y;
// 			nx = x + p[i].x;
// 			if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && ss >= arr[ny][nx]) {
// 				q.push({ ny, nx, cnt + 1 });
// 				visited[ny][nx] = true;
// 				// 크기 같은 경우
// 				if (!arr[ny][nx] || ss == arr[ny][nx]) continue;
// 				// 상어보다 작은 물고기
// 				pq.push({ ny, nx });
// 			}
// 		}

// 		if (!pq.empty() && !q.empty() && q.front().cnt != cnt) {
// 			res += (cnt + 1);
// 			sy = pq.top().y, sx = pq.top().x;
// 			arr[sy][sx] = 0;
// 			if (ss == sc + 1) {
// 				ss++;
// 				sc = 0;
// 			}
// 			else
// 				sc++;
// 			for (int i = 0; i < fish.size(); i++) {
// 				if (sy == fish[i].y && sx == fish[i].x) {
// 					fish.erase(fish.begin() + i);
// 					break;
// 				}
// 			}
// 			return false;
// 		}
// 	}
// 	return true;
// }

// void move() {
// 	while (true) {
// 		if (fish.empty()) break;
// 		sort(fish.begin(), fish.end(), desc);
// 		if (fish[0].cnt >= ss) break;
// 		if (bfs()) break;
// 		memset(visited, false, sizeof(visited));
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> arr[i][j];
// 			if (arr[i][j] == 9) {
// 				sy = i, sx = j;
// 				ss = 2, sc = 0;
// 				arr[i][j] = 0;
// 			}
// 			else if (arr[i][j] >= 1 && arr[i][j] <= 6)
// 				fish.push_back({ i, j, arr[i][j]});
// 		}
// 	}
// 	move();
// 	cout << res << '\n';
// 	return 0;
// }

//  #include <iostream>
//  #include <vector>
//  #include <queue>
//  #include <string.h>
//  #include <algorithm>

//  using namespace std;

//  int n, res;
//  int arr[21][21];
//  bool visited[21][21];

//  class Point {
//  public:
//  	int y, x;

//  	bool operator < (const Point &p) const {
//  		if (y < p.y) return false;
//  		else if (y == p.y) {
// 			if (x < p.x) return false;
//  			else return true;
//  		}
//  		else return true;
//  	}
//  };
//  Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
//  vector<Point> fish;
//  int sy, sx, ss, sc;

//  bool desc(Point p1, Point p2) {
// 	 return arr[p1.y][p1.x] < arr[p2.y][p2.x];
//  }

//  bool bfs() {
//  	queue<pair<int, int>> q;
//  	q.push(make_pair(sy, sx));
//  	visited[sy][sx] = true;
//  	int y, x, ny, nx, len, t = 0;
//  	while (!q.empty()) {
// 		priority_queue<Point> pq;
// 		len = q.size();
// 		t++;
// 		while (len--) {
// 			y = q.front().first;
// 			x = q.front().second;
// 			q.pop();
// 			for (int i = 0; i < 4; i++) {
// 				ny = y + p[i].y;
// 				nx = x + p[i].x;
// 				if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && ss >= arr[ny][nx]) {
// 					q.push(make_pair(ny, nx));
// 					visited[ny][nx] = true;
// 					// 크기 같은 경우
// 					if (!arr[ny][nx] || ss == arr[ny][nx]) continue;
// 					// 상어보다 작은 물고기
// 					pq.push({ ny, nx });
// 				}
// 			}
// 		}
// 		if (!pq.empty()) {
// 			res += t;
// 			sy = pq.top().y;
// 			sx = pq.top().x;
// 			arr[sy][sx] = 0;
// 			if (ss == sc + 1) {
// 				ss++;
// 				sc &= 0;
// 			}
// 			else
// 				sc++;

// 			for (int i = 0; i < fish.size(); i++) {
// 				if (sy == fish[i].y && sx == fish[i].x) {
// 					fish.erase(fish.begin() + i);
// 					break;
// 				}
// 			}
// 			return false;
// 		}
//  	}
//  	return true;
//  }

//  void move() {
//  	while (true) {
// 		// 먹을 물고기 없을 경우
//  		if (fish.empty()) break;
//  		sort(fish.begin(), fish.end(), desc);
// 		// 남아 있는 물고기중 아기상어보다 작은 물고기가 없을 경우
//  		if (arr[fish[0].y][fish[0].x] >= ss) break;
// 		// 물고기를 먹으러 갈 수 없을 경우
//  		if (bfs()) break;
//  		memset(visited, false, sizeof(visited));
//  	}
//  }

//  int main() {
//  	ios_base::sync_with_stdio(false);
//  	cin.tie(NULL);
//  	cin >> n;
//  	for (int i = 0; i < n; i++) {
//  		for (int j = 0; j < n; j++) {
//  			cin >> arr[i][j];
//  			if (arr[i][j] == 9) {
//  				sy = i, sx = j;
//  				ss = 2, sc = 0;
//  				arr[i][j] = 0;
//  			}
//  			else if (arr[i][j] >= 1 && arr[i][j] <= 6)
//  				fish.push_back({ i, j });
//  		}
//  	}
//  	move();
//  	cout << res << '\n';
//  	return 0;
//  }

// #include <iostream>
// #include <queue>
// #include <string.h>
// #include <algorithm>

// using namespace std;

// int n;
// int arr[21][21];
// bool visited[21][21];
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };

// class Fish {
// public:
// 	int y, x;
// 	bool operator < (const Fish& fish) const {
// 		if (y < fish.y) return true;
// 		else if (y == fish.y) {
// 			if (x < fish.x) return true;
// 			else return false;
// 		}
// 		else return false;
// 	}
// };

// int bfs(int y, int x) {
// 	int ny, nx, len, sz = 2, cnt = 0, sec, res = 0;
// 	bool flag;
// 	while (true) {
// 		memset(visited, false, sizeof(visited));
// 		vector<Fish> v;
// 		queue<pair<int, int>> q;
// 		q.push(make_pair(y, x));
// 		visited[y][x] = true;
// 		flag = false;
// 		sec = 0;
// 		while (!q.empty()) {
// 			sec++;
// 			len = q.size();
// 			while (len--) {
// 				y = q.front().first;
// 				x = q.front().second;
// 				q.pop();
// 				for (int i = 0; i < 4; i++) {
// 					ny = y + dy[i];
// 					nx = x + dx[i];
// 					if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx]) continue;
// 					if (arr[ny][nx] > sz) continue;
// 					else if (arr[ny][nx] == sz || !arr[ny][nx]) q.push(make_pair(ny, nx));
// 					else v.push_back({ ny, nx });
// 					visited[ny][nx] = true;
// 				}
// 			}
// 			if (v.size()) {
// 				sort(v.begin(), v.end());
// 				y = v[0].y;
// 				x = v[0].x;
// 				if (++cnt == sz) { sz++; cnt = 0; }
// 				arr[y][x] = 0;
// 				flag = true;
// 				res += sec;
// 				break;
// 			}
// 		}
// 		if (!flag) return res;
// 	}
// }

// int main() { 
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	int sy, sx;
// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> arr[i][j];
// 			if (arr[i][j] == 9) {
// 				sy = i;
// 				sx = j;
// 				arr[i][j] = 0;
// 			}
// 		}
// 	}
// 	cout << bfs(sy, sx) << '\n';
// 	return 0;
// }

// #include <iostream>
// #include <queue>
// #include <string.h>
// #include <algorithm>

// using namespace std;

// int y, x;
// int n, sz = 2, cnt = 0;
// int arr[21][21];
// int fish_cnt[7] = { 0, };
// bool visited[21][21];
// int dy[4] = { 0, 0, 1, -1 };
// int dx[4] = { 1, -1, 0, 0 };

// int bfs() {
// 	memset(visited, false, sizeof(visited));
// 	int ny, nx, len, sec = 0;
// 	vector<pair<int, int>> v;
// 	queue<pair<int, int>> q;
// 	q.push(make_pair(y, x));
// 	visited[y][x] = true;
// 	while (!q.empty()) {
// 		sec++;
// 		len = q.size();
// 		while (len--) {
// 			y = q.front().first;
// 			x = q.front().second;
// 			q.pop();
// 			for (int i = 0; i < 4; i++) {
// 				ny = y + dy[i];
// 				nx = x + dx[i];
// 				if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx] || arr[ny][nx] > sz) continue;
// 				if (arr[ny][nx] != 0 && arr[ny][nx] < sz) v.push_back(make_pair(ny, nx));
// 				q.push(make_pair(ny, nx));
// 				visited[ny][nx] = true;
// 			}
// 		}
// 		if (!v.empty()) {
// 			sort(v.begin(), v.end());
// 			y = v[0].first;
// 			x = v[0].second;
// 			if (++cnt == sz) {
// 				sz++;
// 				cnt = 0;
// 			}
// 			fish_cnt[arr[y][x]]--;
// 			arr[y][x] = 0;
// 			return sec;
// 		}
// 	}
// 	return -1;
// }

// int SHARK() {
// 	int val;
// 	int sec = 0;
// 	bool flag;
// 	while (true) {
// 		flag = true;
// 		for (int i = 1; i < sz && i < 7; i++) {
// 			if (fish_cnt[i]) {
// 				flag = false;
// 				break;
// 			}
// 		}
// 		if (flag) return sec;
// 		val = bfs();
// 		if (val == -1) return sec;
// 		sec += val;
// 	}
// }

// int main() {
// 	cin.sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			cin >> arr[i][j];
// 			if (arr[i][j] == 9) {
// 				y = i;
// 				x = j;
// 				arr[i][j] = 0;
// 			}
// 			else if (arr[i][j] >= 1 && arr[i][j] <= 6) fish_cnt[arr[i][j]]++;
// 		}
// 	}
// 	cout << SHARK() << '\n';
// 	return 0;
// }