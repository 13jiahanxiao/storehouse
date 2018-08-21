#include<iostream>
#include<string>
using namespace std;
class student {
public:
	student(string,float);
	void set(string, float);
	void show();
	float gpaz();
	void counts();
private:
	static int count;
	string name;
	float gpa;
};
student::student(string nam = "name", float gpas= 0.0) {
	name = nam;
	gpa = gpas;
}
int student::count = 0;
void student::set(string n,float m) {
	name = n;
	gpa = m;
	count++;
}
void student::show() {
	cout << "name :" << name << endl
		<< "GPA :" << gpa << endl;
}
float student::gpaz() {
	return gpa;
}
void student::counts() {
	cout << "student number :" << count << endl;
}
float cal(student *p) {
	float total = 0.0, avg;
	int i;
	for (i = 0; i < 3 ; i++) {
		total = total + p[i].gpaz();
	}
	avg = total / 3;
	return avg;
}
student students[3];
int main() {
	string n;
	float m;
	int i;
	for (i = 0; i < 3; i++) {
		cout << "please input name" << endl;
		cin >> n;
		cout << "please input gpa" << endl;
		cin >> m;
		students[i].set(n, m);
	}
	for (i = 0; i < 3; i++) {
		students[i].show();
	}
	students[2].counts();
	cout<< "The GPA avg is :" << cal(students) << endl;
	return 0;
}