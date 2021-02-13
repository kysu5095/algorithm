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
        const pair<int, pair<int, int>>& node = pq.top();
        y = Find(node.second.first);
        x = Find(node.second.second);
        if(y != x){
            res += (((1L *count[y] * count[x]) % MOD) * total) % MOD;
            res %= MOD;
            parent[y] = x;
            count[x] += count[y];
        }
        total -= node.first;
        pq.pop();
    }
    cout << res << '\n';
    return 0;
}