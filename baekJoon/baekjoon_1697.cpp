//  숨바꼭질  //
///////////////

#include <iostream>
#include <queue>

using namespace std;

int n, k;
int time = 0;
queue<int> q;
bool visited[100001] = {false, };

bool isRight(int step){
    return step >= 0 && step <= 100000;
}

int bfs(void){
    q.push(n);
    visited[n] = true;

    while(!q.empty()){
        time++;
        int size = q.size();

        for(int j = 0; j < size; j++){
            int next = q.front();
            for(int i = 0; i < 3; i++){
                int step = next + 1;
                if(step == k) return time;
                if(isRight(step) && !visited[step]){
                    q.push(step);
                    visited[step] = true;
                }

                step = next - 1;
                if(step == k) return time;
                if(isRight(step) && !visited[step]){
                    q.push(step);
                    visited[step] = true;
                }

                step = next * 2;
                if(step == k) return time;
                if(isRight(step) && !visited[step]){
                    q.push(step);
                    visited[step] = true;
                }
            }
            q.pop();
        }
    }

    return time;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    if(n == k) cout << 0 << '\n';
    else cout << bfs() << '\n';

    return 0;
}