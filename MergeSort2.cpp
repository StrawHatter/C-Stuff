// ConsoleApplication17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void merge(int, int, int);
int arr[] = { 7, -13, 1, 3, 10, 5, 2, 4 };

void merge_sort(int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		merge_sort(low, mid);
		merge_sort(mid + 1, high);
		merge(low, mid, high);
	}
}


void merge(int low, int mid, int high) {
	int h, i, j, brr[50], k;
	h = low;
	i = low;
	j = mid + 1;

	while ((h <= mid) && (j <= high)) {
		if (arr[h] <= arr[j]) {
			brr[i] = arr[h];
			h++;
		}
		else {
			brr[i] = arr[j];
			j++;
		}
		i++;
	}

	if (h>mid) {
		for (k = j; k <= high; k++) {
			brr[i] = arr[k];
			i++;
		}
	}
	else {
		for (k = h; k <= mid; k++) {
			brr[i] = arr[k];
			i++;
		}
	}
	for (k = low; k <= high; k++) {
		arr[k] = brr[k];
	}
}
void main(){
	int num, i;
	num = sizeof(arr) / sizeof(int);

	merge_sort(1, num);
	cout << endl;
	cout << "So, the sorted list (using MERGE SORT) will be :" << endl;
	cout << endl << endl;

	for (i = 1; i <= num; i++) {
		cout << arr[i] << "	";
	}

	cout << endl << endl << endl << endl;

}
