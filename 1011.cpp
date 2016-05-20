#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class MyComplex
{
private:
	double x,y;
public:
	MyComplex(double r,double i){x=r;y=i;}
	MyComplex(){x=0;y=0;}
	MyComplex operator+(const MyComplex z)
	{
		return MyComplex(x+z.x,y+z.y);
	}
	MyComplex operator+=(const MyComplex z)
	{
		x+=z.x;
		y+=z.y;
		return *this;
	}
	MyComplex operator-(const MyComplex z)
	{
		return MyComplex(x-z.x,y-z.y);
	}
	MyComplex operator-=(const MyComplex z)
	{
		x-=z.x;
		y-=z.y;
		return *this;
	}
	MyComplex operator*(const MyComplex z)
	{
		return MyComplex(x*z.x-y*z.y,x*z.y+y*z.x);
	}
	MyComplex operator*=(const MyComplex z)
	{
		MyComplex tmp=*this;
		x=tmp.x*z.x-tmp.y*z.y;
		y=tmp.x*z.y+tmp.y*z.x;
		return *this;
	}
	MyComplex operator/(const MyComplex z)
	{
		return MyComplex((x*z.x+y*z.y)/(z.x*z.x+z.y*z.y),(y*z.x-x*z.y)/(z.x*z.x+z.y*z.y));
	}
	MyComplex operator/=(const MyComplex z)
	{
		MyComplex tmp=*this;
		x=(tmp.x*z.x+tmp.y*z.y)/(z.x*z.x+z.y*z.y);
		y=(tmp.y*z.x-tmp.x*z.y)/(z.x*z.x+z.y*z.y);
		return *this;
	}
	friend ostream& operator<<(ostream &os,const MyComplex z)
	{
		printf("%.2f %.2f",z.x,z.y);
		return os;
	}
	friend istream& operator>>(istream &is,MyComplex &z)
	{
		is>>z.x>>z.y;
		return is;
	}
};

int main()
{
	MyComplex z1;
	MyComplex z2;

	cin >> z1 >> z2;

	cout << z1 + z2 <<endl;
	cout << z1 - z2 <<endl;
	cout << z1 * z2 <<endl;
	cout << z1 / z2 <<endl;
	cout << (z1 += z2) <<endl;
	cout << (z1 -= z2) <<endl;
	cout << (z1 *= z2) <<endl;
	cout << (z1 /= z2) <<endl;

	return 0;
}