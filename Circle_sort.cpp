#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<map>
#include <iomanip>
using namespace std;
#define ll long long
int i, j, k;
int n, m;
const int inf = 0x3f3f3f;
const int mod = 1e9 + 7;
map<ll, ll> mpp[30];
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}
const int maxn = 1010;
double r[maxn], cx[maxn], a[maxn];
float minn = inf;
double getcx(int c) {
	double len = 0, t;
	for (int i = 1; i < c; i++) {
		t = cx[i] + 2 * sqrt((r[c] * r[i]));
		if (t > len)
			len = t;
	}
	return len;
}
void cal() {//计算当前圆排列的长度 
	double L = 0, R = 0;
	for (int i = 1; i <= n; i++) {
		if (cx[i] - r[i] < L)
			L = cx[i] - r[i];
		if (cx[i] + r[i] > R)
			R = cx[i] + r[i];
	}
	if ((R - L) <= minn) {
		minn = R - L;//更新最小值
		for (i = 1; i <= n; i++)//记录最优顺序
			a[i] = r[i];
	}

}
void Backtrack(int t)//回溯法 
{
	if (t == n + 1)
		cal();
	else {
		for (int i = t; i <= n; i++) {
			swap(r[t], r[i]);
			double centerx = getcx(t);
			if (r[1] + centerx + r[t] < minn) {
				cx[t] = centerx;
				Backtrack(t + 1);//到第t+1个圆
			}
			swap(r[t], r[i]);
		}
	}
}
int main() {
	cout << "请输入圆的数量:";
	cin >> n;
	cout << "请分别输入他们的半径:";
	for (i = 1; i <= n; i++)
		cin >> r[i];
	Backtrack(1);
	cout << "最小排列长度:" << minn << endl;
	cout << "最小排列组合:";
	for (i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	puts("");
	return 0;
}
