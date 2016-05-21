//100
#include<iostream>

using namespace  std;

//my linked list
struct myNode
{
	char data[2001];
	int data_size;
	myNode *next;
};
myNode *head=new myNode;

void list(int n1,int n2)
{
	myNode *temp=head;
	if(n1<1||n1>n2)
	{
		cout<<"Error!"<<endl;
		return;
	}
	for(int i=1;i<=n2;i++)
	{
		if(temp->data[0]!='*')
			temp=temp->next;
		else
		{
			cout<<"Error!"<<endl;
			return;
		}
	}
	temp=head;
	for(int i=1;i<n1;i++)
	{
			temp=temp->next;
	}
	for(int i=n1;i<=n2;i++)
	{
		for(int i=0;i<temp->data_size;i++)
		{
			cout<<temp->data[i];
		}
		cout<<endl;
		temp=temp->next;

	}

	return;
}

void quit()
{
	myNode  *temp=head;
	while(temp->data[0]!='*')
	{
		for(int i=0;i<temp->data_size;i++)
		{
			cout<<temp->data[i];
		}
		cout<<endl;
		temp=temp->next;
	}

	return;
}
void add(myNode *node,char elem,int i)
{
	for(int j=node->data_size;j>=i;j--)
		node->data[j]=node->data[j-1];
	node->data[i-1]=elem;
	node->data_size++;

}

void ins(int i,int j,char str[])
{
	myNode *temp=head;

	if(i<1)
	{
		cout<<"Error!"<<endl;

		return;
	}
	int size=1;
	while(str[size-1]>=' ')
	{
		size++;
	}
	for(int k=1;k<i;k++)
	{
		if(temp->next->data[0]!='*')
			temp=temp->next;
		else
		{
			cout<<"Error!"<<endl;

			return;
		}
	}
	if(temp->data_size>=j-1)
	{
		if((temp->data_size+size)>2000)
		{
			cout<<"Error!"<<endl;

			return;
		}

		for(int n=0;n<size-2;n++)
		{
			add(temp,str[n+1],j+n);

		/*	for(int m=temp->data_size;m>=j+n;m--)
				temp->data[m]=temp->data[m-1];
			temp->data[j+n-1]=str[n];
			temp->data_size++;*/
		}
		
	}
	else
	{
		cout<<"Error!"<<endl;

		return;
	}

	return;
}

void del(int i,int j,int num)
{
	myNode *temp=head;
	if(i<1)
	{
		cout<<"Error!"<<endl;
		return;
	}
	for(int k=1;k<i;k++)
	{
		if(temp->next->data[0]!='*')
			temp=temp->next;
		else
		{
			cout<<"Error!"<<endl;
			return;
		}
	}
	if(temp->data_size<(j+num-1))
	{
		cout<<"Error!"<<endl;
		return;
	}
	for(int n=0;n<num;n++)
	{
		for(int m=j;m<temp->data_size;m++)
			temp->data[m-1]=temp->data[m];
		temp->data[temp->data_size-1]=NULL;
		temp->data_size--;
	}


	return;
}
				

int main()
{
	cin.getline(head->data,2000);
	head->data_size=0;
	while(head->data[head->data_size]>=' ')
	{
		head->data_size++;
	}
	myNode *test=head;

	while(test->data[0]!='*')
	{
		test->next=new myNode;
		cin.getline(test->next->data,2000);
		test->next->data_size=0;
		while(test->next->data[test->next->data_size]>=' ')
		{
			test->next->data_size++;
		}
		test=test->next;
	}

	char command[5],str[100];
	int x,y,z;
	cin>>command;
while(command[0]!='q'){

	if(command[0]=='l')
	{
		cin>>x>>y;

		list(x,y);

		cin>>command;

	}
	else if(command[0]=='i')
	{
		cin>>x>>y;
		cin.getline(str,100,'\n');

		ins(x,y,str);
		cin>>command;
	}
	else if(command[0]=='d')
	{
		cin>>x>>y>>z;
		del(x,y,z);
		cin>>command;
	}
}

	if(command[0]=='q')
		quit();

	delete []head;
	delete []test;
	return 0;

}
