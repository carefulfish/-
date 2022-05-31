#include<stdio.h>
#pragma warning(disable:4996)
#include<stdlib.h>
#include<math.h>
#include<string.h>

int hlsz(int a[10][10], int n)
{
	if (n == 1)
	{
		return a[0][0];
	}
	int x[10][10];
	int D = 0;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n - 1; k++)
		{
			for (int l = 0; l < n - 1; l++)
			{
				
				x[k][l] = a[k + 1][(l>=i)?l + 1:l];

			}
		}
		int d = hlsz(x, n - 1);
		if (i % 2 == 0)
		{
			D += a[0][i] * d;
		}
		else
		{
			D -= a[0][i] * d;
		}
	}
	return D;
}
void dsyzs(int a[10][10],int n,int b[10][10])
{
	int yzs[10][10];
	if (n == 1)
	{
		b[0][0] = 1;
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n - 1; k++)
			{
				for (int l = 0; l < n - 1; l++)
				{
					yzs[k][l] = a[(k >= i) ? k + 1 : k][(l >= j) ? l + 1 : l];
				}
			}
			b[j][i] = hlsz(yzs, n - 1);
			if ((i + j) % 2 == 1)
			{
				b[j][i] = -1 * hlsz(yzs, n - 1);
			}
		}
		
		
	}

}
int main()
{
	int n;
	int bs[10][10];
	int N[10][10];
	scanf_s("%d", &n);
	int **a=NULL;
	a = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%p", &a[i][j]);
			bs[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		free(a[i]);
	}
	free(a);
	
		int D = hlsz(bs, n);
		if (D== 0)
		{
			printf("无\n");
		}
		else
		{
			dsyzs(bs, n, N);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					int a = N[i][j],b=D,c;
					
					if (a < b)
					{
						int t;
						t = a;
						a = b;
						b = t;
					}
					c = a % b;
					while (a % b)
					{
						a = b;
						b = c;
						c = a % b;
					}

					printf("%d/%d\t", N[i][j]/b, D/b);
				}
				printf("\n");
			}
		}


	
	
}
