#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <time.h>


//Simple trace function to test things out.
void trace(std::string message)
{
	std::cout << message << "\n";
};

//Accuracy of both players when aiming for anything but the center.
#define BASE_ACCURACY 80 

//Globaly initialize board so it can be used in class functions.
const int board [20] = {20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5}; 

class Player
{
private:
	//Class variables and constants
	static const int ACCURACY = BASE_ACCURACY;
	int bull_accuracy;			

	//Class functions
	int State(); //Based on score remaining, chance state of the player.
	int Aim(); //Find the segment to aim for in order to get as close to 50 as possible
	int Throw(); //Use the Aim value and try to hit it.
	int Score_Update(); //Function to update score for each player.

public:
	//Class variables and constants
	int score;
	short int state;
	int score_hit; // What did you hit
	int aiming; //What is the player aiming for.
	bool won; //Whether the player won or not.

	Player(int); //constructor

	void Play(); //The function used for the player object to play the game.

	//"Exploring program characteristics" values
	int throw_count;
	int wins;
};

//Constructor
Player::Player(int accuracy)
{
	score = 301; //Initialize the Score at start of the game.
	bull_accuracy = accuracy; //The chances of each player to hit the bull.
	state = 0; // Set state to Fast Paced since game just started.
	aiming = 0; // Player is aiming at nothing.
	won = false;
	throw_count = 0;
	wins = 0;
}

//Figuring out the player state (if he's shooting to lower score fast or concentrates to get to exactly 50 as fast as possible).
int Player::State()
{
	if (score > 70)
	{
		state = 0;
	}

	else if (score > 50  && score <= 70)
	{
		state = 1;
	}

	else if ((score == 50) || (score==0))
	{
		state = 2;
	}

	return (state);
}

//Player takes aim and returns the value he aimed for for the Throw function to use.
int Player::Aim()
{
	if (state == 0) //The player is in a state where he or she try to lower the score fast and will always aim for middle to reduce score fast.
	{
		if ((score - 50) > 50)
		{
			aiming = 50;
		}
		else
		{
			aiming = 20;
		}
	}

	if (state == 1) // The Player is in a state of concentration where he or she will try to get to 50 best way possible.
	{
		aiming = score - 50; 
	}

	else if (state == 2) //Player can only aim at the Bull since he has a score of 50
	{
		aiming = 50;
	}

	return (aiming);
}

//Player throws a dart at the value the aim function returned.
int Player::Throw()
{
	unsigned int chance = 0, aiming_position = 0, left_position = 0, right_position = 0;

	chance = rand()%100+1; // Number magic follows, look away so you don't go blind!

	if (aiming == 50)
	{
		if (chance <= bull_accuracy) // Congrats you hit what you aimed for.
		{
			score_hit = aiming;
		}
		else // You missed what you aimed for but hit something else.
		{
			aiming_position = rand()%19;
			score_hit = board[aiming_position];
		}
	}
	else if (aiming != 50)
	{
		if (chance <= ACCURACY)// Congrats you hit what you aimed for.
		{
			score_hit = aiming; 
		}
		else // You missed what you aimed for but hit something else.
		{
			for (int i = 0; i <= 19; i++)
			{
				if (board[i] == aiming)
				{
					aiming_position = i;
				}
			}

			if (aiming_position == 0)
			{
				left_position = 19;
				right_position = aiming_position + 1;
			}

			else if (aiming_position == 19)
			{
				left_position = aiming_position - 1;
				right_position = 0;
			}

			chance = rand()%2;

			if (chance == 0) // Miss and hit the area to the left of where you aimed at.
			{
				score_hit = board[left_position];
			}
			else if (chance == 1) // Miss and hit the area to the right of where you aimed at.
			{
				score_hit = board[right_position];
			}
		}
	}
return score_hit;
}

//After throwing a dart, update the player's individual score.
int Player::Score_Update()
{
	if (state == 0)
	{
		if ( (score - score_hit) < 50)
		{
			score = score;
		}
		else
		{
			score = score - score_hit;
		}
	}
	if (state == 1)
	{
		if ((score - score_hit) < 50)
		{
			score = score;
		}
		else if ((score - score_hit)>=50)
		{
			score = score - score_hit;
		}
	}
	if ((state == 2) && (score_hit == 50))
	{
		score = score - score_hit;
	}
	else
	{
		score = score;
	}

	return score;
}

//Play function to make things secure and simple.
void Player::Play()
{
	State();
	Aim();
	Throw();
	Score_Update();
	throw_count++;

	if (score == 0)
		won = true;
}


int main()
{
	Player joe(70); //Initialize Joe with Bull Accuracy of 72%
	Player sid(72); //Initialize Sid with Bull Accuracy of 70%

	int throws[7] = {0}; //Throw-count array
	int player_switch = 0;
	
	srand ( time(NULL) );

	// Title text and test to make sure some stuff work.
	trace("Joe and Sid playing 301 Darts game!");

	//Adding the 10000 games loop
	for (int game_loops = 0; game_loops < 10000; game_loops++)
	{
		joe.score = 301;
		sid.score = 301;
		joe.throw_count = 0;
		//The game loop
		while ((joe.won == false) && (sid.won == false))
		{
			if ((sid.score != 0) && (player_switch == 0))
			{
				//Sleep(550);
				std::cout<<"Joe's turn: \n";
				std::cout<<"Joe has "<<joe.score<<" points left.\n";
				joe.Play();
				std::cout<<"Joe aims for "<<joe.aiming<<", he hits "<<joe.score_hit<<"\n\n";
				player_switch = 1;
			}
			if ((joe.score != 0) && (player_switch == 1))
			{
				//Sleep(550);
				std::cout<<"Sid's turn: \n";
				std::cout<<"Sid has "<<sid.score<<" points left.\n";
				sid.Play();
				std::cout<<"Sid aims for "<<sid.aiming<<", he hits "<<sid.score_hit<<"\n\n";
				player_switch = 0;
			}
		}
	
		std::cout<<"\n\n";
		if (sid.won == true)
		{
			std::cout<<"Sid won the game!!\n";
			std::cout<<"\n";
			sid.wins ++;
		}
		else
		{
			std::cout<<"Joe won the game!!\n";
			std::cout<<"\n";
			joe.wins++;
		}

		//Put the number of throws in an array.
		if (joe.throw_count == 7)
				throws[0] += 1;
			else if (joe.throw_count == 8)
				throws[1] += 1;
			else if (joe.throw_count == 9)
				throws[2] += 1;
			else if (joe.throw_count == 10)
				throws[3] += 1;
			else if (joe.throw_count == 11)
				throws[4] += 1;
			else if (joe.throw_count == 12)
				throws[5] += 1;
			else
				throws[6] += 1;
	}
	
	std::cout << "Joe won "<< joe.wins << "\n";
	std::cout << "Sid won "<< sid.wins << "\n";
	std::cout << "Throw count:\n\n";
	for (int z = 0; z < 7; z++) 
	{
		std::cout <<"Number of throws needed " << throws[z] << "\n";
	}

	//Pause before exiting.
	//getchar();

	return 0;
};



