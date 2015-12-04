
#include <iostream>
#include <string>
#include <windows.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace std;

enum HungryState { W, P, H, S, D };    // Well-Fed, Slightly Pekish, Hungry, Starving, Dead
enum SleepState { WA, A, T, FA, C };   // Wide-Awake, Awake, Tired, Falling-Asleep, Collapsed

//string happiness(string one1, string two2){

// go through each of the possible variations and give a value based on points
// 10 max
// 0 lowest
// 
//}


string petName(string checking) {


	string nameOfPet;

	if (checking == "Yes") {
		cout << "What would you like to name your pet? ";
		cin >> nameOfPet;
	}
	else {
		nameOfPet = "your pet";
	}
	return nameOfPet;
}

int main() {

	char checkFeed;
	string checkname;
	string nameOfPet;
	bool isAlive = true;

	HungryState Hungry = P;
	SleepState Sleepy = T;

	cout << "Would you like to name your pet? Please type 'Yes' or 'No'." << endl;
	cin >> checkname;

	nameOfPet = petName(checkname);

	do {
		cout << "Press 'F' to feed your pet! 'S' to check if they're tired and 'Q' to quit!" << endl;
		cin >> checkFeed;

		std::this_thread::sleep_for(std::chrono::seconds(1/2));

			switch (checkFeed) {
			case 'F':
				switch (Hungry) {
				case W:
					Hungry = W;
					cout << "dfsdf";
					break;
				case P:
					Hungry = W;
					cout << "heasf";
					break;
				case H:
					Hungry = P;
					cout << "heolo";
					break;
				case S:
					Hungry = H;
					cout << "hi";
					break;
				case D:
					Hungry = S;
					cout << nameOfPet << " is dead." << endl;
					break;
				}
		case 'Q':
			return 0; //enum SleepState { WA, A, T, FA, C };   // Wide-Awake, Awake, Tired, Falling-Asleep, Collapsed
		//case 'P':
			//happiness++; increases happiness
			//cout << nameOfPet << " your pet is " << happiness << " this happy!" << endl;
			//break;
		case 'S':
			switch (Sleepy){
			case WA:
				Sleepy = WA;
				break;
			case A:
				Sleepy = WA;
				break;
			case T:
				Sleepy = A;
				break;
			case FA:
				Sleepy = T;
				break;
			case C:
				Sleepy = FA;
				break;
			}

			switch (Hungry){
			case W:
				cout << nameOfPet << " is well-fed." << endl;
				break;
			case P:
				cout << nameOfPet << " is fairly peckish." << endl;
				break;
			case H:
				cout << nameOfPet << " is hungry." << endl;
				break;
			case S:
				cout << nameOfPet << " is starving." << endl;
				break;
			case D:
				cout << nameOfPet << " is dead." << endl;
				break;
			}

			switch (Sleepy){
			case WA:
				cout << nameOfPet << " is wide-awake." << endl;
				break;
			case A:
				cout << nameOfPet << " is awake." << endl;
				break;
			case T:
				cout << nameOfPet << " is tired." << endl;
				break;
			case FA:
				cout << nameOfPet << " is fast-asleep." << endl;
				break;
			case C:
				cout << nameOfPet << " is collapsed." << endl;
				break;
			}


			//switch checkFeed finish


		}

	} while (isAlive = true); // while loop finishes
		
	//happiness(char Hungry, char Sleepy)
	//enum HungryState { W, P, H, S, D };    // Well-Fed, Slightly Pekish, Hungry, Starving, Dead
	//enum SleepState { WA, A, T, FA, C };   // Wide-Awake, Awake, Tired, Falling-Asleep, Collapsed
} 
