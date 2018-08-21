#include<iostream>
#include<string>
using namespace std;
class  publication {
	string title;
	string name;
	int price;
	int date;
public:
	publication(string, string, int, int);
	~publication() {};
	void inputdata(string,string,int,int);
	void display();
};
class book :public publication {
	int page;
public:
	book(string , string , int , int, int );
	book(int, publication);
	~book() {};
	void inputdata(string m,string n,int p,int d,int i);
	void display();
};
class tape :public publication {
	int playtime;
public:
	tape(string, string, int, int, int);
	tape(int, publication);
	~tape() {};
	void inputdata(string,string,int,int,int);
	void display();
};
publication::publication(string m="title", string n="name", int p=0, int d=0) {
	title = m;
	name = n;
	price = p;
	date= d;
}
void publication::inputdata(string m,string n,int p,int d) {
	title = m;
	name = n;
	price = p;
	date = d;
}
void publication::display() {
	cout<<"title:" <<title<<endl
		<<"name:" <<title<<endl
		<<"price:" <<title<< endl
		<<"date:" << title<<endl;
}
book::book(string m = "title", string n = "name", int p = 0, int d = 0, int i = 0) :publication(m, n, p, d) {
	page = i;
}
book::book(int i , publication tp) : publication(tp) {
	page = i;
}
void book::inputdata(string m,string n,int p,int d,int i){
	publication::inputdata(m, n, p, d);
	page = i;
}
void book::display() {
	publication::display();
	cout<<"page:"<<page<<endl;
}
tape::tape(string m = "title", string n = "name", int p = 0, int d = 0, int i = 0) :publication(m, n, p, d) {
	playtime = i;
}
tape::tape(int i , publication tp) : publication(tp) {
	playtime = i;
}
void tape::inputdata(string m,string n,int p,int d,int i) {
	publication::inputdata(m, n, p, d);
	playtime = 0;
}
void tape::display() {
	publication::display();
	cout << "playtime:"<<playtime << endl;
}
book book1;
int main() {
	string m, n;
	int p, d, i;
	cout << "please input title,name,price,date,page or playtime" << endl;
	cin >> m >> n >> p >> d >> i;
	book1.inputdata(m, n, p, d,i);
	book1.display();
}