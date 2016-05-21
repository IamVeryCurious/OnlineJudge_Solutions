#include <iostream>
#include <vector>
using namespace std;
struct date
{
    int year;
    int month;
    int day;
};
int dayofweek(int year,int month,int day)
{
    static int t[]={0,3,2,5,0,3,5,1,4,6,2,4};
    year-=month<3;
    int ans=(year+year/4-year/100+year/400+t[month-1]+day)%7;
    if(ans==0) ans=7;
    return ans;
}
int days_between_dates(int year,int month,int day)
{
    if((month-=2)<=0)
    {
        year--;
        month+=12;
    }
    return (year/4 - year/100 + year/400 + 367*month/12 +day + year*365);
}
int festivals(int year1,int year2,vector<int>& result)
{
    for(int i=year1;i<=year2;i++)
    {
        result.push_back(days_between_dates(i,1,1));
        result.push_back(days_between_dates(i,5,1));
        result.push_back(days_between_dates(i,5,2));
        result.push_back(days_between_dates(i,5,3));
        result.push_back(days_between_dates(i,10,1));
        result.push_back(days_between_dates(i,10,2));
        result.push_back(days_between_dates(i,10,3));
        result.push_back(days_between_dates(i,10,4));
        result.push_back(days_between_dates(i,10,5));
        result.push_back(days_between_dates(i,10,6));
        result.push_back(days_between_dates(i,10,7));
    }
    return 0;
}
int main()
{
    int n;
    char a;
    cin>>n;
    date tp1;
    date tp2;
    for(int i=0;i<n;i++)
    {
        int total=0;
        vector<int> res;
        cin>>tp1.year>>a>>tp1.month>>a>>tp1.day;
        cin>>tp2.year>>a>>tp2.month>>a>>tp2.day;
        festivals(tp1.year,tp2.year,res);
        int ans1=dayofweek(tp1.year,tp1.month,tp1.day);
        int ans2=dayofweek(tp2.year,tp2.month,tp2.day);
        int left_year=days_between_dates(tp1.year,tp1.month,tp1.day);
        int right_year=days_between_dates(tp2.year,tp2.month,tp2.day);
        int cycle=(right_year-left_year-7+ans1-ans2)/7;
        total+=(right_year-left_year+1)-cycle*2;
      if(ans1<=6) total=total-2;
        else total=total-1;
        if(ans2>=6) total=total-(ans2-5);
        int i1=-1,j1=res.size();
        while(res[++i1]<left_year);
      while(res[--j1]>right_year);
        total=total-(j1-i1+1);
        for(int t=i1;t<=j1;t++)
        {
            int tp=(res[t]-left_year+ans1)%7;
            if(tp==0||tp==6) total++;
        }
        cout<<total<<endl;
    }
    return 0;
}
