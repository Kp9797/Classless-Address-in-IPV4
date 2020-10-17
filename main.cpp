#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int ip[4][8],n;
	cin >> n;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			cin >> ip[i][j];
		}
	}
	int mask[4][8];
	for(int i=0;i<4;i++)
	{
		if(n>=8)
		{
			for(int j=0;j<8;j++)
			{
				mask[i][j] = 1 ;
			}
			n -= 8;
		}
		else
		{
			for(int j=0;j<n;j++)
			{
				mask[i][j] = 1;
			}
			for(int j=n;j<8;j++)
			{
				mask[i][j] = 0;
			}
		}
	}
	int fadd[4][8];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			fadd[i][j] = ip[i][j] & mask[i][j];
		}
	}
	int comp[4][8];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(mask[i][j] == 1)
				comp[i][j] = 0;
			else
				comp[i][j] = 1;
		}
	}
	int ladd[4][8];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			ladd[i][j] = ip[i][j] | comp[i][j];		
		}
	}
	cout << "First Address :" << "\n" ;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout << fadd[i][j] << "\t";
		}
		cout << "\n" ;
	}
	cout << "Last Address :" << "\n" ;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout << ladd[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "No. of addresses :" << (int)(pow(2,n)) << endl ;
	return 0;
}
