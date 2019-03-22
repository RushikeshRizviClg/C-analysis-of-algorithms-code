#include<stdio.h>
#include<conio.h>
void main()
{
	 int a[100],i,n,j,key;
      clrscr();
    printf("Enter size of arrary:");
    scanf("%d",&n);
    printf("Enter array element:");
    for (i=1; i<=n; i++)
	scanf("%d",&a[i]);
    printf("\n");
    for(j=2;j<=n;j++)
    {
	key=a[j];
	i=j-1;
	while(i>0 && a[i]>key)
	{
		a[i+1]=a[i];
		i-=1;
	}
	a[i+1]=key;
    }
     printf("Insertion Sorted array: ");
    for (i=1; i <=n; i++)
	printf("%d ",a[i]);
    printf("\n");

    getch();

}