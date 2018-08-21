#include<iostream>
#include<cmath>
using namespace std;
class segment {
	int x1, y1, x2, y2;
public:
	segment(int, int, int, int);
	~segment() {};
	void input(int, int ,int ,int);
	double length();
};
class polygon:public segment {
	int number;
public:
	polygon(int a,int b,int a1,int b1,int n=0) :segment(a,b,a1,b1){
		number = n;
	};
	~polygon() {};
	void input(int a,int b,int a1,int b1,int n) {
		segment::input(a, b, a1, b1);
		number = n;
	}
};
class trans :public polygon {
public:
	trans(int a,int b,int a1,int b1,int n):polygon(a,b,a1,b1,n){}
	~trans() {};
	double perimeter() {
		double  p;
		p = length() * 3;
		return p;
	}
	double area() {
		double a;
		a = (sqrt(3)*length()*length()) / 4;
		return a;
	}
};
segment::segment(int a1 = 0, int b1 = 0,int a2=0, int b2 = 0) {
	x1 = a1;
	x2 = a2;
	y1 = b1;
	y2 = b2;
}
void segment::input(int a, int b, int a1, int b1) {
	x1 = a;
	x2 = a1;
	y1 = b;
	y2 = b1;
}
double segment::length() {
	int x,y,l;
	double i;
	if(x1>x2)x = x1 - x2;
	else x = x2 - x1;
	if (y1 > y2)y = y1 - y2;
	else y = y2 - y1;
	l = x * x + y * y;
	i = sqrt(l);
	return i;
}
int main() {
	trans tt(4, 4, 5, 5, 9);
	double p, l,a;
	l = tt.length();
	p = tt.perimeter();
	a = tt.area();
	cout << l << endl
		<< p << endl
		<< a << endl;
	return 0;
}
