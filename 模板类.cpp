#include<iostream>
using std::cin;
using std::cout;
using std::endl;
template<class T ,int n>
class stack {
	T stacks[n];
	int top;
public:
	stack();
	~stack(){};
	bool push(T);
	bool pop(T&);
	T topn(T&)const;
};
template<class T,int n>
stack<T,n>::stack() {
	top = 0;
}
template<class T,int n>
bool stack<T,n>::push(T m) {
	if (top < n) {
		top++;
		stacks[top] = m;
		return true;
	}
	else return false;
}
template<class T,int n>
bool stack<T,n>::pop(T& m) {
	if (top > 0) {
		m = stacks[top];
		top--;
		return true;
	}
	else
		return false;
}
template<class T,int n>
T stack<T,n>::topn(T& m)const {
	if (top > 0 && top < n) {
		m = stacks[top];
	}
	else if (top <= 0) {
		cout << "is empty" << endl;
	}
	else if (top>= n) {
		cout << "is full" << endl;
	}
	return m;
} 
int main() {
	stack<int,10>st;
	int m = 0, i;
	for (i = 0; i < 10; i++) {
		cout << "please import number" << endl;
		cin >> m;
		st.push(m);
	}
	cout << st.topn(m) << endl;
	stack<char,10>st1;
	cout<<"alphabet stack"<<endl;
	char f;
	for (i = 0; i < 10; i++) {
		cout << "please import alphabet" << endl;
		cin >> f;
		st1.push(f);
	}
	cout << st1.topn(f) << endl;
	return 0;
	system("pause");
}