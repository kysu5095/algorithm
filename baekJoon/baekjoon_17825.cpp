// 주사위 윷놀이

#include <stdio.h>
#include <vector>
using namespace std;

int res = 0;
int path_1[21], path_2[5] = { 10,13,16,19,25 }, path_3[4] = { 20,22,24,25 }, path_4[5] = { 30,28,27,26,25 };
int path_5[4] = { 25,30,35,40 }; int path_6[1] = { 40 };
int command[10];
struct Point {
	bool end;
	int path, idx;
};

//int move(int go, Point& p) {
//	int ret = 0;
//	p.idx += go;
//	switch (p.path)
//	{
//	case 1:
//		if (p.idx > 20) {
//			p.end = true;
//			break;
//		}
//		ret = path_1[p.idx];
//		if (p.idx == 5) {
//			p.path = 2;
//			p.idx = 0;
//		}
//		else if (p.idx == 10) {
//			p.path = 3;
//			p.idx = 0;
//		}
//		else if (p.idx == 15) {
//			p.path = 4;
//			p.idx = 0;
//		}
//		else if (p.idx == 20) {
//			p.path = 6;
//			p.idx = 0;
//		}
//		break;
//	case 2:
//		if (p.idx == 8) {
//			p.end = true;
//			break;
//		}
//		else if (p.idx >= 4) {
//			p.path = 5;
//			p.idx = p.idx - 4;
//			ret = path_5[p.idx];
//		}
//		else ret = path_2[p.idx];
//		break;
//	case 3:
//		if (p.idx >= 7) {
//			p.end = true;
//			break;
//		}
//		else if (p.idx >= 3) {
//			p.path = 5;
//			p.idx = p.idx - 3;
//			ret = path_5[p.idx];
//		}
//		else ret = path_3[p.idx];
//		break;
//	case 4:
//		if (p.idx == 8) {
//			p.end = true;
//			break;
//		}
//		else if (p.idx >= 4) {
//			p.path = 5;
//			p.idx = p.idx - 4;
//			ret = path_5[p.idx];
//		}
//		else ret = path_4[p.idx];
//		break;
//	case 5:
//		if (p.idx > 3) {
//			p.end = true;
//			break;
//		}
//		ret = path_5[p.idx];
//		if (p.idx == 3) {
//			p.path = 6;
//			p.idx = 0;
//		}
//		break;
//	case 6:
//		p.end = true;
//		break;
//	}
//	return ret;
//}

bool possible(Point p[4]) {
	for (int i = 0; i < 4; i++) {
		if (p[i].end) continue;
		int path = p[i].path;
		int idx = p[i].idx;
		if (path == 1 && idx == 0) continue;
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			if (p[j].end) continue;
			if (path == p[j].path && idx == p[j].idx) return false;
		}
	}
	return true;
}

int move(int go, int& idx, Point* p) {
	while (go--) {
		if (p[idx].end) return -1;
		p[idx].idx++;
		if (p[idx].path == 6 && p[idx].idx > 0) {
			p[idx].end = true;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			if (idx == i || p[idx].end) continue;
			if (p[idx].path == 1) {
				if (p[idx].idx == 5  && p[i].path == 2 && p[i].idx == 0) return -1;
				if (p[idx].idx == 10 && p[i].path == 3 && p[i].idx == 0) return -1;
				if (p[idx].idx == 15 && p[i].path == 4 && p[i].idx == 0) return -1;
				if (p[idx].idx == 20 && p[i].path == 6 && p[i].idx == 0) return -1;
				if (p[idx].idx == 20) {
					p[idx].path = 6;
					p[idx].idx = 0;
				}
			}
			else if (p[idx].path == 2) {
				if (p[idx].idx == 4) {
					p[idx].path = 5;
					p[idx].idx = 0;
				}
			}
			else if (p[idx].path == 3) {
				if (p[idx].idx == 3) {
					p[idx].path = 5;
					p[idx].idx = 0;
				}
			}
			else if (p[idx].path == 4) {
				if (p[idx].idx == 4) {
					p[idx].path = 5;
					p[idx].idx = 0;
				}
			}
			else if (p[idx].path == 5) {
				if (p[idx].idx == 3) {
					p[idx].path = 6;
					p[idx].idx = 0;
				}
			}
			if (p[idx].path == p[i].path && p[idx].idx == p[i].idx) return -1;
		}
	}
	if (p[idx].path == 1) {
		if (p[idx].idx == 5) {
			p[idx].path = 2;
			p[idx].idx = 0;
		}
		else if (p[idx].idx == 10) {
			p[idx].path = 3;
			p[idx].idx = 0;
		}
		else if (p[idx].idx == 15) {
			p[idx].path = 4;
			p[idx].idx = 0;
		}
	}

	if      (p[idx].path == 1) return path_1[p[idx].idx];
	else if (p[idx].path == 2) return path_2[p[idx].idx];
	else if (p[idx].path == 3) return path_3[p[idx].idx];
	else if (p[idx].path == 4) return path_4[p[idx].idx];
	else if (p[idx].path == 5) return path_5[p[idx].idx];
	else if (p[idx].path == 6) return path_6[p[idx].idx];
}

void dfs(int cnt, int total, Point p[4], vector<pair<pair<int, int>, pair<int, int>>> v[4]) {
	if (cnt == 10) {
		if (res < total) {
			res = total;
			printf("\ntotal : %d\n", total);
			for (int i = 0; i < 4; i++) {
				printf("%dth path\n", i);
				for (auto& node : v[i]) printf("(turn%d(%d) path : %d, idx : %d, score : %d)\n", node.first.first, command[node.first.first], node.second.first, node.second.second, node.first.second);
				printf("\n");
			}
		}
		//res = res < total ? total : res;
		return;
	}
	Point tmp;
	for (int i = 0; i < 4; i++) {
		if (p[i].end) continue;
		Point tmp = p[i];
		int score = move(command[cnt], i, p);
		if (score >= 0) {
			v[i].push_back(make_pair(make_pair(cnt, score), make_pair(p[i].path, p[i].idx)));
			dfs(cnt + 1, total + score, p, v);
			v[i].pop_back();
		}
		p[i] = tmp;
	}
}

int main() {
	for (int i = 0; i < 10; i++) scanf(" %d", &command[i]);
	for (int i = 1; i < 21; i++) path_1[i] = i * 2;
	Point p[4];
	vector<pair<pair<int, int>, pair<int, int>>> v[4];
	for (int i = 0; i < 4; i++) {
		p[i].end = false;
		p[i].path = 1;
		p[i].idx = 0;
	}
	dfs(0, 0, p, v);
	printf("%d\n", res);
	return 0;
}