// ConsoleApplication16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::swap;
using std::cin;


void print(int *a, int n){

	int i = 0;
	while (i < n){
		cout << a[i] << ",";
		i++;
	}
	cout << "\n";
}

int parition(int *arr, const int left, const int right){
	const int mid = left + (right - left) / 2;
	const int pivot = arr[mid];
	swap(arr[mid], arr[left]);
	int i = left + 1;
	int j = right;

	while (i <= j){
		while (i <= j && arr[i] <= pivot){
			i++;
		}
		while (i <= j && arr[j] > pivot) {
			j--;
		}

		if (i < j) {
			swap(arr[i], arr[j]);
		}
		swap(arr[i - 1], arr[left]);
		return i - 1;
	}
}

void quickSort(int *arr, const int left, const int right, const int sz){

	if (left >= right){
		return;
	}

	int part = parition(arr, left, right);
	cout << "QSC:" << left << "," << right << " part=" << part << endl;
	print(arr, sz);

		quickSort(arr, left, part - 1, sz);
		quickSort(arr, part + 1, right, sz);
}

int main(){
	int input123;
	int arr[13] = { 110, 5, 10, 3, 22, 100, 1, 23, 7, 3, 6, 7, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	quickSort(arr, 0, sz - 1, sz);
	print(arr, sz);

	cin >> input123;
	if (input123 = 5){
		return 0;
	}

	//return 0;
}
