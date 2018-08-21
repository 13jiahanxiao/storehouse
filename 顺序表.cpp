#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct {
	int *date;
	int length;
	int listsize;
}sqlist;
void intlist(sqlist *l) {
	l->date = (int*)malloc(sizeof(int) * 4);
	l->length = 0;
	l->listsize = 4;
}
void get(sqlist *l) {
	int i = 0;
	for (i = 0; i < 4; i++)
		cin >> l->date[i];
}
void merge(int src[], int des[], int low, int high, int mid) {
	int i = low;
	int k = low;
	int j = mid + 1;
	while ((i <= mid) && (j <= high)) {
		if (src[i] < src[j]) {
			des[k++] = src[i++];
		}
		else {
			des[k++] = src[j++];
		}
	}
	while (i <= mid) {
		des[k++] = src[i++];
	}
	while (j <= high) {
		des[k++] = src[j++];
	}
}
void msort(int src[], int des[], int low, int high, int max) {
	int mid = (low + high) / 2;
	if (low == high) {
		des[low] = src[low];
	}
	else {
		int *space = (int*)malloc(sizeof(int)*max);
		if (space != NULL) {
			msort(src, space, low, mid, max);
			msort(src, space, mid + 1, high, max);
			merge(space, des, low, high, mid);
		}
		free(space);
	}
}
void use(int arr[], int low, int high, int len) {
	msort(arr, arr, low, high, len);
}
void put(sqlist *l) {
	int i;
	for (i = 0; i < 4; i++)
		cout << l->date[i] << endl;
}
int main() {
	sqlist l;
	int i;
	intlist(&l);
	get(&l);
	use(l.date, 0, 4- 1, 4);
	put(&l);
	system("pause");
	return 0;
}