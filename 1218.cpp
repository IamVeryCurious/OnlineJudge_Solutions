#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int data;
	node *next;
	node(){data=0;next=NULL;}
	node(int d){data=d;next=NULL;}
};

int main()
{
	int n,tmp,m,t[120];
	node root=node(),*p,*q;
	char op;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>op;
		cin>>m;
		if(op=='+')
		{
			for(int j=0;j<m;j++)
			{
				cin>>tmp;
				p=&root;
				q=p->next;
				while(p!=NULL)
				{
					if(q){
					if(q->data<tmp)
					{
						p=q;
						q=q->next;
					}
					else if(q->data==tmp)
						break;
					else
					{
						p->next=new node(tmp);
						p->next->next=q;
						break;
					}}
					else{
						p->next=new node(tmp);
						break;
					}
				}
			}
			p=&root;
		}
		else if(op=='-')
		{
			for(int j=0;j<m;j++)
			{
				cin>>tmp;
				p=&root;
				while(p)
				{
					q=p->next;
					if(q){
					if(q->data>tmp)
						break;
					else if(q->data==tmp)
					{
						p->next=q->next;
						break;
					}}
					p=q;
				}
			}
			p=&root;
		}
		else if(op=='*')
		{
			for(int j=0;j<m;j++)
				cin>>t[j];
			sort(t,t+m);
			p=&root;
			q=p;
			for(int j=0;j<m;j++)
			{
				while(q)
				{
					if(q->data>t[j])
						break;
					else if(q->data==t[j])
					{
						p->next=q;
						p=p->next;
						break;
					}
					q=q->next;
				}
			}
			p->next=NULL;
		}
		p=&root;
			while(p->next)
			{
				p=p->next;
				cout<<p->data<<' ';
			}
			cout<<endl;
	}
}/*
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	bool *res;
	int n,m,tmp,t[120];
	char op[1];
	res=(bool*)malloc(sizeof(bool)*10000);
	memset(res,false,10000*sizeof(bool));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		getchar();
		scanf("%c",&op);
		scanf("%d",&m);
		if(op[0]=='+')
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&tmp);
				res[tmp]=true;
			}
		}
		if(op[0]=='-')
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&tmp);
				res[tmp]=false;
			}
		}
		if(op[0]=='*')
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&t[j]);
				if(!res[t[j]])
					t[j]=0;
			}
			memset(res,false,10000*sizeof(bool));
			for(int j=0;j<m;j++)
				res[t[j]]=true;
			res[0]=false;
		}
		for(int j=0;j<10000;j++)
		{
			if(res[j])
				printf("%d ",j);
		}
		printf("\n");
	}
	free(res);
	return 0;
}*/
