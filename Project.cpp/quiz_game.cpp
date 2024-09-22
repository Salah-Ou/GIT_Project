#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void play_game(){
    int random = rand() % 251 ;
    cout << "\n\t\t  Random : " <<  random << endl ;
    int guess ;
    while(1){
        cout << "\n\t\t  Guess a number between 1 and 250 : ";
        cin >> guess;
        if(guess == random){
            cout << "\033[1;32m\n\t\t\t\t  YOU WIN!\033[1;32m\n";
            break ;
        }else if (guess < random){
            cout << "\033[1;31m\n\t\t\t\t  TOO LOW!\033[1;32m\n";
        }
        else{
            cout << "\033[1;33m\n\t\t\t\t  TOO HIGH!\033[1;32m\n" ;
        }
    }
}

int main(){
    system("cls");
    cout << "\033[1;32m" ;
    srand(time(0)); 
    int choice ;
    do{
        cout << "\n\t\t0. Quit." << endl << "\t\t1. Play Game.\n" ;
        cout << "\n\t\tEnter your choice : " ;  
        cin >> choice ;
        switch(choice){
            case 0 : cout << "\n\t\t\tThe Program Exiting...\n\n" ;
                break ;
            case 1 : play_game();
                break ;
        }
    }while(choice != 1);
    return 0; 
}