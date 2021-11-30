#include <iostream>
#include <string>
#include <chrono>
#include <thread>


using namespace std;
using namespace std::this_thread;
using namespace std::chrono;


// Holiday ASCII art for the game as global variables
string ROCK = "\n     __\n   _|==|_  \n    ('')___/\n>--(`^^')\n  (`^'^'`)\n  `======'  ldb";
string PAPER = "\n      .\n   __/ \\__\n   \\     /\n   /.'o'.\\\n    .o.'.\n   .'.'o'.\n  o'.o.'.o.\n .'.o.'.'.o.\n.o.'.o.'.o.'.\n   [_____]\n    \\___/    ldb\n";
string SCISSORS = "\n  .-""-.\n /,..___\\\n() {_____}\n  (/-@-@-\\)\n  {`-=^=-'}\n  {  `-'  } Max\n   {     }\n    `---'\n";


// function declarations 
void runGame();
int getComputerPlay();
void printPlay(int play);


int main(){
    // For random number used for the computer's play
    srand(time(0));

    // clear screen
    cout << "\033[2J\033[1;1H";

    // Prints welcome message
    cout << "Welcome to Holiday RPS!\n";

    int keepPlaying = 1;
    // loop to let the player choose to exit the game or not
    while(keepPlaying == 1){

        // runs the game function
        runGame();

        cout << "Would you like to play again? 1 - Yes, 2 - No\n";
        cin >> keepPlaying;

    }
    
    return 0;
}


void runGame(){
    // variables
    int     roundCounter = 0;
    int     player;
    int     computer;
    bool    win = false;

    // loop to let the player play three rounds before restarting
    while(roundCounter < 3){
        roundCounter++;

        // tells the player to make their play
        cout << "What's your play? Enter it's number to see if you win!\n#####  1  #####" << ROCK << "\n#####  2  #####" << PAPER << "\n#####  3  #####" << SCISSORS << "\n";

        // gets the number the player entered for their play
        cin >> player;

        // clear screen
        cout << "\033[2J\033[1;1H";
        // sets the computer's move to a random number between 1 and 3
        int maxOptions = 3;
        computer = rand()%maxOptions+1;

        // prints the plays the computer and player made
        cout << "\n";
        printPlay(player);
        cout << "\nVS";
        printPlay(computer);
        cout << "\n\n";

        // calculates the round's winner
        if(player == 1 && computer == 2){
            win = false;
        }
        else if(player == 2 && computer == 3){
            win = false;
        }
        else if(player == 3 && computer == 1){
            win = false;
        }
        else if(player == 1 && computer == 3){
            win = true;
        }
        else if(player == 2 && computer == 1){
            win = true;
        }
        else if(player == 3 && computer == 2){
            win = true;
        }
        
        // announces the results of the round
        if(player == computer){
            cout << "Draw!\n\n";
        }
        else {
            if(win == true){
                cout << "You Win!\n";
            }
            else {
                cout << "You Loose!\n\n";
            }
        }

        // pauses the program
        sleep_until(system_clock::now() + seconds(2));
        // clear screen
        cout << "\033[2J\033[1;1H";

    }

}

// prints the play made by computer or player
void printPlay(int play){
    if(play == 1){
        cout << ROCK;
    }
    else if(play == 2){
        cout << PAPER;
    }
    else if(play == 3){
        cout << SCISSORS;
    }
}