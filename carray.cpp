#include<iostream>
using namespace std;
class carray {
	int *p;
	int size;
public:
	carray(int);
	void set(int,int);
	~carray() {};
	friend carray operator +(carray, carray);
	void operator =(carray);
	friend carray operator -(carray, carray);
	void show();
};
carray::carray(int size = 0) {
	int i;
	this->size = size;
	p = new int[this->size];
	if (!p) {
		cout << "ÉêÇëÄÚ´æÊ§°Ü" << endl;
		exit(1);
	}
	for (i = 0; i < size; i++) {
		p[i] = 0;
	}
}
void carray::set(int k,int l) {
	size = k;
	int i;
	for (i = 0; i < size; i++)
		p[i] = i +l;
}
carray operator +(carray f, carray l) {
	carray temp;
	int i;
	if (f.size > l.size)
		temp.size = f.size;
	else temp.size = l.size;
	for (i = 0; i < temp.size; i++) {
		if (f.size >i && l.size >i)
			temp.p[i] = f.p[i] + l.p[i];
		if (f.size > i && l.size <= i)
			temp.p[i] = f.p[i] + 0;
		if (f.size <=i&&l.size > i)
			temp.p[i] = 0 + l.p[i];
	}
	return temp;
}
void carray::operator =(carray t) {
	this->p = t.p;
	this->size = t.size;
}
carray operator -(carray f, carray l) {
	carray temp;
	int i;
	if (f.size > l.size)
		temp.size = f.size;
	else temp.size = l.size;
	for (i = 0; i < temp.size; i++) {
		if (f.size >i && l.size >i)
			temp.p[i] = f.p[i] -l.p[i];
		if (f.size > i && l.size <= i)
			temp.p[i] = f.p[i] - 0;
		if (f.size <= i && l.size > i)
			temp.p[i] = 0 - l.p[i];
	}
	return temp;
}
void carray::show() {
	int i;
	for (i = 0; i < size; i++)
		cout << p[i] << endl;
}
int main() {
	carray t(6), k(7),s(7);
	t.set(6, 1);
	k.set(7,2);
	s = t + k;
	s.show();
	return 0;
}