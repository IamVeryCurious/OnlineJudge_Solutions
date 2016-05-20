#include<iostream>
#include<algorithm>
using namespace std;

bool Shudu(int a[9][9])
{
	int tmp[9];
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			tmp[j]=a[i][j];
		sort(tmp,tmp+9);
		for(int j=0;j<9;j++)
			if(tmp[j]!=j+1)
				return false;
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			tmp[j]=a[j][i];
		sort(tmp,tmp+9);
		for(int j=0;j<9;j++)
			if(tmp[j]!=j+1)
				return false;
	}
	int k;
	for(int i=0;i<9;i+=3)
		for(int j=0;j<9;j+=3)
		{
			k=0;
			for(int m=i;m<i+3;m++)
				for(int n=j;n<j+3;n++)
				{
					tmp[k]=a[m][n];
					k++;
				}
			sort(tmp,tmp+9);
			for(int j=0;j<9;j++)
				if(tmp[j]!=j+1)
					return false;
		}
	
	return true;
}

int main()
{
	int n,a[9][9];
	bool flag=1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<9;j++)
			for(int k=0;k<9;k++)
			{
				cin>>a[j][k];
			}
		if(Shudu(a))
			cout<<"Right"<<endl;
		else
			cout<<"Wrong"<<endl;
	}
	return 0;
}