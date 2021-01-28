// 하이퍼 토마토

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int m, n, o, p, q, r, s, t, u, v, w, cnt = 0;
int ***********arr;
int Dm[22] = { 1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int Dn[22] = { 0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int Do[22] = { 0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int Dp[22] = { 0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int Dq[22] = { 0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0 };
int Dr[22] = { 0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0 };
int Ds[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0 };
int Dt[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0 };
int Du[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0 };
int Dv[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0 };
int Dw[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1 };

class Point {
public:
	int w, v, u, t, s, r, q, p, o, n, m;
};
queue<Point> tomato;

void Create() {
	arr = new int **********[w];
	for (int i1 = 0; i1 < w; i1++) {
		arr[i1] = new int *********[v];
		for (int i2 = 0; i2 < v; i2++) {
			arr[i1][i2] = new int ********[u];
			for (int i3 = 0; i3 < u; i3++) {
				arr[i1][i2][i3] = new int *******[t];
				for (int i4 = 0; i4 < t; i4++) {
					arr[i1][i2][i3][i4] = new int ******[s];
					for (int i5 = 0; i5 < s; i5++) {
						arr[i1][i2][i3][i4][i5] = new int *****[r];
						for (int i6 = 0; i6 < r; i6++) {
							arr[i1][i2][i3][i4][i5][i6] = new int ****[q];
							for (int i7 = 0; i7 < q; i7++) {
								arr[i1][i2][i3][i4][i5][i6][i7] = new int ***[p];
								for (int i8 = 0; i8 < p; i8++) {
									arr[i1][i2][i3][i4][i5][i6][i7][i8] = new int **[o];
									for (int i9 = 0; i9 < o; i9++) {
										arr[i1][i2][i3][i4][i5][i6][i7][i8][i9] = new int *[n];
										for (int i10 = 0; i10 < n; i10++) {
											arr[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10] = new int[m];
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void Delete() {
	for (int i1 = 0; i1 < w; i1++) {
		for (int i2 = 0; i2 < v; i2++) {
			for (int i3 = 0; i3 < u; i3++) {
				for (int i4 = 0; i4 < t; i4++) {
					for (int i5 = 0; i5 < s; i5++) {
						for (int i6 = 0; i6 < r; i6++) {
							for (int i7 = 0; i7 < q; i7++) {
								for (int i8 = 0; i8 < p; i8++) {
									for (int i9 = 0; i9 < o; i9++) {
										for (int i10 = 0; i10 < n; i10++) {
											delete arr[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10];
										}
										delete arr[i1][i2][i3][i4][i5][i6][i7][i8][i9];
									}
									delete arr[i1][i2][i3][i4][i5][i6][i7][i8];
								}
								delete arr[i1][i2][i3][i4][i5][i6][i7];
							}
							delete arr[i1][i2][i3][i4][i5][i6];
						}
						delete arr[i1][i2][i3][i4][i5];
					}
					delete arr[i1][i2][i3][i4];
				}
				delete arr[i1][i2][i3];
			}
			delete arr[i1][i2];
		}
		delete arr[i1];
	}
	delete arr;
}

int bfs() {
	int nm, nn, no, np, nq, nr, ns, nt, nu, nv, nw, len, day = 0;
	while (!tomato.empty()) {
		day++;
		len = tomato.size();
		while (len--) {
			Point point = tomato.front();
			tomato.pop();
			for (int i = 0; i < 22; i++) {
				nm = point.m + Dm[i]; nn = point.n + Dn[i];	no = point.o + Do[i];
				np = point.p + Dp[i]; nq = point.q + Dq[i];	nr = point.r + Dr[i];
				ns = point.s + Ds[i]; nt = point.t + Dt[i];	nu = point.u + Du[i];
				nv = point.v + Dv[i]; nw = point.w + Dw[i];
				if (nm < 0 || nm == m || nn < 0 || nn == n || no < 0 || no == o
				 || np < 0 || np == p || nq < 0 || nq == q || nr < 0 || nr == r
				 || ns < 0 || ns == s || nt < 0 || nt == t || nu < 0 || nu == u
				 || nv < 0 || nv == v || nw < 0 || nw == w) continue;
				if (arr[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] == 1) continue;
				if (arr[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] == -1) continue;
				tomato.push({ nw, nv, nu, nt, ns, nr, nq, np, no, nn, nm });
				arr[nw][nv][nu][nt][ns][nr][nq][np][no][nn][nm] = 1;
				cnt--;
			}
			if (!cnt) return day;
		}
	}
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> o >> p >> q >> r >> s >> t >> u >> v >> w;
	Create();
	for (int i1 = 0; i1 < w; i1++) {
		for (int i2 = 0; i2 < v; i2++) {
			for (int i3 = 0; i3 < u; i3++) {
				for (int i4 = 0; i4 < t; i4++) {
					for (int i5 = 0; i5 < s; i5++) {
						for (int i6 = 0; i6 < r; i6++) {
							for (int i7 = 0; i7 < q; i7++) {
								for (int i8 = 0; i8 < p; i8++) {
									for (int i9 = 0; i9 < o; i9++) {
										for (int i10 = 0; i10 < n; i10++) {
											for (int i11 = 0; i11 < m; i11++) {
												cin >> arr[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11];
												if (arr[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11] == 1)
													tomato.push({ i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11 });
												else if (arr[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][i11] == 0)
													cnt++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (!cnt) cout << "0\n";
	else {
		int res = bfs();
		if (res) cout << res << '\n';
		else cout << "-1\n";
	}
	Delete();
	return 0;
}