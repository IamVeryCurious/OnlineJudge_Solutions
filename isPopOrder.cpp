#include<iostream>
#include<stack>
using namespace std;

bool isPopOrder(const int push[],const int pop[],int length)
{
	stack<int> stk;
	int i=0,j=0;
	while(i<length)
	{
		stk.push(push[i++]);
		while(j<length&&!stk.empty()&&pop[j]==stk.top())
		{
			j++;
			stk.pop();
		}
	}
	if(i==length&&j==length)
		return true;
	return false;
}

int main()
{
	int push[]={1,2,3,4,5},pop[]={4,3,5,1,2};
	cout<<isPopOrder(push,pop,5)<<endl;
	return 0;
}
