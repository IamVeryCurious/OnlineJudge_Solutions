

#include<iostream>
using namespace std;
int main()
{
	int fib[3];
	long long N;
	cin>>N;
	fib[0]=1;
	fib[1]=1;
	for(int i=2;i<N%2040;i++)
	{
		fib[2]=(fib[0]+fib[1])%2010;
		fib[0]=fib[1];
		fib[1]=fib[2];
	}
	cout<<fib[2]<<endl;
	return 0;
}
