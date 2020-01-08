#include<iostream>

using namespace std;

void selectSort(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int temp=arr[i],j=i,k=i;
		for(j=i;j<n;j++)
		{
			if(temp<arr[j])
			{
				temp=arr[j];
				k=j;
			}
		}
		int res=arr[i];
		arr[i]=arr[k];
		arr[k]=res;
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int arr[] = {23,56,4,15,8,65,45};
	selectSort(arr,sizeof(arr)/sizeof(int));
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
