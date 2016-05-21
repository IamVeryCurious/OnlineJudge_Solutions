#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
 
int main()
{
	int n,a,b,sq[620][620];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		for(int j=0;j<a;j++)
			for(int k=0;k<a;k++)
				scanf("%d",&sq[j][k]);
		if(b==0)
		{
			for(int j=0;j<a;j++)
			{
				for(int k=0;k<a;k++)
					printf("%d ",sq[j][a-1-k]);
				printf("\n");
			}
		}
		else if(b==1)
			for(int j=0;j<a;j++)
			{
				for(int k=0;k<a;k++)
					printf("%d ",sq[a-1-j][k]);
				printf("\n");
			}
		else if(b==2)
			for(int j=0;j<a;j++)
			{
				for(int k=0;k<a;k++)
					printf("%d ",sq[k][j]);
				printf("\n");
			}
  }
 
	return 0;
}

