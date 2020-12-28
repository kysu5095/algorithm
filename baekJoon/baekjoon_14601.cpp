#include <stdio.h>

int map[1 << 7][1 << 7];
int dx[4] = { 0,1,1,0 };
int dy[4] = { 0,0,1,1 };
int global_label = 1;
int n, m;
int inArea(int sy, int sx, int ey, int ex, int n, int m) {
   return sy <= n && ey >= n && sx <= m && ex >= m;
}
void coloring(int sy, int sx, int ey, int ex, int n, int m) {
   if (sy - ey == 0) return;
   int middle_y = (sy + ey) / 2;
   int middle_x = (sx + ex) / 2;

   int count = 0;
   for (int i = 0; i < 4 && count < 3; i++) {
      if (map[middle_y + dy[i]][middle_x + dx[i]] == 0) {
         if (inArea(sy, sx, ey, ex, n,m)) {
            int n_pos_y = n > middle_y;
            int n_pos_x = m > middle_x;
            if (dy[i] == n_pos_y && dx[i] == n_pos_x) {
               continue;
            }
         }
         map[middle_y + dy[i]][middle_x + dx[i]] = global_label;
         count++;
      }
   }
   int current_label = global_label;
   global_label++;
   
   if(current_label == map[middle_y][middle_x]) coloring(sy, sx, middle_y, middle_x, middle_y, middle_x);
   else coloring(sy, sx, middle_y, middle_x, n, m);

   if (current_label == map[middle_y+1][middle_x]) coloring(middle_y + 1, sx, ey, middle_x, middle_y+1, middle_x);
   else coloring(middle_y + 1, sx, ey, middle_x,n,m);

   if (current_label == map[middle_y][middle_x+1]) coloring(sy, middle_x + 1, middle_y, ex, middle_y, middle_x+1);
   else coloring(sy, middle_x + 1, middle_y, ex,n,m);

   if (current_label == map[middle_y+1][middle_x + 1]) coloring(middle_y + 1, middle_x + 1, ey, ex, middle_y+1,middle_x+1);
   else coloring(middle_y + 1, middle_x + 1, ey, ex, n, m);
}
int main() {
   int k;
   scanf("%d", &k);
   scanf("%d %d", &m, &n);
   m--, n--;
   map[n][m] = -1;
   coloring(0, 0, (1 << k) - 1, (1 << k) - 1, n,m);
   for (int j = (1 << k) - 1; j >= 0; j--) {
      for (int i = 0; i < (1 << k); i++) {
         printf("%d ", map[j][i]);
      }
      printf("\n");
   }
}