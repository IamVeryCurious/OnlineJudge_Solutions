#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int M,*num,tmp=0;
	bool *flag;
	cin>>M;
	num=new int[M-1];
	flag=new bool[M];
	for(int i=0;i<M-1;i++)
		cin>>num[i];
	for(int i=0;i<M;i++)
		flag[i]=false;
	for(int i=0;i<M-1;i++)
	{
		tmp=(tmp+num[i]%(M-i)-1)%M;
		while(flag[tmp])
		{
			tmp--;
			tmp=tmp%M;
		}
		flag[tmp]=true;
		while(flag[tmp%=M]) tmp++;
	}
	for(int i=0;i<M;i++)
	{
		if(!flag[i])
		{
			cout<<i+1<<endl;
			break;
		}
	}
	return 0;
}