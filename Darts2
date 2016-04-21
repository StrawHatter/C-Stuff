//
//  main.cpp
//  Darts2
//
//  Created by Cordelia on 20/04/2016.
//  Copyright © 2016 Cordelia. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */

using namespace std;

class Player
{
public:
    //attributes
    string name;
    int hit_miss, no_bulls, no_throws, avg_throws, avg_bulls;
};


int main()
{
    srand(time(NULL));
    
    int percent_joe;
    int percent_sid;
    int number_of_rounds = 1;
    int no_simulations = 1;
    char code = ' ';
    
    Player player_joe;
    Player player_sid;
    
    player_joe.name = "Joe";
    player_sid.name = "Sid";
    
    player_joe.no_bulls = 0;
    player_sid.no_bulls = 0;
    
    player_joe.no_throws = 0;
    player_sid.no_throws = 0;
    
    player_joe.avg_bulls = 0;
    player_sid.avg_bulls = 0;
    
    player_joe.avg_throws = 0;
    player_sid.avg_throws = 0;
    
    cout << "Who do you want to go first? Sid or Joe? Press 'S' for Sid, 'J' for Joe" << endl;
    cin >> code;
    cout << "What percent do you want Joe to have?" << endl;
    cin >> percent_joe;
    cout << "What percent do you want Sid to have?" << endl;
    cin >> percent_sid;
    cout << "How many tests do you want to do? Make it a positive integer please." << endl;
    cin >> no_simulations;
    
    do {
        do {
            // cout << iSecret << "Hit or Miss - 1 = hit" << endl; This line was purely for testing purposes
            
            if (code == 'J' or code == 'j'){
            for (int i = 0; i < 3; i++ ){
                player_joe.hit_miss = (rand() % 100 < percent_joe);
                if (player_joe.hit_miss == 1 && (player_joe.no_bulls < 10 && player_sid.no_bulls < 10)) {
                    player_joe.no_bulls++;
                    player_joe.no_throws++;
                    //cout << "No. Throws by Joe: " << player_joe.no_throws << endl;
                    //cout << "No. Bulls hit by Joe: " << player_joe.no_bulls << endl;

                }
                if (player_joe.hit_miss == 0 && (player_joe.no_bulls < 10 && player_sid.no_bulls < 10)) {
                    player_joe.no_throws++;
                }
            }
            
            for (int n = 0; n < 3; n++){
                player_sid.hit_miss = (rand() % 100 < percent_sid);
                if (player_sid.hit_miss == 1 && (player_joe.no_bulls < 10 && player_sid.no_bulls < 10)) {
                    player_sid.no_bulls++;
                    player_sid.no_throws++;
                }
                if (player_sid.hit_miss == 0 && (player_joe.no_bulls < 10 && player_sid.no_bulls < 10)){
                    player_sid.no_throws++;
                }
            }
            
                
            }
            
            if (code == 'S' || code == 's') {
                for (int n = 0; n < 3; n++){
                    player_sid.hit_miss = (rand() % 100 < percent_sid);
                    if (player_sid.hit_miss == 1 && (player_joe.no_bulls < 10 && player_sid.no_bulls < 10)) {
                        player_sid.no_bulls++;
                        player_sid.no_throws++;
                    }
                    if (player_sid.hit_miss == 0 && (player_joe.no_bulls < 10 && player_sid.no_bulls < 10)){
                        player_sid.no_throws++;
                    }
                    
                    for (int i = 0; i < 3; i++ ){
                        player_joe.hit_miss = (rand() % 100 < percent_joe);
                        if (player_joe.hit_miss == 1 && (player_joe.no_bulls < 10 && player_sid.no_bulls < 10)) {
                            player_joe.no_bulls++;
                            player_joe.no_throws++;
                            
                        }
                        if (player_joe.hit_miss == 0 && (player_joe.no_bulls < 10 && player_sid.no_bulls < 10)) {
                            player_joe.no_throws++;
                        }
                    }
                    
                
                }
            }
            number_of_rounds++;
        } while ((player_sid.no_bulls < 10) && (player_joe.no_bulls < 10));
        
        no_simulations++;
    } while (number_of_rounds < no_simulations);
    
    
    
    if (player_joe.no_bulls > player_sid.no_bulls){
        cout << "Winner is Joe" << endl;
    }
    else {
        cout << "Winner is Sid" << endl;
    }
    //cout << "No. Throws by Joe: " << player_joe.no_throws << endl;
    //cout << "No. Bulls by Joe: " << player_joe.no_bulls << endl;
    //cout << "No.Throws by Sid: " << player_sid.no_throws << endl;
    //cout << "No. Bulls by Sid: " << player_sid.no_bulls << endl;
    cout << "Number of Rounds: " << number_of_rounds << endl;
    
    return 0;
}


