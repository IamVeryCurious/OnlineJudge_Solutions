#include<iostream>
using namespace std;

template<typename T>
struct myLink{
	T data[20000];                       
	int size;
};
template<typename T>
myLink<T> operator+(const myLink<T> A,const myLink<T> B)
{
	myLink<T> temp;
	temp.size=A.size+B.size;
	for(int i=0;i<A.size;i++)
		temp.data[i]=A.data[i];
	for(int i=0;i<B.size;i++)
		temp.data[i+A.size]=B.data[i];
	return temp;
}

int main()
{
	char type[10];
	int n,m;
	cin>>type;
	cin>>n>>m;

	if(type[0]=='i'){
		myLink<int> A,B,C;
		A.size=n;
		B.size=m;
		for(int i=0;i<A.size;i++)
			cin>>A.data[i];
		for(int i=0;i<B.size;i++)
			cin>>B.data[i];
		C=A+B;
		for(int i=0;i<C.size;i++)
			cout<<C.data[i]<<' ';
	}
	else if(type[0]=='c'){
		myLink<char> A,B,C;
		A.size=n;
		B.size=m;
		for(int i=0;i<A.size;i++)
			cin>>A.data[i];
		for(int i=0;i<B.size;i++)
			cin>>B.data[i];
		C=A+B;
		for(int i=0;i<C.size;i++)
			cout<<C.data[i]<<' ';
	}
		
	else if(type[0]=='d'){
		myLink<double> A,B,C;
		A.size=n;
		B.size=m;
		for(int i=0;i<A.size;i++)
			cin>>A.data[i];
		for(int i=0;i<B.size;i++)
			cin>>B.data[i];
		C=A+B;
		for(int i=0;i<C.size;i++)
			cout<<C.data[i]<<' ';
	}
	else 
		return -1;

	return 0;
}
