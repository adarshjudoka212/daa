#include<iostream>
using namespace std;
int comp=0;
void quicksort(int a[], int i, int j);
int partition(int a[],int l,int u);
int main()
{
	int n,t,j;
	cout<<"\nEnter the size of array:\n";
	cin>>n;
	int ar[n];
	cout<<"\nEnter elements in an array:\n";
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	cout<<"\nElements are:\n";
		for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	quicksort(ar,0,n-1);
	cout<<"\nsorted array is:\n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<ar[i];
	}
	cout<<"\nTotal number of comparisons are: "<<comp;
	return 0;
}
void quicksort(int a[],int i,int j)
{
	int mid;
	if(i<j)
	{
	mid=partition(a,i,j);
	quicksort(a,i, mid-1);
	quicksort(a,mid+1,j);	
	}
}
int partition(int a[],int l,int u)
{
	int p,i,j,temp;
	p=a[l];
	i=l;
	j=u+1;
	do{
		do
		i++;
		while(a[i]<p && i<=u);
		do
		j--;
		while(p<a[j]);
		if(i<j)
		{
		 temp=a[i];
		 a[i]=a[j];
		 a[j]=temp;
		}
		comp++;
	}while(i<j);
	a[l]=a[j];
	a[j]=p;
	return(j);
}
