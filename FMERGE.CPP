#include<stdio.h>
#include<conio.h>
void Combine(int a[],int low,int mid,int high);
void MergeSort(int a[],int low,int high);
void Display(int a[],int n);

void MergeSort(int a[10],int low,int high){
	int mid;
	if(low<high){
	mid=(low+high)/2;
	MergeSort(a,low,mid);
	MergeSort(a,mid+1,high);
	Combine(a,low,mid,high);
	}
}

void Combine(int a[],int low,int mid,int high){
	int i,j,k=0,m,temp[10];
	i=low;
	j=mid+1;
	while(i<=mid&&j<=high)
	{
		if(a[i]<a[j]){
		temp[k]=a[i];
		i++;
		k++;
		}
		else
		{
		temp[k]=a[j];
		j++;
		k++;
		}
	}
	while(i<=mid){
	temp[k]=a[i];
	i++;
	k++;
	}
	while(j<=high){
	temp[k]=a[j];
	k++;
	j++;
	}
	j=0;
	for(i=low;i<=high;i++)
	{
	a[i]=temp[j];
	j++;
	}
}

void Display(int a[],int n){
printf("MergeSorted Array is \n");
for(int i=0;i<n;i++)
printf("%d\t",a[i]);
}

void main()
{
clrscr();
	int a[10],low,high,n;
	printf("Enter the no of elements: ");
	scanf("%d",&n);
	low=0;
	high=n-1;
	printf("Enter the elements: \n");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	MergeSort(a,low,high);
	Display(a,n);
	getch();
}
