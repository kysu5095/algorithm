#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
const int INF = 1e9;
int n1, m1, n2, m2;
int c[105][105];
vector<vector<int>> a(55, vector<int>(55, 0));
vector<vector<int>> b(55, vector<int>(55, 0));

void rotate(vector<vector<int>> &v, int &N, int &M) {
    vector<vector<int>> tmp = v;
    for(int i=1;i<=M;++i) {
        for(int j=1;j<=N;++j) {
            tmp[i][j] = v[N-j+1][i];
        }
    }
    v = tmp;
    swap(N, M);
}

// put b's left-upper side at (y, x) of a
bool solve(int y, int x) {
    for(int i=y;i<=n1;++i) {
        for(int j=x;j<=m1;++j) {
            if(a[i][j] == 0) continue;
            int k = i-y+1;
            int l = j-x+1;
            if(1<=k && k<=n2 && 1<=l && l<=m2 && b[k][l] == 1)
                return false;
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n1 >> m1;
    for(int i=1;i<=n1;++i) {
        string s; cin >> s;
        for(int j=1;j<=m1;++j) {
            a[i][j] = s[j-1] - '0';
        }
    }
    cin >> n2 >> m2;
    for(int i=1;i<=n2;++i) {
        string s; cin >> s;
        for(int j=1;j<=m2;++j) {
            b[i][j] = s[j-1] - '0';
        }
    }
    int ans = INF;
    for(int i=0;i<4;++i) {
        memset(c, 0, sizeof(c));
        for(int i=1;i<=n1;++i) for(int j=1;j<=m1;++j) c[i][j] = a[i][j];
        for(int j=0;j<4;++j) {
            for(int k=1;k<=n1+1;++k) {
                for(int l=1;l<=m1+1;++l) {
                    if(solve(k, l)) {
                        int H = max(n1, k+n2-1);
                        int W = max(m1, l+m2-1);
                        ans = min(ans, H*W);
                    }
                }
            }
            rotate(b, n2, m2);
        }
        rotate(a, n1, m1);
    }
    swap(a, b);
    swap(n1, n2);
    swap(m1, m2);
    for(int i=0;i<4;++i) {
        memset(c, 0, sizeof(c));
        for(int i=1;i<=n1;++i) for(int j=1;j<=m1;++j) c[i][j] = a[i][j];
        for(int j=0;j<4;++j) {
            for(int k=1;k<=n1+1;++k) {
                for(int l=1;l<=m1+1;++l) {
                    if(solve(k, l)) {
                        int H = max(n1, k+n2-1);
                        int W = max(m1, l+m2-1);
                        ans = min(ans, H*W);
                    }
                }
            }
            rotate(b, n2, m2);
        }
        rotate(a, n1, m1);
    }
    cout << ans << '\n';
    return 0;
}