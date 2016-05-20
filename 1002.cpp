#include <iostream>
#include <stdlib.h>
using namespace std;
//前缀和
int main()
{
	int L,W,**num,a,b,m=0,temp;
	cin>>L>>W;
	num=(int **)malloc(sizeof(int*)*L);
	for(int i=0;i<L;i++)
		num[i]=(int*)malloc(sizeof(int)*W);
	for(int i=0;i<L;i++)
		for(int j=0;j<W;j++)
		{
			cin>>temp;
			if(i==0&&j==0)
				num[i][j]=temp;
			else if(i==0&&j>0)
				num[i][j]=num[i][j-1]+temp;
			else  if(i>0&&j==0)
				num[i][j]=num[i-1][j]+temp;
			else
				num[i][j]=num[i][j-1]+num[i-1][j]+temp-num[i-1][j-1];
		}
	cin>>a>>b;
	for(int i=a-1;i<L;i++)
		for(int j=b-1;j<W;j++)
		{
			if(i==a-1&&j==b-1)
				temp=num[i][j];
			else if(i>a-1&&j==b-1)
				temp=num[i][j]-num[i-a][j];
			else if(i==a-1&&j>b-1)
				temp=num[i][j]-num[i][j-b];
			else
				temp=num[i][j]-num[i][j-b]-num[i-a][j]+num[i-a][j-b];
			if(temp>m)
				m=temp;
		}
	cout<<m<<endl;
	for(int i=0;i<L;i++)
		free(num[i]);
	free(num);
	return 0;
}

