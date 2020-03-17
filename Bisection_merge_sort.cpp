#include <stdio.h>
#include <stdlib.h>
void Merge(int arr[], int p, int q, int r)
{
	int *L, *R;
	L = (int*)malloc(sizeof(int)*(q - p + 1));
	R = (int*)malloc(sizeof(int)*(r - q));
	int i = 0;
	int j = 0;
	for (i; i < q-p+1; i++)
		L[i] = arr[i + p];
	for (j; j < r-q; j++)
		R[j] = arr[j + q + 1];
	i = j = 0;
	int k = p;
	while (i != q-p+1 && j != r-q)
	{
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	while (i < q-p+1)
		arr[k++] = L[i++];
	while (j < r-q)
		arr[k++] = R[j++];
	free(L);
	free(R);
}

void MergeSort(int arr[], int p, int q)
{
	if (p < q)
	{
		int r = (p + q) / 2;
		MergeSort(arr, p, r);
		MergeSort(arr, r + 1, q);
		Merge(arr, p, r, q);
	}
}

int main()
{
	int a[8] = { 11,2,9,7,1,3,8,6 };
	MergeSort(a, 0, 7);
	for (int i; i < 8; i++)
		printf("%d ", a[i]);
	return 0;
}