#include<iostream>
using namespace std;
int main()
{
	int n,t,j,ct=0;
	cout<<"\nEnter the size of array: ";
	cin>>n;
	int ar[n];
	cout<<"\nEnter elements in an array: ";
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	cout<<"\nElements are: ";
		for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	for(int i=1;i<n;i++)
	{
		t=ar[i];
		for(j=i-1;j>=0&&t<ar[j];j--)
		{
			ar[j+1]=ar[j];
			ct++;
		}
		
    	ar[j+1]=t;
	}
	cout<<"\nSorted array is:";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<ar[i];
	}
	cout<<"\nNo of Comparisions : "<<ct;
}

