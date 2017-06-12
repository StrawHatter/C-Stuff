# include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread> 

using std::thread;
using std::iostream;
using namespace std;


//defining struct integers for pointer things
struct threadArgs { 
	int foo;
	int bar;
};

//void thread that takes in pointer struct *ptr
//outputs the values before changing it, and returning it
void myThreadFunc(threadArgs *ptr) {

	cout << (*ptr).foo << endl;
	cout << (*ptr).bar << endl;
	ptr->foo = 7;


}

//main function sets a pointer variable *ptr and normal var args
//of type threadArgs
//the address of variable args is stored in the pointer variable ptr
//then the member of args is accessed by a pointer 
//point values 
//make a new thread that exeucted the myThreadFunc with the ptr variable args
//once thread finishes, join it and output the changed value. 
int main() {
	
	threadArgs *ptr, args;

	ptr = &args;

	ptr->foo = 5;
	ptr->bar = 2;

	thread myThread(myThreadFunc, ptr);
	myThread.join();
	cout << (*ptr).foo << endl;
}

//when passing by value, the value given is changed due to a copy of the value being 
//created in memory, if i tried printing it before joining the thread, output = 7
