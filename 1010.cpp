#include <iostream>
using namespace std;
 
int main()
{
	int money[12],sum=0,tmp=0,month=0;
	for(int i=0;i<12;i++)
	{
		cin>>money[i];
		tmp=300+tmp-money[i];
		if(tmp<0)
		{
			month=-i-1;
			break;
		}
		sum+=100*(tmp/100);
		tmp=tmp%100;
	}
	if(month<0)
    	cout<<month<<endl;
	else
	{
		sum=sum*1.2+tmp;
		cout<<sum<<endl;
	}
	return 0;
}

