//First thread checks 000 - 323, second checks 333 - 665, third checks 666 - 999. 
//These threads do not need to interact at all.They can be run on entirely different computers.
//implement a variable guessed_the_password which will turn on if one of the threads guesses the password and tells the other threads to stop guessing.

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;


int password = 500;
int max_password_limit = 999;
bool password_reached = false;
condition_variable password_cv;
mutex password_m;

void myThreadFunc() {
	for (int i = 0; i < 1000000; i++) {
		//code goes here

	}
}

int main() {

	thread myThreads[3];

	for (int i = 0; i < 3; i++) {
		myThreads[i] = thread(myThreadFunc);
	}

	for (int n = 0; n < 3; n++) {
		myThreads[n].join();
	}


}
