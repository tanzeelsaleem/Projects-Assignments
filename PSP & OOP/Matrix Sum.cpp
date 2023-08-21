#include<iostream>

using namespace std;
void sum(int arr[][4], int r, int c)
{
	
	cout<<"The values after taking the sum of both are in the form of matrix are";

	for (int i=0;i<r;i++)
	{
		for(int j=0; j<c;j++)
		{
			cout<<arr[i][j]+arr[i][j]<<" ";
			
		}
		cout<<endl;
	}
}
int main()
{
	int r =4,c=4;
	int arr[4][4];
	cout<<"Enter number in the matrix to take the sum of 2 matrix : "<<endl;
	for (int i=0;i<r;i++)
	{
		for(int j=0; j<c;j++)
		{
			cin>>arr[i][j];
			
		}
		cout<<endl;
	}
	sum(arr,4,4);
	
}

