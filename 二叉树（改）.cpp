#include<iostream>
using namespace std;
typedef char genre;
typedef struct tree_creat {
	genre data;
	tree_creat *left, *right;
}*tree;
//输入值
void input(tree &start) {
	char c;
	cin >> c;
	if (c != '#') {
		start = new tree_creat;
		start->data = c;
		input(start->left);
		input(start->right);
	}
	else
		start = NULL;
}
//中序遍历（递归）
void midput(tree & t) {
	if (t) {
		midput(t->left);
		cout << t->data;
		midput(t->right);
	}
}
//后序遍历（递归）
void lastput(tree &t) {
	if (t) {
		lastput(t->left);
		lastput(t->right);
		cout << t->data;
	}
}
//叶子节点
int leaf(tree &t) {
	static int n = 0;
	if (t != NULL) {
		if (t->left == NULL && t->right == NULL)
			n++;
		leaf(t->left);
		leaf(t->right);
	}
	return n;
}
//高
int high(tree &t) {
	int h, h1, h2;
	if (t == NULL) h = 0;
	else {
		h1 = high(t->left);
		h2 = high(t->right);
		h = (h1>h2 ? h1 : h2) + 1;
	}
	return h;
}
int node(int a[], int i, tree &t) {
	int m, h, h1, h2;
	if (t == NULL) h = 0;
	else {
		h1 = node(a,i,t->left);
		for (m = 1; m < i; m++)
			if (h1!=0&&h1 == m)
				a[m]=a[m]+1;
		h2 = node(a,i,t->right);
		for (m = 1; m < i; m++)
			if (h2 == m&&h2!=0)
				a[m]=a[m]+1;
		h = (h1>h2 ? h1 : h2) + 1;
	}
	if (h == i) {
		cout << "the same high node:"<<endl;
		for (m = 1; m < i; m++)
			cout << a[m] << endl;
	}
	return h;
}
int main() {
	tree first;
	int n = 0;
	int h = 0;
	cout << "pleasr input " << endl;
	input(first);
	cout << "mid is";
	midput(first);
	cout << endl << "last is";
	lastput(first);
	n = leaf(first);
	h = high(first);
	cout << endl << "leaf is " << n << endl
		<< "high is " << h << endl;
	int *p = new int[h];//vector
	int m = 0;
	for (m = 0; m < h; m++)
		p[m] = 0;
	node(p, h, first);
	system("pause");
	return 0;
}