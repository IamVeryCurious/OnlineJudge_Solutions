#include<iostream>
#include<string>
#include<string.h>
using namespace std;
 
void big_add(char a[],char b[],int la,int lb,int *res,int x)//la>=lb
{
	res[la]=a[la-1]+b[lb-1]-'0'-'0'+x;
	for(int i=1;i<lb;i++)
	res[la-i]=a[la-1-i]+b[lb-1-i]-'0'-'0';
	for(int i=lb;i<la;i++)
		res[la-i]=a[la-1-i]-'0';
	res[0]=0;
	for(int i=la;i>0;i--)
	if(res[i]>=10)
		{
			res[i-1]++;
			res[i]-=10;		}
}
 
int main()
{
	char a[300],b[300];
	int sum[300],x[3];
	int la,lb,maxl;
	cin.getline(a,300,'\n');
	cin.getline(b,300,'\n');
	la=strlen(a);
	lb=strlen(b);
	x[2]=a[la-1]+b[lb-1]-'0'-'0';
	x[1]=a[la-2]+b[lb-2]-'0'-'0';
	if(x[2]>=10)
	{
		x[2]-=10;
		x[1]++;
	}
	if(x[1]>=10)
	{
		x[1]-=10;
		x[0]=1;
	}
	else 
		x[0]=0;
 
	if(la>=lb)
	{
		big_add(a,b,la-3,lb-3,sum,x[0]);
		maxl=la-3;
	}
	else{
		big_add(b,a,lb-3,la-3,sum,x[0]);
		maxl=lb-3;
	}
	if(sum[0]!=0)
	cout<<sum[0];
	for(int i=1;i<=maxl;i++)
		cout<<sum[i];
	cout<<'.'<<x[1]<<x[2];
	return 0;
}

