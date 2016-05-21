/*
#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int h;
	bool inPath;
};
struct point
{
	int x,y;
	point(int a,int b){x=a;y=b;};
};
int N;
node mount[150][150];
bool havepath(int minh,int maxh)
{
	if(mount[0][0].h<minh||mount[0][0].h>maxh||mount[N-1][N-1].h<minh||mount[N][N].h>maxh)
		return false;
	queue<point> path;
	point tmp=point(0,0);
	path.push(tmp);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			mount[i][j].inPath=false;
		}
	mount[0][0].inPath=true;
	while(!path.empty())
	{
		tmp=path.front();
		path.pop();
		if(tmp.x+1<N&&!mount[tmp.x+1][tmp.y].inPath&&mount[tmp.x+1][tmp.y].h>=minh&&mount[tmp.x+1][tmp.y].h<=maxh)
		{	path.push(point(tmp.x+1,tmp.y));
			mount[tmp.x+1][tmp.y].inPath=true;
		}
		if(tmp.x>0&&!mount[tmp.x-1][tmp.y].inPath&&mount[tmp.x-1][tmp.y].h>=minh&&mount[tmp.x-1][tmp.y].h<=maxh)
		{	path.push(point(tmp.x-1,tmp.y));
		mount[tmp.x-1][tmp.y].inPath=true;}
		if(tmp.y<N&&!mount[tmp.x][tmp.y+1].inPath&&mount[tmp.x][tmp.y+1].h>=minh&&mount[tmp.x][tmp.y+1].h<=maxh)
		{	path.push(point(tmp.x,tmp.y+1));
		mount[tmp.x][tmp.y+1].inPath=true;
		}
		if(tmp.y>0&&!mount[tmp.x][tmp.y-1].inPath&&mount[tmp.x][tmp.y-1].h>=minh&&mount[tmp.x][tmp.y-1].h<=maxh)
		{	path.push(point(tmp.x,tmp.y-1));
		mount[tmp.x][tmp.y-1].inPath=true;
		}
	}
	if(mount[N-1][N-1].inPath)
		return true;
	else
		return false;
};

int pathheight(int minh,int maxh)
{
	int mid;
	bool flag;
	while(minh<maxh)
	{
		mid=(minh+maxh)/2;
		flag=false;
		for(int i=0;i<=maxh-mid;i++)
		{
			if(havepath(i,i+mid))
			{
				flag=true;
				break;
			}
		}
		if(flag)
			maxh=mid;
		else
			minh=mid+1;
	}
	return minh;
}

int main()
{
	cin>>N;
	int minh=150,maxh=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			cin>>mount[i][j].h;
			if(mount[i][j].h<minh)
				minh=mount[i][j].h;
			if(mount[i][j].h>maxh)
				maxh=mount[i][j].h;
		}
	cout<<pathheight(0,maxh-minh)<<endl;
	return 0;
}*/
