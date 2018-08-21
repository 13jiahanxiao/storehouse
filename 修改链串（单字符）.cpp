#include <iostream>  
#include<stdio.h>
using namespace std;

 struct String {
	char data;
	struct String *next;
};

void sign(String *&s, char str[]) {
	int i;
	String *r, *p;
	s = new String;
	r = s;
	for (i = 0; str[i] != '\0'; i++) {
		p = new String;
		p->data = str[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

void change(String *s) {
	String *p = s->next, *q;
	int find = 0;
	while (p->next != NULL && find == 0) {
		if (p->data == 'a'&&p->next->data == 'b') {
			p->data = 'x';
			p->next->data = 'z';
			q = new String;
			q->data = 'y';
			q->next = p->next;
			p->next = q;
			find = 1;
		}
		else p = p->next;
	}
}

void disStr(String *s) {
	String *p = s->next;
	while (p != NULL) {
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}

int main() {
	String *s;
	char str[100];
	fgets(str,100,stdin);
	sign(s, str);
	change(s);
	disStr(s);
	system("pause");
	return 0;
}