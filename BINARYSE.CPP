#include<stdio.h>
#include<conio.h>
void b(int a[10],int low,int high,int mid,int key)
{       while(low<=high)
    {

	if(a[mid]<key)
	{
	       low=mid+1;
	       mid=(low+high)/2;
	}
	else if(a[mid]==key)
	{
		printf("\n%d Found at position %d",(key+1),mid);
		break;
	}
	else
	{
		high=mid-1;
		mid=(low+high)/2;
	}
    }
    if(low>high)
    {
	printf("\n %dNot found in array",key);
    }
}
void main()
{
	int a[10],low,high,mid,i,key,n,temp,j;
	clrscr();
	printf("Enter size of array : ");
	scanf("%d",&n);
	printf("Enter array elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter key :");
	scanf("%d",&key);
	low=0;
	high=4;
	mid=(low+high)/2;
	for(j=0;j<n;j++)
	for(i=0;i<n-j-1;i++)
	{
		if(a[i]>a[i+1])
		{
			temp=a[i+1];
			a[i+1]=a[i];
			a[i]=temp;
		}
	}
	printf("Sorted array is :");
	for(i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}
	b(a,low,high,mid,key);
	getch();
}
