#include<iostream>
#include<iomanip>
using namespace std;
struct date {
	int day;
	int month;
	int year;
};
bool leapyear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else return 0;
}
int ml[13] = { 0,31,28,31,30,31,30,31,30,30,31,30,31 };
date newdate(date indate, int mds) {
	date nowdate = indate;
	int yeardays = 365;
	if (leapyear(nowdate.year))
		yeardays = 366;
	mds = mds + nowdate.day;
	nowdate.day = 0;
	while (mds / yeardays>1) {
		mds = mds - yeardays;
		nowdate.year++;
		if (leapyear(nowdate.year))
			yeardays = 366;
		else yeardays = 365;
	}
	if (mds>366) {
		mds = mds - yeardays;
		nowdate.year++;
	}
	if (leapyear(nowdate.year))
		ml[2] = 29;
	while (mds / ml[nowdate.month]>1) {
		mds = mds - ml[nowdate.month];
		nowdate.month++;
		if (nowdate.month >= 13) {
			nowdate.month = nowdate.month - 12;
			nowdate.year++;
		}
		if (leapyear(nowdate.year))
			ml[2] = 29;
		else ml[2] = 28;
	}
	if (leapyear(nowdate.year))
		ml[2] = 29;
	if (mds<ml[nowdate.month])
		nowdate.day = mds;
	if (mds >=ml[nowdate.month]) {
		while (mds > ml[nowdate.month]) {
			mds = mds - ml[nowdate.month];
			nowdate.month++;
			if (nowdate.month > 12) {
				nowdate. month = nowdate.month - 12;
				nowdate.year++;
			}
		}
		nowdate.day = mds;
	}
	if (nowdate.day == 0) {
		nowdate.day = 1;
		nowdate.month++;
	}
	if (nowdate.month>12) {
		nowdate.month = nowdate.month - 12;
		nowdate.year++;
	}
	return nowdate;
}

int main(void) {
	int mds;
	date indate;
	cout << "please input a date;" << endl;
	cin >> indate.year >> indate.month >> indate.day;
	cout << "please input days" << endl;
	cin >> mds;
	mds = mds - 1;
	date result;
	result = newdate(indate, mds);
	cout << result.year << "-" << setfill('0') << setw(2) << result.month << "-" << setfill('0') << setw(2) << result.day << endl;
}