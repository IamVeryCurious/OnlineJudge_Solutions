#include<iostream>
using namespace std;
void Qsort(int a[],int low,int high)
{
	if(low>=high)
		return;
	int first = low;
	int last = high;
	int key = a[first];
	while(first<last)
	{
		while(first<last&&a[last]>=key)
			--last;
		a[first] = a[last];
		while(first<last&&a[first]<=key)
			++first;
		a[last] = a[first];
	}
	a[first] = key;
	Qsort(a,low,first-1);
	Qsort(a,first+1,high);
}
int main()
{
	int n,*seq;
		cin>>n;
		seq=new int[n];
		for(int j=0;j<n;j++)
			cin>>seq[j];
		Qsort(seq,0,n-1);
		for(int j=0;j<n;j++)
			cout<<seq[j]<<" ";
		cout<<endl;
		delete [] seq;
return 0;
}
