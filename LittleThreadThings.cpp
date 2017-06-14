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


//When sharing a common resource in a thread, you must stop other threads from accessing said resource during computation 
//In order to do this, we create a global mutex that we lock before accessing the common resource
//This prevents all otehr threads from accessing it whilst they are running 
//After we have altered the common resource, we unlock it allowing it to be used again by another thread
