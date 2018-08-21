#include<iostream>
#include<string>
using namespace std;
class person {
	string telephone;
	string name;
	string address;
public:
	person(string, string, string);
	~person() {};
	void inputdata(string, string, string);
	void show();
};
class staff :virtual public person {
	string department;
	int salary;
public:
	staff(string, string, string, string, int);
	staff(string, int, person);
	~staff() {};
	void inputdata(string, string, string, string, int);
	void show();
	void shows();
};
class student :virtual public person {
	string major;
public:
	student(string, string, string, string);
	student(string m, person tp);
	~student() {};
	void inputdata(string, string, string, string);
	void show();
	void shows();
};
class teacher :virtual public staff {
	string subject;
public:
	teacher(string, string, string, string, int, string);
	teacher(staff, string);
	~teacher() {};
	void inputdata(string, string, string, string, int, string);
	void show();
	void shows();
};
class sr :public teacher, public student {
public:
	sr(string, string, string, string, int, string, string);
	sr(student t, teacher p);
	~sr() {};
	void inputdata(string, string, string, string, int, string, string);
	void show();
};
person::person(string t = "empty", string n = "name", string a = "address") {
	telephone = t;
	name = n;
	address = a;
}
void person::inputdata(string t, string n, string a) {
	telephone = t;
	name = n;
	address = a;
}
void person::show() {
	cout << "telephone number:" << telephone << endl
		<< "name:" << name << endl
		<< "address:" << address << endl;
}
staff::staff(string t = "empty", string n = "name", string a = "address", string d = "department", int s = 0) :person(t, n, a) {
	department = d;
	salary = s;
}
staff::staff(string d, int s, person tp) : person(tp) {
	department = d;
	salary = s;
}
void staff::inputdata(string t, string n, string a, string d, int s) {
	person::inputdata(t, n, a);
	department = d;
	salary = s;
}
void staff::show() {
	person::show();
	cout << "department:" << department << endl
		<< "salary:" << salary << endl;
}
void staff::shows(){
	cout << "department:" << department << endl
		<< "salary:" << salary << endl;
}
student::student(string t = "empty", string n = "name", string a = "address", string m = "major") :person(t, n, a) {
	major = m;
}
student::student(string m, person tp) : person(tp) {
	major = m;
}
void student::inputdata(string t, string n, string a, string m) {
	person::inputdata(t, n, a);
	major = m;
}
void student::show() {
	person::show();
	cout << "major:" << major << endl;
}
void student::shows(){
	cout << "major:" << major << endl;
}
teacher::teacher(string t = "empty", string n = "name", string a = "address", string d = "department", int s = 0, string u = "subject") :person(t, n, a), staff(t, n, a, d, s) {
	subject = u;
}
teacher::teacher(staff tp, string u) : staff(tp) {
	subject = u;
}
void teacher::inputdata(string t, string n, string a, string d, int s, string u) {
	staff::inputdata(t, n, a, d, s);
	subject = u;
}
void teacher::show() {
	staff::show();
	cout << "subject:" << subject << endl;
}
void teacher::shows(){
	cout << "subject:" << subject << endl;
}
sr::sr(string t = "empty", string n = "name", string a = "address", string d = "department", int s = 0, string u = "subject", string m = "major") :person(t, n, a), staff(t, n, a, d, s), teacher(t, n, a, d, s, u), student(t, n, a, m) {
}
sr::sr(student t, teacher p) : student(t), teacher(p) {
}
void sr::inputdata(string t, string n, string a, string d, int s, string u, string m) {
	teacher::inputdata(t, n, a, d, s, u);
	student::inputdata(t, n, a, m);
}
void sr::show() {
	person::show();
	staff::shows();
	teacher::shows();
	student::shows();
}
int main() {
	string t, n, a, d, u, m;
	int s;
	cout << "please input telrphone,name,address,department,salary,subject,major" << endl;
	cin >> t >> n >> a >> d >> s >> u >> m;
	sr sr1(t, n, a, d, s, u, m);
	sr1.show();
	return 0;
}
