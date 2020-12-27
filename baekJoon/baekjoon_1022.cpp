#include <cstdio>  
#include <algorithm>  
  
int r1, c1;  
int r2, c2;  
  
const int dx[4] = { 0, -1, 0, 1 }; // 우, 상, 좌, 하  
const int dy[4] = { 1, 0, -1, 0 };  
  
int Len(int value);  
void Print(int arr[][50], int h, int w);  
void Solve();  
  
int main(void)  
{  
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);  
    Solve();  
  
    return 0;  
}  
  
// value의 길이를 계산한다.  
int Len(int value)  
{  
    int len = 0;  
    while (value > 0)  
    {  
        value /= 10;  
        len++;  
    }  
  
    return len;  
}  
  
void Print(int arr[][50], int h, int w)  
{  
    // 각 숫자들의 길이를 계산하고, 최대 길이를 찾는다.  
    int len[50][50] = { 0 };  
    int maxLen = -1;  
    for (int i = 0; i < h; i++)  
    {  
        for (int j = 0; j < w; j++)  
        {  
            len[i][j] = Len(arr[i][j]);  
            maxLen = std::max(len[i][j], maxLen);  
        }  
    }  
  
    for (int i = 0; i < h; i++)  
    {  
        for (int j = 0; j < w; j++)  
        {  
            // 숫자 사이의 공백  
            if (j > 0)  
                printf(" ");  
  
            // 길이를 맞추기 위한 공백  
            for (int k = len[i][j]; k < maxLen; k++)  
                printf(" ");  
  
            // 숫자 출력  
            printf("%d", arr[i][j]);  
        }  
        printf("\n");  
    }  
}  
  
void Solve()  
{  
    int ret[50][50] = { 0 };  
    int h = r2 - r1 + 1;  
    int w = c2 - c1 + 1;  
    int remain = h * w;  
  
    int x = 0, y = 0;  
    int dir = 0; // 이동 방향  
    int len = 1; // 이동 방향으로 몇 칸을 이동할지?  
    int value = 1; // 현재 위치에 상응하는 값  
  
    while (remain > 0)  
    {  
        for (int i = 0; i < 2; i++)  
        {  
            for (int j = 0; j < len; j++)  
            {  
                if (r1 <= x && x <= r2 && c1 <= y && y <= c2)  
                {  
                    ret[x - r1][y - c1] = value;  
                    remain--;  
                }  
  
                value++;  
                x += dx[dir];  
                y += dy[dir];  
            }  
  
            dir = (dir + 1) % 4;  
        }  
  
        len++;  
    }  
  
    Print(ret, h, w);  
}  