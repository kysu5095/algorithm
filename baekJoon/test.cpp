#include<iostream>
#include<queue>
using namespace std;
using std::queue; using std::pair;
char tmp[105][105];
int arr[105][105], check[105][105];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0 ,0};
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
	int a, b;
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        cin >> tmp[i];
        for(int j = 0; j < b; j++)
            arr[i][j] = (tmp[i][j] - '0');
    }
	queue<pair<int,pair<int,int> > > q;
    q.push(make_pair(1, make_pair(0, 0)));
    check[0][0] = true;
	while (!q.empty())
	{
        int y = q.front().second.first;
        int x = q.front().second.second;
        int k = q.front().first;
        q.pop();
		if(y == a - 1 && x == b - 1){
            cout << k << '\n';
            return 0;
        }
		for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny == a || nx < 0 || nx == b || check[ny][nx]) continue;
            if(!arr[ny][nx]) continue;
            q.push(make_pair(k + 1, make_pair(ny, nx)));
            check[ny][nx] = true;
        }
        // if (y > 0 && arr[y - 1][x] && !check[y - 1][x])
		// {
		// 	q.push({ k + 1,{y-1,x} }); 
		// 	check[y - 1][x] = true; 
		// }
		// if (x > 0 && arr[y][x - 1] && !check[y][x - 1])
		// {
		// 	q.push({ k + 1,{y,x-1} }); 
		// 	check[y][x-1] = true; 
		// }
		// if (y + 1 < a && arr[y + 1][x] && !check[y + 1][x]) 
		// {
		// 	q.push({ k + 1,{y+1,x} });
		// 	check[y + 1][x] = true; 
		// }
		// if (x + 1 < b && arr[y][x+1] && !check[y][x+1])
		// { 
		// 	q.push({ k + 1,{y,x+1} });
		// 	check[y][x + 1] = true;
		// }
	}
    return 0;
}