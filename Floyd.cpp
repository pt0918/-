#include<stdio.h>
using namespace std;
int main() {
	int e[10][10], k, i, j;
	int inf = 0x3f3f3f3f;
	for (i = 1; i <= 4; i++)
		for (j = 1; j <= 4; j++)
			if (i == j) e[i][j] = 0;
			else e[i][j] = inf;
	e[1][2] = 2, e[1][3] = 6, e[1][4] = 4;
	e[2][3] = 3;
	e[3][1] = 7, e[3][4] = 1;
	e[4][1] = 5, e[4][3] = 12;
	for (k = 1; k <= 4; k++)
		for (i = 1; i <= 4; i++)
			for (j = 1; j <= 4; j++)
				if (e[i][j] > e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
	//输出最终的结果
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= 4; j++) {
			printf("%d ", e[i][j]);
		}
		printf("\n");
	}
	return 0;
}