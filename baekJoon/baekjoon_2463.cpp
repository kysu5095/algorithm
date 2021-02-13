// 비용

#include <iostream>
#include <vector>
#include <queue>
#define MOD 1000000000
#define ll long long

using namespace std;

int n, m;
ll total = 0;
int parent[100001], count[100001];
priority_queue<pair<int, pair<int, int>>> pq;

void Init(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        count[i] = 1;
    }
}

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int y, int x){
    y = Find(y);
    x = Find(x);
    if(y == x) return;
    if(y > x) parent[y] = x;
    else parent[x] =y;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int x, y, w;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> w;
        if(y < x) swap(y, x);
        pq.push(make_pair(w, make_pair(y, x)));
        total += w;     
    }    
    Init();
    ll res = 0;
    while(!pq.empty()){
        y = pq.top().second.first;
        x = pq.top().second.second;
        w = pq.top().first;
        pq.pop();
        y = Find(y);
        x = Find(x);
        if(y != x){
            res += (((count[y] * count[x]) % MOD) * total) % MOD;
            res %= MOD;
            parent[y] = x;
            count[x] += count[y];
        }
        total -= w;
    }
    cout << res << '\n';
    return 0;
}