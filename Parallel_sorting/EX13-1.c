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

// 행 오름차순 정렬
void PARALLEL_SORT_1D_array_ROW_UP(int t, int n, int* arr)
{
	if (t == n)
		return;


	// 시도 횟수가 짝수이면 0번부터 2개씩 sort, 홀수이면 1번부터 2개씩 sort. (0부터 시작, array도 0부터 시작.)
	int temp = t % 2;

	for (int i = temp; i < n - temp; i += 2)
	{
		if (arr[i] > arr[i + 1])
			swap(&arr[i], &arr[i + 1]);
	}

	PARALLEL_SORT_1D_array_ROW_UP(t + 1, n, arr);
}

// 행 내림차순 정렬
void PARALLEL_SORT_1D_array_ROW_DOWN(int t, int n, int* arr)
{
	if (t == n)
		return;


	// 시도 횟수가 짝수이면 0번부터 2개씩 sort, 홀수이면 1번부터 2개씩 sort. (0부터 시작, array도 0부터 시작.)
	int temp = t % 2;

	for (int i = temp; i < n - temp; i += 2)
	{
		if (arr[i] < arr[i + 1])
			swap(&arr[i], &arr[i + 1]);
	}

	PARALLEL_SORT_1D_array_ROW_DOWN(t + 1, n, arr);
}

// 열 오름차순 정렬
void PARALLEL_SORT_1D_array_COL_UP(int t, int n, int** arr, int col)
{
	if (t == n)
		return;


	// 시도 횟수가 짝수이면 0번부터 2개씩 sort, 홀수이면 1번부터 2개씩 sort. (0부터 시작, array도 0부터 시작.)
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

// 전체 PARALLEL_SORT
void PARALLEL_SORT(int n, int** arr)
{
	int log_n = LOG(n);

	// 1 to (log n)
	for (int i = 0; i < log_n; i++)
	{
		// row sorting
		for (int j = 0; j < n; j++)
		{
			// 짝수row는 오름차순 (array 첫줄이 0이므로)
			if (j % 2 == 0)
				PARALLEL_SORT_1D_array_ROW_UP(0, n, arr[i]);
			// 홀수 row는 내림차순
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
	// 입력
	for (int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			fscanf(F, "%d", &arr[i][j]);

	PARALLEL_SORT(N, arr);

	// 출력
	PRINT(N, arr);

	// 배열 할당 해제
	for(int i = 0; i < N; i++)
		free(arr[i]);
	free(arr);

	fclose(F);

	return 0;
}