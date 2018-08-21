#include<iostream>
using namespace std;
class circle {
private:
	int r, m, n;
public:
	friend class circlez;
	circle(int, int, int);
	void get();
	void show();
};
class circlez {
private:
	circle bottom;
	int H;
public:
	circlez(circle, int);
	void volume();
	void surface();
};
void circle::show() {
	cout << "preimeter is" << m << endl;
	cout << "area is" << n << endl;
}
circle::circle(int h = 0, int i = 0, int j = 0) {
	r = h;
	m = i;
	n = j;
}
void circle::get() {
	cin >> r;
	m = 2 * 3.14*r;
	n = 3.14*r*r;
}
circlez::circlez(circle s, int h) {
	H = h;
	bottom = s;
}
void circlez::volume() {
	int p;
	p = bottom.n*H;
	cout << " volume is" << p << endl;
}
void circlez::surface() {
	int p;
	p = bottom.m*H + 2 * bottom.n;
	cout << "The surface area is" << p << endl;
}
int main() {
	circle sd;
	sd.get();
	circlez das(sd, 5);
	das.surface();
	return 0;
}