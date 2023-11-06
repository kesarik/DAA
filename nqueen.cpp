#include<iostream>
using namespace std;
int issafe(int board[][10],int n,int row,int column)
{
	for(int i=0;i<n;i++)   //chekcing for column
	{
		if(board[i][column]==1)
		{
			return 0;
		}
	}
		//checking for left diagonal
	for(int i=row,j=column;i>=0 && j>=0;i--,j--)
	{
		if(board[i][j]==1)
		{
			return 0;
		}
	}
		//checking for right diagonal
	for(int i=row,j=column;i>=0 && j<n;i--,j++)
	{
		if(board[i][j]==1)
		{
			return 0;
		}
	}
	return 1;
	
}
int placequeen(int board[][10],int n,int row)
{
	if(row==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<board[i][j]<<"\t";
			}
			cout<<"\n";
		}
		cout<<"\n";
		return 1;
	}
	int flag=0;
	for(int i=0;i<n;i++) //queens are not placed then used to check next row
	{
		if(issafe(board,n,row,i)==1)
		{
			board[row][i]=1;
			flag=placequeen(board,n,row+1) || flag;
			board[row][i]=0;
		}
	}
	return flag;
}
int main()
{
	int n;
	cout<<"Enter the number of queens:";
	cin>>n;
	
	int board[10][10]={0};
	
	if(placequeen(board,n,0)==1)
	{
		cout<<"Solution is exit.."<<"\n";
	}
	else
	{
		cout<<"Solution does not exit.."<<"\n";
	}
	return 0;
}
