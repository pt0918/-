#include<stdio.h>
#include<string.h>
int ergodic(int t[], int len, int x) // 遍历检索
{
	for (int i = 0; i < len; i++)
	{
		if (t[i] == x)
			return i+1;
	}
	return 0;
}
int binary(int t[], int len, int x)// 二分检索
{
	int l = 0;
	int i = 0;
	while (l <= len) {
		i = l + (len - l) / 2;
		if (x < t[i])
			len = i - 1;
		else if (x > t[i])
			l = i + 1;
		else 
			return i+1;
	}
	return 0;
}
int main()
{
	int t[10] = { 1,3,4,6,8,9,10,11,14,15 };//排好序的数组T
	int x;
	scanf("%d", &x);
	printf("遍历检索:%d\n", ergodic(t, 10, x));
	printf("二分检索:%d\n", binary(t, 10, x));
	return 0;
}