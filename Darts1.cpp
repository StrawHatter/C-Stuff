#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */


using namespace std;


	int main()
	{
		int iSecret, no_bulls, no_throws, no_simulations, avg_throws, avg_bulls;

		no_throws = 0;
		no_bulls = 0;
		no_simulations = 0;
		avg_bulls = 0;
		avg_throws = 0;

		/* initialize random seed: */
		srand(time(NULL));

		/* tells us if iSecret hits the 70% mark or not (1 = hit, 0 = miss) */
		//iSecret = (rand() % 100 < 70); - added this in order to 

		do {
			do {
				iSecret = (rand() % 100 < 70);
				// cout << iSecret << "Hit or Miss - 1 = hit" << endl; This line was purely for testing purposes 
				if (iSecret == 1){
					no_throws++;
					no_bulls++;
				}
				if (iSecret == 0){
					no_throws++;
				}

			} while (no_bulls < 10);

			cout << "No. Throws: " << no_throws << endl;
			cout << "No. Bulls hit: " << no_bulls << endl;
			avg_bulls = no_bulls + avg_bulls;
			avg_throws = no_throws + avg_throws;
			no_throws = 0;
			no_bulls = 0;
			no_simulations++;
		} while (no_simulations < 100);
		cout << "Total Throws: " << avg_throws << endl;
		cout << "Total Bulls: " << avg_bulls << endl;
		cout << (float(avg_bulls) / float(avg_throws)) << endl;


		return 0;
}

