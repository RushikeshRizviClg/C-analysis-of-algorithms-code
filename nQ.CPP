#include<stdio.h>
#include<conio.h>
#include<math.h>
int x[20], count;

void print_board(int n)
{
	int i,j;
	printf("\n\nSolution :%d\n\n", ++count);//number of solution
	for (i = 1;i <= n; i++)
		printf("\t%d", i);
	for (i = 1;i <= n; i++) { 
		printf("\n\n%d", i);
		for (j = 1; j <= n; j++) { //f or nXn board
			if (x[i] == j)
				printf("\tQ"); // Queen at i,j position
			else
				printf("\t-"); // empty slot
		}
	}
	printf("\n\n\nPress any key to continue....");
	getch();
}

int place(int row,int column)
{
	int i;
	for (i = 1;i <= row-1; i++)
		if (x[i] == column)
			return 0;
		else if (abs(x[i] - column) == abs(i - row))   
			return 0;
	return 1;
}

void Queen(int row, int n)
{
	int column; 
	for(column = 1; column <= n; column++) {
		if(place(row,column)) {
			x[row] = column;
			if (row == n)
				print_board(n);
			else
				Queen(row+1, n);
		}
	}
}
void main()
{
	int n;
	clrscr();
	printf("\n\t Program for n-Queen Using Backtracking");
	printf("\nEnter Number of Queens:");
	scanf("%d", &n);
	Queen(1, n);
	if (count == 0)
		printf("\n There are no Solution");
	getch();
}
