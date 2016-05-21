#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int lchild,rchild;
};
int main()
{
	int n,father;
	node	tree[1000],temp;
	queue<node> q;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>father;		
		if(tree[father].lchild>0&&tree[father].lchild<n)
		{
			if(tree[father].lchild>i)
			{
				tree[father].rchild=tree[father].lchild;
				tree[father].lchild=i;		
			}
			else
				tree[father].rchild=i;
		}
		else
			tree[father].lchild=i;
	}

	q.push(tree[0]);
	cout<<0<<" ";
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		if(temp.lchild>0&&temp.lchild<n)
		{
			q.push(tree[temp.lchild]);
			cout<<temp.lchild<<" ";
		}
		if(temp.rchild>0&&temp.rchild<n)
		{
			q.push(tree[temp.rchild]);
			cout<<temp.rchild<<" ";
		}	
	}
	return 0;
}
