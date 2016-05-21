//1019
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool right(char brace[],int len)
{
	stack<char> stk;
	char tmp;
	for(int i=0;i<len;i++)
	{
		if(brace[i]=='(')
			stk.push('(');
		else
		{
			if(stk.empty())
				return false;
			tmp=stk.top();
			stk.pop();
		}
	}
	if(!stk.empty())
		return false;
	return true;
}
int main()
{
	int N,len;
	char brace[150];
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>brace;
		len=strlen(brace);
		if(right(brace,len))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

