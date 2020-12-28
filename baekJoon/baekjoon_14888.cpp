//  연산자 끼워넣기  //
//////////////////////


////////////////////////////////////////////
// 위 내 코드 : 시간 304ms
// 위 고친 내 코드 : 시간 0ms
// 아래 동연이형 코드 : 시간 0 ms
////////////////////////////////////////////


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int sumV = 0;
int arr[12];
int arr2[12];
int maxV = -1000000001;
int minV = 1000000001;

vector<int> v[4];

void dfs(int cnt) {
	if (cnt == n - 1) {
		sumV += arr[0];
		for (int i = 0; i < n - 1; i++) {
			if (arr2[i] == 0) {
				sumV += arr[i + 1];
			}
			else if (arr2[i] == 1) {
				sumV -= arr[i + 1];
			}
			else if (arr2[i] == 2) {
				sumV *= arr[i + 1];
			}
			else if (arr2[i] == 3) {
				sumV /= arr[i + 1];
			}
		}
		maxV = max(maxV, sumV);
		minV = min(minV, sumV);
		sumV = 0;

		return;
	}

	for (int i = 0; i < 4; i++) {
        if (v[i][0] != 0) {
            arr2[cnt] = i;
            v[i][0] -= 1;
            dfs(cnt + 1);
            v[i][0] += 1;
        }
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		int operat;
		cin >> operat;
		v[i].push_back(operat);
	}

	dfs(0);
	cout << maxV << '\n';
	cout << minV << '\n';

	return 0;
}

// #include <iostream>

// using namespace std;

// void solve(int count);
// void cal();

// int n, mx = -1000000000, mn = 1000000000, a[11], buf[4], buf2[10];

// int main()
// {
//    cin >> n;

//    for (int i = 0; i < n; i++)
//       cin >> a[i];

//    for (int i = 0; i < 4; i++)
//       cin >> buf[i];
   
//    solve(0);

//    cout << mx << "\n" << mn << endl;
// }

// void solve(int count)
// {
//    if (count == n - 1)
//    {
//       cal();

//       return;
//    }

//    for (int i = 0; i < 4; i++)
//    {
//       if (buf[i] != 0)
//       {
//          buf2[count] = i;
//          buf[i]--;
//          solve(count + 1);
//          buf[i]++;
//       }
//    }
// }

// void cal()
// {
//    int sum = a[0];

//    for (int i = 0; i < n - 1; i++)
//    {
//       switch (buf2[i])
//       {
//       case 0 :
//          sum += a[i + 1];
//          break;
//       case 1 :
//          sum -= a[i + 1];
//          break;
//       case 2 :
//          sum *= a[i + 1];
//          break;
//       case 3 :
//          sum /= a[i + 1];
//          break;
//       }
//    }

//    mx = mx > sum ? mx : sum;
//    mn = mn < sum ? mn : sum;
// }

// #include <iostream>
// #include <algorithm>

// using namespace std;

// int n, min_value = 1987654321, max_value = -9876543211;
// int arr[12] = { 0, };
// int oper[11] = { 0, };
// int tmp[11] = { 0, };

// int cal() {
// 	int tmp_value = arr[0];
// 	for (int i = 0; i < n - 1; i++) {
// 		switch (tmp[i])
// 		{
// 		case 0 :
// 			tmp_value += arr[i + 1];
// 			break;
// 		case 1 :
// 			tmp_value -= arr[i + 1];
// 			break;
// 		case 2 :
// 			tmp_value *= arr[i + 1];
// 			break;
// 		case 3 :
// 			tmp_value /= arr[i + 1];
// 			break;
// 		default:
// 			break;
// 		}
// 	}
// 	return tmp_value;
// }

// void dfs(int cnt) {
// 	if (cnt == n - 1) {
// 		int tmp_value = cal();
// 		min_value = min(min_value, tmp_value);
// 		max_value = max(max_value, tmp_value);

// 		return;
// 	}
// 	for (int i = 0; i < 4; i++) {
// 		if (oper[i] != 0) {
// 			tmp[cnt] = i;
// 			oper[i]--;
// 			dfs(cnt + 1);
// 			oper[i]++;
// 		}
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cin >> n;
// 	for (int i = 0; i < n; i++) 
// 		cin >> arr[i];
// 	for (int i = 0; i < 4; i++)
// 		cin >> oper[i];
// 	dfs(0);
// 	cout << max_value << '\n';
// 	cout << min_value << '\n';

// 	return 0;
// }