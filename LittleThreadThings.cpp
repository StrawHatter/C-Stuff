#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <iostream>

using namespace std;

int score = 0;

void myThreadFunc() {
	for (int i = 0; i < 100; i++) {
		score = score + 1;
	}
}

int main() {
	
	thread myThreads[10];

	for (int i = 0; i < 10; i++) {
		myThreads[i] = thread(myThreadFunc);
	}

	for (int n = 0; n < 10; n++) {
		myThreads[n].join();
	}

	cout << score << endl;
}
