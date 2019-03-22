#include<stdio.h>
#include<conio.h>
int Partition(int a[],int p,int r)
{       int pivot,i,j,temp;
	pivot=a[r];
	i=p;
	for(j=0;j<r;j++)
	{
		if(a[j]<pivot)
		{
			temp=a[j];
			a[j]=a[i];
			a[i] =a[j];
			i++;
		}
	}
	temp=a[i];
	a[i]=a[r];
	a[r]=temp;
	return (i);
}
void Quicksort(int a[], int p,int r)
{
	int q;
	if(p<r)
	{
		q=Partition(a,p,r);
		Quicksort(a,p,q-1);
		Quicksort(a,q+1,r);
	}
}
void main()
{	int n,p,r,i,a[10];
	clrscr();
	printf("Enter number of element of array:");
	scanf("%d",&n);
	printf("Enter array element:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	p=0;
	r=n-1;
	Quicksort(a,p,r);
	printf("Quick sort array element:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	getch();
}