#include<iostream>
using namespace std;

void matrix(int p[],int wt[],int n,int capacity)
{	
	int status[n+1]={0};
	int profit=0;
	int k[n+1][capacity+1];
	
	for(int i=0;i<=n;i++)
	{
		for(int w=0;w<=capacity;w++)
		{
			if(i==0 || w==0) //i is 0 (no items to consider) or w is 0 (no capacity left), 
			{
				k[i][w]=0;
			}
			else if(wt[i]<=w) 
			{
				k[i][w]=max(k[i-1][w],p[i]+k[i-1][w-wt[i]]);
			}
			else
			{
				k[i][w]=k[i-1][w];
			}
			cout<<k[i][w]<<"\t"; //printing matrix
		}
		cout<<"\n";
	}
	int i=n,w=capacity;
	while(i>0 && w>0)
	{
		if(k[i][w]==k[i-1][w]) //jr ekhda element nhi consider kela tr
		{
			status[i]=0;
			i--;
		}
		else
		{
			status[i]=1;
			w=w-wt[i];
			i--;
		}
	}
	
	cout<<"The Status is:\n";
	for(int i=1;i<=n;i++)
	{
		cout<<status[i]<<"\t";
	}
	cout<<"\n";
	cout<<"The maximum profit is:\n";
	for(int i=1;i<=n;i++)
	{
		profit+=status[i]*p[i];
	}
	cout<<profit<<"\t";
}
int main()
{
		int n,capacity;
		
		cout<<"Enter the capacity of the bag:";
		cin>>capacity;
		cout<<"Enter the number of objects:";
		cin>>n;
		
		int p[n],wt[n];
		p[0]=wt[0]=0;
		for(int i=1;i<=n;i++)
		{
			cout<<"Enter the profit of the object:";
			cin>>p[i];
			cout<<"Enter the weight of the object:";
			cin>>wt[i];
		}
		cout<<"\n";
		
		cout<<"Printing the profit and weight is:\n";
		cout<<"The Profit is:\n";
		for(int i=1;i<=n;i++)
		{
			cout<<p[i]<<"\t";
		}
		cout<<"\n";
		cout<<"The weight is:\n";
		for(int i=1;i<=n;i++)
		{
			cout<<wt[i]<<"\t";
		}
		cout<<"\n";
		matrix(p,wt,n,capacity);
		
		return 0;
		
}
