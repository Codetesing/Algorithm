#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// swap
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int LOG(int n)
{
	int temp = 1;
	
	for (int i = 0; ; i++, temp *= 2)
		if (temp == n)
			return i;
}

// �� �������� ����
void PARALLEL_SORT_1D_array_ROW_UP(int t, int n, int* arr)
{
	if (t == n)
		return;


	// �õ� Ƚ���� ¦���̸� 0������ 2���� sort, Ȧ���̸� 1������ 2���� sort. (0���� ����, array�� 0���� ����.)
	int temp = t % 2;

	for (int i = temp; i < n - temp; i += 2)
	{
		if (arr[i] > arr[i + 1])
			swap(&arr[i], &arr[i + 1]);
	}

	PARALLEL_SORT_1D_array_ROW_UP(t + 1, n, arr);
}

// �� �������� ����
void PARALLEL_SORT_1D_array_ROW_DOWN(int t, int n, int* arr)
{
	if (t == n)
		return;


	// �õ� Ƚ���� ¦���̸� 0������ 2���� sort, Ȧ���̸� 1������ 2���� sort. (0���� ����, array�� 0���� ����.)
	int temp = t % 2;

	for (int i = temp; i < n - temp; i += 2)
	{
		if (arr[i] < arr[i + 1])
			swap(&arr[i], &arr[i + 1]);
	}

	PARALLEL_SORT_1D_array_ROW_DOWN(t + 1, n, arr);
}

// �� �������� ����
void PARALLEL_SORT_1D_array_COL_UP(int t, int n, int** arr, int col)
{
	if (t == n)
		return;


	// �õ� Ƚ���� ¦���̸� 0������ 2���� sort, Ȧ���̸� 1������ 2���� sort. (0���� ����, array�� 0���� ����.)
	int temp = t % 2;

	for (int i = temp; i < n - temp; i += 2)
	{
		if (arr[i][col] > arr[i + 1][col])
			swap(&arr[i][col], &arr[i + 1][col]);
	}

	PARALLEL_SORT_1D_array_COL_UP(t + 1, n, arr, col);
}

// PRINT_ARRAY
void PRINT(int n, int** arr)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%3d ", arr[i][j]);
		printf("\n");
	}
}

// ��ü PARALLEL_SORT
void PARALLEL_SORT(int n, int** arr)
{
	int log_n = LOG(n);

	// 1 to (log n)
	for (int i = 0; i < log_n; i++)
	{
		// row sorting
		for (int j = 0; j < n; j++)
		{
			// ¦��row�� �������� (array ù���� 0�̹Ƿ�)
			if (j % 2 == 0)
				PARALLEL_SORT_1D_array_ROW_UP(0, n, arr[i]);
			// Ȧ�� row�� ��������
			else
				PARALLEL_SORT_1D_array_ROW_DOWN(0, n, arr[i]);
		}
		// col sorting
		for (int j = 0; j < n; j++)
			PARALLEL_SORT_1D_array_COL_UP(0, n, arr, j);

		//PRINT(n, arr);
		//printf("\n");
	}

	// last sort
	for (int i = 0; i < n; i++)
		PARALLEL_SORT_1D_array_ROW_UP(0, n, arr[i]);
}

int main()
{
	FILE* F;
	int N;
	int** arr;


	if (!(F = fopen("input1.txt", "r")))
	{
		printf("NO File!\n");
		exit(1);
	}

	// array initialize (size = n * n)
	fscanf(F, "%d", &N);

	arr = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
		arr[i] = (int*)malloc(N * sizeof(int));
	// �Է�
	for (int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			fscanf(F, "%d", &arr[i][j]);

	PARALLEL_SORT(N, arr);

	// ���
	PRINT(N, arr);

	// �迭 �Ҵ� ����
	for(int i = 0; i < N; i++)
		free(arr[i]);
	free(arr);

	fclose(F);

	return 0;
}