//
//  DartCoursework.cpp
//  Darts2
//
//  Created by Cordelia on 21/04/2016.
//  Copyright © 2016 Cordelia. All rights reserved.
//
//#include "DartCoursework.hpp"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>


using namespace std;

const int N = 1;

//enum state { fast, slow, focus, out, win };
//extern const int N;

class Darts_501{
public:
    
    int percent;
    int score;
    int darts;
    
    int bull();
    int throw_treble(int d);
    int throw_double(int d);
    int throw_single(int d);
    void play_501();
};


int Darts_501:: bull() {
    
    //  Throw for the bull with accuracy p%  (20<p<85)
    
    int r = rand() % 100;
    
    if (r<(percent - 20))
        return 50;
    else if (r<85)
        return 25;
    else
        return 1 + rand() % 20;
}

int Darts_501:: throw_treble(int d) {
    
    //  return result of throwing for treble d with accuracy p%  (o<90)
    
    // Board neighbours ignoring slot zero
    int bd[2][21] = { { 0, 20, 15, 17, 18, 12, 13, 19, 16, 14, 6, 8, 9, 4, 11, 10, 7, 2, 1, 3, 5 },
        { 0, 18, 17, 19, 13, 20, 10, 16, 11, 12, 15, 14, 5, 6, 9, 2, 8, 3, 4, 7, 1 } };
    
    int r = rand() % 100;
    
    if (r < percent){
        return 3 * d;
    }
    else if (r < 90){
        return d;
    }
    else if (r < 93){
        return 3 * bd[0][d];
    }
    else if (r < 96){
        return 3 * bd[1][d];
    }
    else if (r < 98){
        return bd[0][d];
    }
    else{
        return bd[1][d];
    }
}


int Darts_501::throw_double(int d) {
    
    //  return result of throwing for double d with accuracy 80%
    
    // Board neighbours ignoring slot zero
    int bd[2][21]={{0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
        {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1}};
    
    int r = rand()%100;
    
    if(r<80) {
        return 2*d;
    }
    
    else if(r<85) {
        return 0;
    }
    
    else if(r<90) {
    return d;
    }
    
    else if (r<93) {
        return 2*bd[0][d];
    }
    
    else if(r<96) {
        return 2*bd[1][d];
    }
    
    else if (r<98) {
        return bd[0][d];
    }
    
    else {
        return bd[1][d];
    }
}

int Darts_501:: throw_single(int d) {
    
    //  return result of throwing for single d with accuracy 88% (or 80% for the outer)
    
    // Board neighbours ignoring slot zero
    int bd[2][21] = { { 0, 20, 15, 17, 18, 12, 13, 19, 16, 14, 6, 8, 9, 4, 11, 10, 7, 2, 1, 3, 5 },
        { 0, 18, 17, 19, 13, 20, 10, 16, 11, 12, 15, 14, 5, 6, 9, 2, 8, 3, 4, 7, 1 } };
    int r = rand() % 100;
    
    if (d == 25){		// outer  80%
        if (r < 80)
            return 25;
        else if (r < 90)
            return 50;
        else
            return 1 + rand() % 20;
    }
    else{			// 1 to 20 single
        if (r < 88){
            return d;
        }
        else if (r < 92){
            return bd[0][d];
        }
        else if (r < 96){
            return bd[1][d];
        }
        else if (r < 98){
            return 3 * d;
        }
        else{
            return 2 * d;
        }
    }
}

void Darts_501:: play_501() {
    darts = 0;
    int temp = 0;
    
    do{
        
        // determine state
        if (score > 169)
        {
            score = score - throw_treble(20);
        }
        else if (score == 40)
        {
            temp = throw_double(20);
            if (((score - temp) <= 1) && ((score - temp) != 0))
            {
                score -= 0;
            }
            else if ((score - temp) == 0)
            {
                score -= temp;
            }
        }
        else if (score > 32)
        {
            temp = throw_double(16);
            if ((score - temp) > 1)
            {
                score -= temp;
            }
            else if (((score - temp) <= 1) && ((score - temp) != 0))
            {
                score -= 0;
            }
        }
        
        if (score < 32)
        {
            
            if (score % 2 == 0)
            {
                temp = throw_double(score / 2);
            }
            else if (score % 2 == 1)
            {
                temp = throw_single(score / 2 + 0.5);
            }
            else if (((score - temp) <= 1) && ((score - temp) != 0))
            {
                score -= 0;
            }
            score -= temp;
        }
        
        darts++;
        
    } while (darts < 3);// end while
}


int main(){
    srand (time(NULL));
    
    Darts_501 joe;
    Darts_501 sid;
    
    joe.percent = 70;
    sid.percent = 72;
    
    int joe_wins;
    int sid_wins;
    int joe_games;
    int sid_games;
    
    int wins76 = 0;
    int wins67 = 0;
    int wins57 = 0;
    int wins47 = 0;
    int wins37 = 0;
    int wins27 = 0;
    int wins17 = 0;
    
    for (int i = 1; i < N; i++)
    {			// plays 10000 games
        cout << 1 << endl;
        joe_wins = 0;
        sid_wins = 0;
        joe_games = 0;
        sid_games = 0;
        joe.score = 501;
        sid.score = 501;
        do{		// play matches of 13 sets
            do{ //play 5 games
                joe.score = 501;
                sid.score = 501;
                do
                {	// play single game
                    joe.play_501();
                    sid.play_501();
                    cout << i << joe_wins << sid_wins << "	" << joe_games  << " " << sid_games << "	" << joe.score << sid.score << endl;
                } while ((joe.score > 0) || (sid.score > 0));
                cout << "joe.score " << joe.score << endl;
                cout << "sid.score " <<  sid.score << endl;
                if (joe.score == 0)
                {
                    joe_games++;
                }
                else if (sid.score == 0)
                {
                    sid_games++;
                }
            } while ((joe_games < 3) && (sid_games < 3));
            
            if (joe_games == 3)
            {
                joe_wins++;
            }
            else if (sid_games == 3)
            {
                sid_wins++;
            }
        } while ((joe_wins < 7) && (sid_wins < 7));
        // counts scores relative to one another
        if ((joe_wins == 7) && (sid_wins == 6))
        {
            wins76++;
        }
        else if ((joe_wins == 6) && (sid_wins == 7))
        {
            wins67++;
        }
        else if ((joe_wins == 5) && (sid_wins == 7))
        {
            wins57++;
        }
        else if ((joe_wins == 4) && (sid_wins == 7))
        {
            wins47++;
        }
        else if ((joe_wins == 3) && (sid_wins == 7))
        {
            wins37++;
        }
        else if ((joe_wins == 2) && (sid_wins == 7))
        {
            wins27++;
        }
        else if ((joe_wins == 1) && (sid_wins == 7))
        {
            wins17++;
        }
    }
}
