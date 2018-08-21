#include<iostream>
#include<string>
using namespace std;
class student {
private:
	string name;
	int number;
	int gpa;
public:
	student(string, int, int);
	void get();
	void put();
	int fen();
};
student::student(string nam="nam", int h = 0, int m = 0) {
	name = nam;
	number = h;
	gpa = m;
}
void student::get() {
	cin >> name >> number >> gpa;
}
void student::put() {
	cout << name << number << gpa << endl;
}
int student::fen() {
	return gpa;
}
student students[5];
student temp;
int main() {
	int i = 0;
	int j = 0;
	for (i = 0; i < 5; i++)
		students[i].get();
	for (i = 5; i>0; i--)
		for (j = 0; j<i; j++)
			if (students[j].fen() > students[j + 1].fen()) {
				temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
	for (i = 4; i >= 0; i--)
		students[i].put();
}