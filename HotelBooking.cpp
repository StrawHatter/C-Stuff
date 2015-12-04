//  The famous first program  

#include <iostream>
#include <string>

using namespace std;

enum RoomChoice { D, T, S, F, ERROR };

void main()
{
	int no_nights;
	int total = 0;
	char check;
	char code = ' ';

	RoomChoice Choice = ERROR;

	cout << "Room		   Price	Code\n";
	cout << "------------------------------------\n";
	cout << "Deluxe Room        \x9C 200		D\n";
	cout << "Twin Room          \x9C 150		T\n";
	cout << "Single             \x9C 110		S\n";

	while (code != 'F'){
		cout << "What room type would you like? Please use the corresponding Room Code. Press F when you have finished booking any number of rooms. Press 'Ctrl + C' to exit the program at any time. \n";
		cin >> code;
		if (code != 'F') {
			cout << "How many nights would you like to stay?\n";
			cin >> no_nights;
		}
		switch (code) {
		case 'D':
			Choice = D;
			break;
		case 'T':
			Choice = T;
			break;
		case 'S':
			Choice = S;
			break;
		case 'F':
			Choice = F;
			break;
		default:
			Choice = ERROR;
		}

		switch (Choice) {
		case D:
			total = no_nights * 200 + total;
			break;
		case T:
			total = no_nights * 150 + total;
			break;
		case S:
			total = no_nights * 110 + total;
			break;
		case F:

			cout << "Do you have a groupon voucher? Please enter 'Y' or 'N'.";
			cin >> check;

			if (check == 'Y'){
				cout << "\x9C" << (total * 0.85);
			}
			else {
				cout << "\x9C" << total;
			}
			break;
		default:
			cout << "You have entered a error. Please enter a valid Room Code (D, T, S)";
		}

	
	}


}
