#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool IS_2(int n)			// n == 2^k Ȯ�� �Լ�
{
	int i = 1;

	for (; i < n; i *= 2);

	if (i == n)
		return true;

	return false;
}

int LOG_2(int n)			// 2^(log(n) - 1) ��� �Լ�
{
	int i = 1;
	int j = 0;

	for (; i < n; i *= 2, j++);

	return i / 2;
}

int main()
{
	FILE* F;
	int capacity, n, bin_num;
	int* bin;
	int* tree;
	int p;

	// �Է� (bin, tree)
	if (!(F = fopen("input1.txt", "r")))
	{
		printf("No File!\n");
		exit(1);
	}

	fscanf(F, "%d %d %d", &capacity, &n, &bin_num);

	bin = (int*)malloc((bin_num + 1) * sizeof(int));
	tree = (int*)malloc(n * sizeof(int));

	for (int i = 1; i <= bin_num; i++)
		bin[i] = capacity;

	// tree initialize
	if (IS_2(n))			// n == 2^k
	{
		for (int i = 1; i <= n; i += 2)
		{
			p = (i + n - 1) / 2;
			tree[p] = i;
		}
	}
	else
	{						// n != 2^k
		int s = LOG_2(n);
		int offset = 2 * s - 1;
		int LowExt = 2 * (n - s);

		if (n % 2 == 0)		// n == ¦��
		{
			for (int i = 1; i <= n; i += 2)
			{
				if (i <= LowExt)
					p = (i + offset) / 2;
				else
					p = (i - LowExt + n - 1) / 2;
				tree[p] = i;
			}
		}

		else				// n == Ȧ��
		{
			for (int i = 1; i <= LowExt; i += 2)
			{
				p = (i + offset) / 2;
				tree[p] = i;
			}
			for (int i = LowExt + 2; i < n; i += 2)
			{
				p = (i - LowExt + n - 1) / 2;
				tree[p] = i;
			}
		}
	}
	for (int i = (n - 1) / 2; i > 0; i--)
		tree[i] = tree[i * 2];

	// tree initialize �Ϸ�.

	for (int i = 0; i < n; i++)
	{
		int obj;
		int parent = 0;
		int child = 1;
		fscanf(F, "%d", &obj);

		while (child <= n - 1)			// tree�� height ���� �˻�.
		{
			if (bin[tree[child]] >= obj)
			{
				parent = child;
				child = parent * 2;
			}
			else
			{
				child = parent * 2 + 1;
			}
		}
		// tree�� ������ parent�� ���ʿ� ������ �� ������ ���ʿ� ����.
		if (bin[tree[parent] - 1] >= obj)
			bin[tree[parent] - 1] -= obj;
		else
			bin[tree[parent]] -= obj;

		//update;

		// �ٲ� ó�� node�� ��� ���� ū���� tree�� ����.
		int left = tree[parent];
		int right = tree[parent];

		if (tree[parent] % 2 == 0)
			left = tree[parent] - 1;

		else
			right = tree[parent] + 1;

		if (bin[left] < bin[right])
			tree[parent] = right;
		else
			tree[parent] = left;

		parent /= 2;

		// �� �� tree�� ������Ʈ.
		while (parent >= 1)
		{
			left = tree[parent * 2];
			right = tree[parent * 2 + 1];

			if (bin[left] < bin[right])
				tree[parent] = right;
			else
				tree[parent] = left;

			parent /= 2;
		}
	}

	for (int i = 1; i <= bin_num; i++)
		printf("%d ", bin[i]);
	printf("\n");

	free(bin);
	free(tree);

	fclose(F);

	return 0;
}