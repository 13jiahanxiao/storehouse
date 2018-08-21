#include <iostream>
using namespace std;
class ftree {
public:
	int data;
	ftree* left;
	ftree* right;
	ftree() :left(NULL), right(NULL) {}
};
class btree {
private:
	ftree * first;
	int *info;
	int size;
	int loc;
	ftree*f;
public:
	btree(int s, int arr[]);
	void createtree(ftree*);
	void create();
	void inordertree(ftree*);
	void inorder();
	ftree* findtree(ftree*, int);
	ftree* find(int);
	void dele(int);
};
btree::btree(int size, int arr[]) {
	loc = 1;
	ftree*f = NULL;
	this->size = size;
	info = new int[this->size];
	for (int i = 0; i < this->size; i++)
		info[i] = arr[i];
}
void btree::createtree(ftree* p) {
	if (loc < size) {
		if (p->data >= info[loc]) {
			if (!p->left) {
				p->left = new ftree();
				p->left->data = info[loc++];
			}
			else
				createtree(p->left);
		}
		else
			if (p->data < info[loc]) {
				if (!p->right) {
					p->right = new ftree();
					p->right->data = info[loc++];
				}
				else
					createtree(p->right);
			}
		createtree(first);
	}
}
void btree::create() {
	first = new ftree();
	if (size)
		first->data = info[0];
	createtree(first);
}
void btree::inordertree(ftree* p) {
	if (p) {
		inordertree(p->left);
		cout << p->data << ' ';
		inordertree(p->right);
	}
}
void btree::inorder() {
	inordertree(first);
}
ftree* btree::findtree(ftree* p, int m) {
	if (p == NULL)return NULL;
	if (p->data == m)return p;
	else {
		f = p;
		if (p->data > m) findtree(p->left, m);
		else findtree(p->right, m);
	}
}
ftree* btree::find(int m) {
	ftree* p = new ftree();
	p = findtree(first, m);
	return p;
}
void btree::dele(int m) {
	ftree*p, *s, *q;
	p = find(m);
	if (!p) {
		cout << "not exist" << endl;
		return;
	}
	if (p->left == NULL) {
		q = p;
		p = p->right;
		if (q == f->right)
			f->right = p;
		else
			f->left = p;
	}
	else if (p->right == NULL) {
		q = p;
		p = p->left;
		if (q == f->right)
			f->right = p;
		else
			f->left = p;
	}
	else {
		q = p;
		s = p->left;
		if (s->right == NULL) {
			s->right = p->right;
			p = s;
			if (q == f->right)
				f->right = p;
			else
				f->left = p;
		}
		else {
			while (s->right != NULL) {
				q = s;
				s = s->right;
			}
			p->data = s->data;
			q->right = NULL;
			if (q == f->right)
				f->right = p;
			else
				f->left = p;
		}
	}
	if (f = NULL)first = p;
	delete q;
	return;
}
int main() {
	int i = 0, s = 0;
	int *arr = new int[100];
	cout << "please import numbers:" << endl;
	while (1) {
		cin >> s;
		if (s != -1) {
			arr[i] = s;
			i++;
		}
		else break;
	}
	btree stree(i, arr);
	stree.create();
	stree.inorder();
	int m;
	cout << endl << "please import your wanna delete:";
	cin >> m;
	stree.dele(m);
	stree.inorder();
	cout << endl;
	return 0;
}