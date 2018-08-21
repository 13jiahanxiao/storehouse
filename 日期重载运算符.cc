#include<iostream>
using namespace std;
class date {
	int day;
	int month;
	int year;
public:
	date(int, int, int);
	void reset(int, int, int);
	bool leapyear(int);
	void operator +=(int);
	void operator -=(int);
	date operator ++();
	date operator ++(int);
	date operator --();
	date operator --(int);
	friend bool operator >(date, date);
	friend bool operator <(date, date);
	friend bool operator ==(date, date);
	friend bool operator !=(date, date);
	void show();
};
date::date(int year = 2009, int month = 1, int day = 1) {
	this->year = year;
	this->month = month;
	this->day = day;
}
void date::reset(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}
bool date::leapyear(int years) {
	if (years % 4 == 0 && years % 100 != 0 || years % 400 == 0)
		return 1;
	else return 0;
}
void date:: operator+=(int mds) {
	int ml[13] = { 0,31,28,31,30,31,30,31,30,30,31,30,31 };
	int yeardays = 365;
	if (leapyear(year))
		yeardays = 366;
	day = day + mds;
	while ((day / yeardays) >= 1) {
		day = day - yeardays;
		year++;
		if (leapyear(year))
			yeardays = 366;
		else yeardays = 365;
		if (day == 0)
			day++;
	}
	if (leapyear(year))
		ml[2] = 29;
	else ml[2] = 28;
	while ((day / ml[month]) >= 1) {
		day = day - ml[month];
		month++;
		if (month >= 13) {
			month = month - 12;
			year++;
		}
		if (leapyear(year))
			ml[2] = 29;
		else ml[2] = 28;
		if (day == 0)
			day++;
	}
}
void date:: operator-=(int mds) {
	int ml[13] = { 0,31,28,31,30,31,30,31,30,30,31,30,31 };
	int yeardays = 365;
	if (leapyear(year))
		yeardays = 366;
	day = day - mds;
	if (day < 0) {
		while ((day / yeardays) <= -1) {
			day = day + yeardays;
			year--;
			if (leapyear(year))
				yeardays = 366;
			else yeardays = 365;
			if (day == 0)
				day++;
		}
		if (leapyear(year))
			ml[2] = 29;
		else ml[2] = 28;
		while ((day / ml[month]) <= -1) {
			day = day + ml[month];
			month--;
			if (month == 0) {
				month = month + 12;
				year--;
			}
			if (leapyear(year))
				ml[2] = 29;
			else ml[2] = 28;
			if (day == 0)
				day++;
		}
		if (month - 1 == 0) {
			month = 12;
			day = day + 31;
		}
		day = ml[--month] + day;
	}
}
date date::operator ++() {
	int ml[13] = { 0,31,28,31,30,31,30,31,30,30,31,30,31 };
	if (day ==ml[month]) {
		if (month == 12) {
			year++;
			month = 0;
		}
		month++;
		day = 0;
	}
	day = day + 1;
	return *this;
}
date date::operator++(int) {
	date temp = *this;
	int ml[13] = { 0,31,28,31,30,31,30,31,30,30,31,30,31 };
	if (day == ml[month]) {
		if (month == 12) {
			year++;
			month = 0;
		}
		month++;
		day = 0;
	}
	day = day + 1;
	return temp;
}
date date::operator --() {
	int ml[13] = { 0,31,28,31,30,31,30,31,30,30,31,30,31 };
	if (day ==1) {
		if (month == 1) {
			year--;
			month = 13;
		}
		month--;
		day = ml[month]+1;
	}
	day = day -1;
	return *this;
}
date date::operator --(int) {
	date temp = *this;
	int ml[13] = { 0,31,28,31,30,31,30,31,30,30,31,30,31 };
	if (day == 1) {
		if (month == 1) {
			year--;
			month = 13;
		}
		month--;
		day = ml[month]+1;
	}
	day = day - 1;
	return temp;
}
bool operator >(date f, date l) {
	if (f.year > l.year)
		return 1;
	if (f.year < l.year)
		return 0;
	if (f.year == l.year) {
		if (f.month > l.month)
			return 1;
		if (f.month < l.month)
			return 0;
		if (f.month == l.month) {
			if (f.day > l.day)
				return 1;
			else return 0;
		}
	}
}
bool operator <(date f, date l) {
	if (f.year < l.year)
		return 1;
	if (f.year > l.year)
		return 0;
	if (f.year == l.year) {
		if (f.month < l.month)
			return 1;
		if (f.month > l.month)
			return 0;
		if (f.month == l.month) {
			if (f.day < l.day)
				return 1;
			else return 0;
		}
	}
}
bool operator ==(date f, date l) {
	if (f.year == l.year)
		if (f.month == l.month)
			if (f.day == l.month)
				return 1;
	return 0;
}
bool operator !=(date f, date l) {
	if (f.year == l.year)
		if (f.month == l.month)
			if (f.day == l.month)
				return 0;
	return 1;
}
void date::show() {
	cout << year << "-" << month << "-" << day << endl;
}
int main(void) {
	int year, month, day;
	int a=0,mds=0;;
	cout << "please input a date;" << endl;
	cin >> year >> month >> day;
	cout<<"please choice mode:"<<endl;
	cout<<"1.+=  2.-=  3.++  4.--"<<endl
		<<"5.>  6.<  7.==  8.!="<<endl;
	cin>>a;
	date indate;
	indate.reset(year, month, day);
	switch(a){
		case 1:{
		cout << "please input days" << endl;
		cin >> mds;
		indate+=mds;
		indate.show();
		break;
		}
		case 2:{
		cout << "please input days" << endl;
		cin >> mds;
		indate-=mds;
		indate.show();
		break;
		}
	}
	system("pause");
	return 0;
}