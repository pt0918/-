#include<iostream>
#include<stdio.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<windows.h>
using namespace std;

struct point {
	double x;
	double y;
}P[100];
double distance(point p1, point p2) {
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}
bool cmp1(point p1, point p2) {
	return p1.x < p2.x;
}
bool cmp2(point p1, point p2) {
	return p1.y < p2.y;
}
//蛮力法
double get_min(int n)
{
	double min = sqrt((P[0].x - P[1].x)*(P[0].x - P[1].x) + (P[0].y - P[1].y)*(P[0].y - P[1].y));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double t = sqrt((P[i].x - P[j].x)*(P[i].x - P[j].x) + (P[i].y - P[j].y)*(P[i].y - P[j].y));
			if (min > t)
				min = t;
		}
	}
	return min;
}

//分治法
double nearest(point S[], int left, int right) {
	cout << left << " " << right << endl;
	if (right - left == 1) {
		return distance(S[right], S[left]);
	}
	if (right - left == 2) {
		double d1 = distance(S[right], S[left]);
		double d2 = distance(S[right], S[right + 1]);
		double d3 = distance(S[right + 1], S[left]);
		d2 = min(d1, d2);
		d3 = min(d2, d3);
		return d3;
	}
	int m = (right + left) / 2;
	double d1 = nearest(S, left, m);
	double d2 = nearest(S, m + 1, right);
	double d = min(d1, d2);
	int l = left, r = right;
	while (S[l].x < S[m].x - d && l <= right);
	l++;
	while (S[r].x > S[m].x + d && r >= left)
		r++;
	sort(S + 1, S + r + 1, cmp2);
	double d3;
	for (int i = l; i <= r; i++) {
		for (int j = i + 1; j <= r; j++) {
			if (S[j].y - S[i].y >= d) {
				break;
			}
			else {
				d3 = distance(S[i], S[j]);
				if (d3 < d)
					d = d3;
			}
		}
	}
	return d;
}
int main()
{
	int n;
	cout << "输入点的个数:";
	cin >> n;
	cout << "输入点集的坐标（x y）：\n";
	for (int i = 1; i <= n; i++) {
		cin >> P[i].x >> P[i].y;
	}
	sort(P + 1, P + n + 1, cmp1);
	for (int i = 1; i <= n; i++) {
		cout << P[i].x << " " << P[i].y << endl;
	}
	double m = get_min(n);
	cout << "蛮力法：" << endl;
	cout << m << endl;
	cout << "分治法：" << endl;
	double m2 = nearest(P, 1, n);
	cout << m2 << endl;
	system("pause");
	return 0;
}