#include<stdio.h>
#include<string.h>
const int maxn = 100 + 10;

int n, m, num;
int c[maxn][maxn];
int color[maxn];
int sum = 0;

bool ok(int t) {
	for (int i = 1; i <= n; ++i) {
		if (c[t][i] == 1 && color[i] == color[t])
			return false;
	}
	return true;
}

void traceback(int t) {
	if (t > n) //n个点都已经走完
	{ 
		sum++;
		for (int i = 1; i <= n; ++i)
			printf("%d ", color[i]);
		printf("\n");
	}
	else {
		for (int i = 1; i <= m; ++i) {
			color[t] = i;
			if (ok(t)) {
				traceback(t + 1);
			}
			color[t] = 0;
		}
	}
}

int main() {
	scanf("%d", &m);
	scanf("%d %d", &n, &num);
	for (int i = 1; i <= num; ++i) 
	{
		int x, y;
		scanf("%d %d", &x, &y);
		c[x][y] = c[y][x] = 1;
	}
	printf("解决方案：\n");
	traceback(1);
	if 
		(sum == 0)printf("NO\n");
	else 
		printf("一共%d钟解决方案\n", sum);
}