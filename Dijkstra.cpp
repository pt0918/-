#include<iostream>
using namespace std;

const int inf = 0x3f3f3f3f;
int edge[9][9] = {
	{-1, -1, -1, -1, -1, -1, -1, -1, -1},
	{-1,  0,  1,inf,inf,inf,inf,inf,inf},
	{-1,inf,  0,inf,  2,inf,inf,inf,inf},
	{-1,  2,inf,  0,inf,inf,inf,inf,inf},
	{-1,inf,inf,  1,  0,inf,  8,inf,inf},
	{-1,inf,inf,inf,  2,  0,inf,  2,inf},
	{-1,inf,inf,inf,inf,  2,  0,inf,inf},
	{-1,inf,inf,inf,inf,inf,  3,  0,  3},
	{-1,inf,inf,inf,inf,inf,  3,inf,  0}
};
int main() {
	const int n = 8;
	int dis[n + 1];
	int book[n + 1];
	for (int i = 1; i <= n; ++i)
		dis[i] = edge[1][i];
	memset(book, 0, sizeof(book));
	book[1] = 1;
	int min;
	for (int i = 1; i <= n - 1; ++i) {
		min = inf;
		int u;
		for (int j = 1; j <= n; ++j) {
			if (book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (int v = 1; v <= n; ++v) {
			if (edge[u][v] < inf) {
				if (dis[v] > dis[u] + edge[u][v])
					dis[v] = dis[u] + edge[u][v];
			}
		}
	}
	for (int i = 1; i <= n; ++i) cout << dis[i] << ' ';
	return 0;
}