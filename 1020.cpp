#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int n)
{
	bool flag=true;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
		{
			flag=false;
			break;
		}
	return flag;
}
int main()
{
	int N,i=2,num;
	cin>>N;
	cout<<N<<'=';
	while(i<=N)
	{
		num=0;
		if(isPrime(N))
		{
			cout<<N<<'('<<1<<')';
			break;
		}
		if(isPrime(i))
		{
			while(N%i==0)
			{
				N=N/i;
				num++;
			}
			if(num>0)
				cout<<i<<'('<<num<<')';
		}
		i++;
	}
	cout<<endl;
	return 0;
}
