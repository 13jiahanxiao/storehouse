#include<stdio.h>
#include<stdlib.h>
#define INT 4;
typedef int et;
typedef struct {
	et *date;
	int length;
	int listsize;
}sqlist;
void intlist(sqlist *l) {
	l->date = (et*)malloc(sizeof(et) * INT);
	l->length = 0;
	l->listsize = INT;
}
void get(sqlist *l) {
	int i = 0;
	for (i = 0; i < 4; i++)
		scanf("%d", l->date[i]);
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
int main() {
	sqlist *l;
	int i;
	intlist(l);
	get(l);
	for (i = 0; i < 4; i++) {
		printf("%d\t", arr[i]);
	}
	system("pause");
	return 0;
}