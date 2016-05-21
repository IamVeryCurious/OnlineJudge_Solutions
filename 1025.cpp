#include<iostream>
#include<algorithm>
using namespace std;

struct range
{
	int A,B;
};
bool cmp(const range x, const range y)
{
	return x.A<y.A;
}
int main()
{
	int N,len=0,tmpB=0;
	cin>>N;
	range *r=new range[N];
	for(int i=0;i<N;i++)
	{
		cin>>r[i].A>>r[i].B;
	}
	sort(r,r+N,cmp);
	tmpB=r[0].B;
	len+=tmpB-r[0].A;
	for(int i=1;i<N;i++)
	{
		if(r[i].A<=tmpB)
		{
			if(r[i].B>tmpB)
			{
				len+=r[i].B-tmpB;
				tmpB=r[i].B;
			}
		}
		else
		{
			len+=r[i].B-r[i].A;
			tmpB=r[i].B;
		}
	}
	cout<<len<<endl;
	delete[] r;
	return 0;
}
