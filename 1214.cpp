#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int lc,rb,value;
	bool isroot;
	bool isused;
};
void preorder(node *tree,int root)
{
	if(root!=0){
		cout<<tree[root].value<<' ';
		preorder(tree,tree[root].lc);
		preorder(tree,tree[root].rb);
	}
	return;
}
void postorder(node *tree,int root)
{
	if(root!=0){
		postorder(tree,tree[root].lc);
		cout<<tree[root].value<<' ';
		postorder(tree,tree[root].rb);
	}
	return;
}
int main()
{
	int N,root=0;
	cin>>N;
	node *tree=new node[N+1];
	tree[0].lc=0;
	tree[0].rb=0;
	for(int i=1;i<=N;i++)
	{
		tree[i].isroot=true;
		tree[i].isused=false;
	}
	for(int i=1;i<=N;i++)
	{
		cin>>tree[i].lc>>tree[i].rb>>tree[i].value;
		tree[tree[i].lc].isroot=false;
		tree[tree[i].rb].isroot=false;
	}
	for(int i=1;i<=N;i++)
	{
		if(tree[i].isroot)
		{
			root=i;
			break;
		}
	}
	preorder(tree,root);
	cout<<endl;
	postorder(tree,root);
	cout<<endl;
	int tmp,t2;
	queue<int> q;
	q.push(root);
	tree[root].isused=true;
	while(!q.empty())
	{
		tmp=q.front();
		q.pop();
		cout<<tree[tmp].value<<' ';
		tmp=tree[tmp].lc;
		if(tmp!=0){
		q.push(tmp);
		while(tree[tmp].rb!=0&&!tree[tree[tmp].rb].isused)
		{
			tmp=tree[tmp].rb;
			q.push(tmp);
			tree[tmp].isused=true;
		}
		}
	}
	delete []tree;
	return 0;
}
