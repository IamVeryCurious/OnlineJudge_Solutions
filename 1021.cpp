#include<iostream>
#include<iomanip>
 
using namespace std;
 
int main()
{
  int N,num[150][150],row=0,column=-1,elem=0;
  cin>>N;
  for(int i=0;i<N;i+=2)
  {
    for(int j=0;j<N-i;j++)
    {
      num[row][++column]=++elem;
    }
    for(int j=1;j<N-i;j++)
    {
      num[++row][column]=++elem;
    }
    for(int j=1;j<N-i;j++)
    {
      num[row][--column]=++elem;
    }
    for(int j=1;j<N-1-i;j++)
    {
      num[--row][column]=++elem;
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      cout<<setw(6)<<num[i][j];
    cout<<endl;
  }
  return 0;
}

