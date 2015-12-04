
//  A game fragment adapted from Andre La Mothe's book

//	The Black Art of 3D Games Programming

//  Modified by Paul Dreczkowski on the 31/12/2015

//	1.  hconsole - called TEXT( ) for parameter 1
//	2.  added _ as prefix to deprecated kbhit() function
//	3.  added _ as prefix to deprecated getch() function

//	Note: this is very old-fashioned code originally written for 16-bit PCs



// INCLUDES ///////////////////////////////////////////////


# include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string>


// DEFINES ////////////////////////////////////////////////

#define MAX_X        77  // maximum x position for player
#define SCROLL_POS   24  // the point that scrolling occurs

// PROTOTYPES /////////////////////////////////////////////

void Init_Graphics(void);
inline void Set_Color(int fcolor, int bcolor);
inline void Draw_String(int x, int y, char *string);

// GLOBALS ////////////////////////////////////////////////

CONSOLE_SCREEN_BUFFER_INFO con_info;   // holds screen info

HANDLE hconsole;         // handle to console
int    game_running = 1; // state of game, 0=done, 1=run

// FUNCTIONS //////////////////////////////////////////////

void Init_Graphics(void)
{
	// this function initializes the console graphics engine

	COORD console_size = { 80, 25 }; // size of console

	// seed the random number generator with time
	srand((unsigned)time(NULL));

	// open i/o channel to console screen
	hconsole = CreateFile(TEXT("CONOUT$"), GENERIC_WRITE | GENERIC_READ,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		0L, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0L);

	// make sure we are in 80x25
	SetConsoleScreenBufferSize(hconsole, console_size);

	// get details for console screen                       
	GetConsoleScreenBufferInfo(hconsole, &con_info);

} // end Init_Graphics

///////////////////////////////////////////////////////////

inline void Set_Color(int fcolor, int bcolor = 0)
{
	// this function sets the color of the console output
	SetConsoleTextAttribute(hconsole, (WORD)((bcolor << 4) |
		fcolor));

} // Set_Color

///////////////////////////////////////////////////////////

inline void Draw_String(int x, int y, char *string)
{
	// this function draws a string at the given x,y

	COORD cursor_pos; // used to pass coords

	// set printing position
	cursor_pos.X = x;
	cursor_pos.Y = y;
	SetConsoleCursorPosition(hconsole, cursor_pos);

	// print the string in current color
	printf("%s", string);

} // end Draw_String


///////////////////////////////////////////////////////////

inline void Clear_Screen(void)
{
	// this function clears the screen

	// set color to white on black
	Set_Color(15, 0);

	// clear the screen
	for (int index = 0; index <= 25; index++)
		Draw_String(0, SCROLL_POS, "\n");

} // end Clear_Screen

// MAIN GAME LOOP /////////////////////////////////////////
using namespace std;
int main()
{
	char key;            // player input data
	int  player_x = 40;  // player's x 
	int i = 0;           // player's score counter
	char n = i;
	// SECTION: initialization

	// set up the console text graphics system
	Init_Graphics();

	// clear the screen
	Clear_Screen();

	// SECTION: main event loop, this is where all the action  
	// takes place, the general loop is erase-move-draw

	while (game_running && i < 99)
	{
			// SECTION: erase all the objects or clear screen

			// nothing to erase in our case   

			// SECTION: get player input

			if (_kbhit())
			{
				// get keyboard data, and filter it
				key = toupper(_getch());

				// is player trying to exit, if so exit
				if (key == 'Q' || key == 27)
					game_running = 0;

				// is player moving left        
				if (key == 'A')
					player_x--;

				// is player moving right
				if (key == 'S')
					player_x++;

			} // end if   

			// SECTION: game logic and further processing

			// make sure player stays on screen 
			if (++player_x > MAX_X)
				player_x = MAX_X;

			if (--player_x < 0)
				player_x = 0;

			// SECTION: draw everything

			// draw next star at random position
			Set_Color(15, 0);
			Draw_String(rand() % 80, SCROLL_POS, ".\n");

			// draw player 
			Set_Color(rand() % 15, 0);
			Draw_String(player_x, 0, "<--*-->");
			Draw_String(0, 0, "");
			Draw_String(MAX_X, 1, "");
			cout << i;
			// SECTION: synchronize to a constant frame rate
			Sleep(100);

			i++;

		}

	// SECTION: shutdown and bail
	Clear_Screen();
	printf("\nG A M E  O V E R \n\n");
	return 0;
} // end main
