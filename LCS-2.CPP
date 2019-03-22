#include<stdio.h>
#include<string.h>
#include<conio.h>

void main()
{
  char X[5];
  char Y[5],P[5] ;
  clrscr();
  printf("Enter X  :");
  gets(X);
  printf("\nEnter Y  :");
  gets(Y);

  int m = strlen(X);
  int n = strlen(Y);

  int L[10][10];
   L[m+1][n+1];
   int i, j;
 printf("LCS matrix is :\n");
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
	{ L[i][j]=0;
	printf("%d    ",L[i][j]);
	}

       else if (X[i-1] == Y[j-1])
	{ L[i][j] = L[i-1][j-1] + 1;
	 P[i]=Y[i];
	 printf("%d d  ",L[i][j]);
	}
       else
	 {if(L[i-1][j] > L[i][j-1])
	  {L[i][j]=L[i-1][j];printf("%d u  ",L[i-1][j]);}
	 else{L[i][j]=L[i][j-1];printf("%d h  ",L[i][j-1]);}
	 }
	}
     printf("\n");
   }
   printf("\nLength of LCS is :- %d",L[m][n]);
    printf("\nLCS string is :-  %s", P);
    getch();
}