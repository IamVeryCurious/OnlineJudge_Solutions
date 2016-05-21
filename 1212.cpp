#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int l,r;
	long long value;
	bool isroot;
};
 
int main()
{
	int N,root=0;
	cin>>N;
	node *tree=new node[N+1];
	for(int i=1;i<=N;i++)
		tree[i].isroot=true;
	for(int i=1;i<=N;i++)
	{
		cin>>tree[i].l>>tree[i].r>>tree[i].value;
		tree[tree[i].l].isroot=false;
		tree[tree[i].r].isroot=false;
	}
	for(int i=1;i<=N;i++)
	{
		if(tree[i].isroot)
		{
			root=i;
			break;
		}
	}
	int tmp;
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		tmp=q.front();
		cout<<tree[tmp].value<<' ';
		q.pop();
		if(tree[tmp].l!=0)
			q.push(tree[tmp].l);
		if(tree[tmp].r!=0)
			q.push(tree[tmp].r);
	}
	delete []tree;
	return 0;
}
