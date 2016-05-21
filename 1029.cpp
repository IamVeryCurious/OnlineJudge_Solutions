/*
#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h>
using namespace std;
struct book
{
	char data[240];
	book *next;
	bool empty;
	book(){memset(data,'\0',240*sizeof(char));next=NULL;empty=false;}
};

int main()
{
	int n,x,y;
	book shelves[150],*tmp=new book();
	cin>>n;
	getchar();
	for(int i=0;i<n;i++)
	{
		shelves[i]=book();
		scanf("%[^\n]",shelves[i].data);
		getchar();
	}
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		if(!shelves[x-1].empty)
		{
			tmp=&shelves[y-1];
			while(tmp->next)
				tmp=tmp->next;
			tmp->next=&shelves[x-1];
		}
		shelves[x-1].empty=true;
	}
	for(int i=n-1;i>=0;i--)
		if(!shelves[i].empty)
		{
			tmp=&shelves[i];
			while(tmp)
			{
				cout<<tmp->data<<' ';
				tmp=tmp->next;
			}
			cout<<endl;
			break;
		}
	delete tmp;
	return 0;
}*/
#include<cstring>
#include<string>
#include<iostream> 
#include<stdio.h>
#include<stdlib.h>
using namespace std; 
int main() 
{ 
	int n; 
 	cin>>n; 
	string b[101]; 
 	getchar(); 
 	for (int i=1;i<=n;++i) 
 		getline(cin,b[i]); 
 	int x,y; 
 	for (int i=1;i<=n-1;++i) 
 	{ 
 		cin>>x>>y; 
 		b[y]=b[y]+" "+b[x]; 
 		b[x]=""; 
 	} 
 	cout<<b[y]<<endl; 
} 
