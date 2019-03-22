#include<conio.h>
#include<stdio.h>
#include<string.h>
void LCS(char x[20],char[20]);
void disp();
int L[20][20], n, m;
int A[20][20];	// Arrow(0=Corner,1=Top,2=Left)
char x[20];
void main()
{
	char y [20];
	//clrscr();
	printf("Enter String 1: ");
	scanf("%s",x);
	n = strlen(x);
	printf("\nEnter String 2: ");
	scanf("%s",y);
	m = strlen(y);
	LCS(x, y);
	disp();
	getch();
}
void disp_LCS(int, int);

void disp()
{
	int i,j;
	for(i = 0;i <= n-1; i++) {
		for(j=0;j <= m-1;j++)
			printf("%d\t", L[i][j]);
		printf("\n");
	}
	printf("\nLCS is: ");
	disp_LCS(n-1, m-1);
}

void disp_LCS(int i, int j)
{
	if (i == -1 || j == -1)
		return;
	if (A[i][j] == 0) {	// Corner
		disp_LCS(i-1, j-1);
		printf("%c", x[i]);
	} else if (A[i][j] == 1) { // Top
		disp_LCS(i-1, j);
	} else {
		disp_LCS(i, j-1);
	}
}

void LCS(char x[20],char y[20])
{
	int i,j;
	for (i = 0; i <= n-1; i++)
		for (j = 0; j <= m-1; j++) {
			L[i][j] = 0;
			A[i][j] = -1;
		}
	for (i = 0; i <= n-1; i++) {
		for (j = 0;j <= m-1;j++) {
			if (x[i] == y[j]) {
				A[i][j] = 0;
				if (i == 0 || j == 0)
					L[i][j] = 1;
				else
					L[i][j]=L[i-1][j-1]+1;
			} else {
				int check_i = 0;
				int check_j = 0;
				if (i != 0)
					check_i = L[i-1][j];
				if (j != 0)
					check_j = L[i][j-1];
				if(check_i>= check_j) {
					if (i == 0)
						L[i][j] = 0;
					else
						L[i][j]=L[i-1][j];
					A[i][j] = 1;
				} else {
					if (j == 0)
						L[i][j] = 0;
					else
						L[i][j]=L[i][j-1];
					A[i][j] = 2;
				}
			}
		}
	}
}
