#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	char key;
	struct NODE* left;
	struct NODE* right;
}NODE;

// sum P[i ~ j]
float sum(const float p[], int i, int j)
{
	float sum = 0;

	for (int k = i; k <= j; k++)
		sum += p[k];

	return sum;
}


//min (A[i][m - 1] + A[m + 1][j] ) 최소 일때의 m = k;
float minimum(float** A, int i, int j, int *k)
{
	float temp = 100;

	for(int m = i; m <= j; m++)
		if (A[i][m - 1] + A[m + 1][j] < temp)
		{
			*k = m;
			temp = A[i][m - 1] + A[m + 1][j];
		}

	return temp;
}

// A를 통해 index의 값을 알아냄. && minavg = A[1][n]
void optsearchtree(int n, const float p[], float* minavg, int** R)
{
	int i, j, k, diagonal;
	float** A;

	A = (float**)malloc((n + 2) * sizeof(float*));
	for (i = 0; i <= n + 1; i++)
		A[i] = (float*)malloc((n + 1) * sizeof(float));

	// 대각선 0, diag == 0 일때 A[i][i] = P[i]
	for (i = 1; i <= n; i++)
	{
		A[i][i - 1] = 0;
		A[i][i] = p[i];
		R[i][i] = i;
		R[i][i - 1] = 0;
	}
	A[n + 1][n] = 0;
	R[n + 1][n] = 0;

	// 대각선 위쪽 2번째 줄부터 위로 하나씩 A와 R의 값.
	for(diagonal = 1; diagonal <= n - 1; diagonal++)
		for (i = 1; i <= n - diagonal; i++)
		{
			j = i + diagonal;
			A[i][j] = minimum(A, i, j, &k) + sum(p, i, j);
			R[i][j] = k;
		}

	*minavg = A[1][n];

	for (i = 0; i <= n + 1; i++)
		free(A[i]);
	free(A);
}

// R을 통해 OPTIMAL BINARY SEARCH TREE 생성.
NODE* tree(int i, int j, int** R, char* Key)
{
	int k;
	NODE* p;

	k = R[i][j];

	if (k == 0)
		return NULL;

	p = (NODE*)malloc(sizeof(NODE));
	p->key = Key[k];
	p->left = tree(i, k - 1, R, Key);
	p->right = tree(k + 1, j, R, Key);
	return p;
}

// preorder 순서대로 할당 해제
void FREE_NODE(NODE* r)
{
	NODE* temp_left = r->left;
	NODE* temp_right = r->right;

	free(r);

	if (r->key != '?')
		return;

	if(temp_left != NULL)
		FREE_NODE(temp_left);

	if(temp_right != NULL)
		FREE_NODE(temp_right);
}

// preorder 순서대로 출력
void PRINT_NODE(NODE* r)
{
	NODE* temp_left = r->left;
	NODE* temp_right = r->right;

	printf("(");

	if (r->key != '?')
		printf("%c", r->key);

	if (temp_left != NULL)
		PRINT_NODE(temp_left);
	else
		printf("()");

	if (temp_right != NULL)
		PRINT_NODE(temp_right);
	else
		printf("()");

	printf(")");

	return;
}

int main()
{
	FILE* F;
	NODE* root;
	int N;
	char* KEY;
	float* P;
	float minavg;
	int** R;

	if (!(F = fopen("input.txt", "r")))
	{
		printf("No File!\n");
		exit(1);
	}

	fscanf(F, "%d ", &N);
	// 초기화
	KEY = (char*)malloc((N + 1) * sizeof(char));
	P = (float*)malloc((N + 1) * sizeof(float));
	R = (int**)malloc((N + 2) * sizeof(int*));
	for (int i = 0; i <= N + 1; i++)
		R[i] = (int*)malloc((N + 1) * sizeof(int));
	
	// KEY, P 입력
	for (int i = 1; i <= N; i++)
		fscanf(F, "%c %f ", &KEY[i], &P[i]);

	// OPTSEARCH TREE (minavg = A[1][n]) (R에 index 저장.)
	optsearchtree(N, P, &minavg, R);

	// tree (R을 통해 tree생성)
	root = tree(1, N, R, KEY);

	printf("%f\n", minavg);

	// preorder로 출력
	PRINT_NODE(root);

	FREE_NODE(root);
	for (int i = 0; i <= N; i++)
		free(R[i]);
	free(R);
	free(KEY);
	free(P);
	
	fclose(F);

	return 0;
}