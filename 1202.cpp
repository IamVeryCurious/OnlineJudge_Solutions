//big int (100)
#include <iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	char *A=(char *)malloc(1000000*sizeof(char));
	char *B=(char *)malloc(1000000*sizeof(char));
	int *result=(int *)malloc(1000001*sizeof(int));
	int length_A=0,length_B=0;
	cin>>A;
	cin>>B;
	while('0'<=A[length_A]&&A[length_A]<='9')
		length_A++;
	while('0'<=B[length_B]&&B[length_B]<='9')
		length_B++;
	int length_res=0;
	result[0]=0;

	if(length_A>length_B)
	{
		length_res=length_A+1;
		for(int i=0;i<length_B;i++)
			result[length_A-i]=A[length_A-i-1]+B[length_B-i-1]-2*'0';
		for(int i=length_B;i<length_A;i++)
			result[length_A-i]=A[length_A-i-1]-'0';
	}
	else
	{
		length_res=length_B+1;
		for(int i=0;i<length_A;i++)
			result[length_B-i]=A[length_A-i-1]+B[length_B-i-1]-2*'0';
		for(int i=length_A;i<length_B;i++)
			result[length_B-i]=B[length_B-i-1]-'0';
	}
	for(int i=1;i<length_res;i++)
	{
		if(result[length_res-i]>9)
		{
			result[length_res-i]-=10;
			result[length_res-i-1]++;
		}
	}

	if(result[0]!=0)
		cout<<result[0];
	for(int i=1;i<length_res;i++)
		cout<<result[i];

	return 0;
	
}
