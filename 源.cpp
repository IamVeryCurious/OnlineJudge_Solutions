#include<iostream>
using namespace std;

int main()
{
	int M,T,U,F,D,time=0,count=0;
	cin>>M>>T>>U>>F>>D;
	char tmp;
	int *a=new int[T];
	for(int i=0;i<T;i++)
	{
		cin>>tmp;
		if(tmp=='f')
			a[i]=2*F;
		else
			a[i]=U+D;
	}
	for(int i=0;i<T;i++)
	{
		time+=a[i];
		if(time>M)
			break;
		count++;
	}
	cout<<count<<endl;
	return 0;
}