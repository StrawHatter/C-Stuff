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
int current_password = 0;
volatile bool password_reached = false;
condition_variable password_cv;
mutex password_m;

void myThreadFunc(int search_between, int i) {


	for (int n = (search_between * i); n <= (search_between * (i + 1)); n++) {

		//if (current_password == password) {
			password_m.lock();
			password_cv.notify_all();
			password_reached = true;
			password = current_password;
			password_m.unlock();
			return;
		//}
		password_m.lock();
		current_password = current_password + 1;
		password_m.unlock();

	}
}

int main() {
	int search_between = max_password_limit / 3;	   //setting a number for threads to check between (0-332) (333-665) (666-999)

	thread myThreads[3];		//setting number of threads

	for (int i = 0; i < 3; i++) {
		myThreads[i] = thread(myThreadFunc, search_between, i);
	}

	unique_lock<mutex> lk(password_m);
	password_cv.wait(lk, [] { return password_reached; });
	cout << password_reached << endl;

	for (int n = 0; n < 3; n++) {
		myThreads[n].join();
	}
	cout << current_password << endl;
}
