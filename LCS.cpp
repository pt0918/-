#include<stdio.h>
#include<string.h>
int main() {
	const int maxn = 1000 + 10;
	char x[maxn], y[maxn];
	int dp[maxn][maxn];
	int b[maxn][maxn]; 
	char lcs[maxn];
	int n, m;
	scanf("%d", &n);
	scanf("%s", x + 1);
	scanf("%d", &m);
	scanf("%s", y + 1);
	for (int i = 0; i <= m; ++i)dp[0][i] = 0;
	for (int i = 0; i <= n; ++i)dp[i][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (x[i] == y[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					b[i][j] = 1;
					dp[i][j] = dp[i - 1][j];
				}
				else {
					b[i][j] = 2;
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
	}
	int i = n, j = m;
	while (i != 0 && j != 0) {
		if (b[i][j] == 0) {
			lcs[dp[i][j]] = x[i];
			i--, j--;
		}
		else if (b[i][j] == 1) {
			i--;
		}
		else {
			j--;
		}
	}
	printf("最长公共子序列长度为：%d\n", dp[n][m]);
	if (dp[n][m] != 0) {
		printf("最长公共子序列为：");
		for (int i = 1; i <= dp[n][m]; ++i) {
			printf("%c", lcs[i]);
		}
	}
}