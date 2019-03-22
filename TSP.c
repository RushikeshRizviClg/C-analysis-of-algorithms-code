#include<stdio.h>
#include<conio.h>

int x[15], used[15];
int adj[15][15] = { 0 };
int path[15][15], wght[15];
int c, min;

int path_ok(int k,int n)
{
	if (used[x[k]])
		return 0;
	if (k < n-1)
		return(adj[x[k-1]][x[k]]);
	else
		return(adj[x[k-1]][x[k]] && adj[x[k]][x[0]]);
}
void TSP(int k,int n)
{
	int i,sum;
	for (x[k] = 1; x[k] < n; x[k]++) {
		if (path_ok(k,n)) {
			used[x[k]] = 1;
			if (k == n-1) {
				sum = 0;
				printf("\n\n\tPossible Path %d: ",c+1);
				for (i = 0; i < n; i++) {
					printf("%d ", x[i]);
					path[c][i] = x[i];
					sum += adj[x[i]][x[i+1]];
				}
				printf(": Cost=%d",sum);
				wght[c] = sum;
				if (c==0 || sum<min)
					min=sum;
				c++;
				used[x[k]]=0;
				getch();
			} else
				TSP(k+1,n);
			used[x[k]]=0;
		}
	}
}

void findmin(int n)
{
	int i,j;
	for (i = 0;i < c; i++)
		if (wght[i] == min) {
			printf("\n\n\tMinimum Path: ");
			for (j = 0; j < n; j++)
				printf("%d ", path[i][j]);
		}
}

void main()
{
	int i,n,j;
	int edg;
	clrscr();
	printf("\n\n\t\tTravelling Salesman Problem\n\n");
	printf("\nEnter the no. of Cities: ");
	scanf("%d",&n);
	printf("\n\n Enter the Cost if path Exist Between cities.:{c1,c2}.Else Enter 0\n\n");
	printf("\n\Cities\t\Cost\n\n");
	for (i = 0; i < n; i++)
	for (j = i+1; j < n; j++) {
		printf("\n\t%d to %d: ", i, j);
		scanf("%d", &edg);
		if (edg > 0)
			adj[i][j] = adj[j][i] = edg;
	}
	used[0] = 1;
	TSP(1, n);
	if (c == 0)
		printf("\n\n\t\tNo Path Found to Cover all the Cities\n\n");
	else {
		printf("\n\n\t\tMinimum Cost is %d and the Paths are \n\n", min);
		findmin(n);
	}
	getch();
}
