#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define RESET "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"

using namespace std;

int gotoxy(int x , int y) {
    COORD c ;
    c.X = x ;
    c.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c) ;
    return 0 ;
}

void Time(){
    time_t now = time(0);
    tm *local = localtime(&now);
    cout << "\033[1;32m" ;
    cout << ((local -> tm_mday < 10) ? "0" : "") << local -> tm_mday << "/" << ((local -> tm_mon + 1) < 10 ? "0" : "") << local -> tm_mon + 1 << "/" 
    << local -> tm_year + 1900 << " | " << ((local -> tm_hour < 10) ? "0" : "") << local -> tm_hour << ":" << ((local -> tm_min < 10) ? "0" : "")
    << local -> tm_min << ":" << ((local -> tm_sec < 10) ? "0" : "") << local -> tm_sec << RESET ;
}

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}} ;
int row, column ;
char token = 'x';
bool tie = false;
string name1, name2;

void drawBoard() {
    system("cls");
    gotoxy(34,0);
    Time();
    gotoxy(30, 2);
    cout << "\033[1;37m====== Tic Tac Toe Game ======\n" << RESET ;
    gotoxy(36, 4);
    cout << GREEN << name1 << " : (x) GREEN ";
    gotoxy(36, 6);
    cout << RED << name2 << " : (o) RED " << "\n" << RESET ;
    cout << "\033[1;37m\n\t\t\t\t   ___________________\n";
    cout << "\033[1;37m\t\t\t\t   |     |     |     |\n";
    for (int i = 0 ; i < 3 ; i++) {
        cout << "\033[1;37m\t\t\t\t   |  " ;
        for (int j = 0 ; j < 3 ; j++) {
            if (space[i][j] == 'x') {
                cout << GREEN << space[i][j] << RESET ;
            } else if (space[i][j] == 'o') {
                cout << RED << space[i][j] << RESET ;
            } else {
                cout << space[i][j] ;
            }
            cout << "  |  " ;
        }
        cout << "\033[1;37m\n\t\t\t\t   |_____|_____|_____|\n" ;
        if (i < 2) {
            cout << "\033[1;37m\t\t\t\t   |     |     |     |\n" ;
        }
    }
    cout << "\n" ;
}

void Digit(){
    int digit ;
    gotoxy(36, 19);
    if (token == 'o'){
        cout << RED << "\n\t\t\t\t     ==) " << name2 << RESET ;
        cout << "\033[1;31m\n\t\t\t\t---------------------\n" << "\t\t\t\t Enter your digit : ";
        cin >> digit;
        cout << RESET ;
    }
    else{
        cout << GREEN << "\n\t\t\t\t    ==) " << name1 << RESET ;
        cout << "\033[1;32m\n\t\t\t\t---------------------\n" << "\t\t\t\t Enter your digit : ";
        cin >> digit;
        cout << RESET ;
    }

    switch (digit) {
        case 1 : row = 0 ; column = 0 ; break ;
        case 2 : row = 0 ; column = 1 ; break ;
        case 3 : row = 0 ; column = 2 ; break ;
        case 4 : row = 1 ; column = 0 ; break ;
        case 5 : row = 1 ; column = 1 ; break ;
        case 6 : row = 1 ; column = 2 ; break ;
        case 7 : row = 2 ; column = 0 ; break ;
        case 8 : row = 2 ; column = 1 ; break ;
        case 9 : row = 2 ; column = 2 ; break ;
        default:
            cout << "\n\t\t\t\t Invalid Choice...  !!\n";
            takeInput();
            break;
    }

    if (space[row][column] != 'x' && space[row][column] != 'o') {
        space[row][column] = token;
        token = (token == 'x') ? 'o' : 'x';
    } else {
        cout << "\n\t\t\t    \033[1;31m Position Already Occupied !\033[0m\n";
        takeInput();
    }
    }

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][1] == space[i][2])
            return true;
        if (space[0][i] == space[1][i] && space[1][i] == space[2][i])
            return true;
    }
    // Check diagonals
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2])
        return true ;
    if (space[0][2] == space[1][1] && space[1][1] == space[2][0])
        return true ;

    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if (space[i][j]!= 'x' && space[i][j]!= 'o'){
                return false ;
            }
        }
    }
    tie = true ;
    return false ;
}

void playGame() {
    while (true) {
        drawBoard();
        takeInput();
        if (checkWin()) {
            drawBoard();
            if (token == 'o') {
                cout << "\n\t\t\t\t\t" << GREEN << name1 << " WON !" << RESET;
            } else {
                cout << "\n\t\t\t\t\t" << RED << name2 << " WON !" << RESET;
            }
        if (checkWin()){
            drawBroad();
            cout << "\n\t\t\t\t\t" << name1 << " Won!!!\n" ;
            break ;
        }
        }
    }
    cout << "\n\t\t\t\t Do You Want To Play Again (Y/N) : " ;
    cin >> play ;
    if (tolower(play) == 'y'){
        system("cls");
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                space[i][j] = '1' + i*3 + j ;
            }
        }
        token = 'x' ;
        tie = false ;
        main();
}

    return 0 ;
}#include <iostream>
#include <windows.h>
#include <conio.h>

#define RESET "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"

using namespace std;

char space[3][3] = {{'1','2','3'} , {'4','5','6'} , {'7','8','9'}};
int row , column ;
char token = 'x' ;
bool tie ;
string name1 , name2 ;

void drawBroad(){
    system("cls");
    gotoxy(50,0);
    Time();
    char play ;
    cout << RESET;
    gotoxy(30, 2);
    cout << "\033[1;37m================ Welcome To Tic Tac Toe Game ================\n";
    gotoxy(40, 4);
    cout << "Enter The Name Of Player 1 (x) : ";
    cin >> name1;
    gotoxy(40, 6);
    cout << "Enter The Name Of Player 2 (o) : ";
    cin >> name2;
    cout << "\033[0m" ;

    do {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                space[i][j] = '1' + i * 3 + j;
            }
        }

bool checkWin(){
    for(int i = 0 ; i < 3 ; i++){
        if (space[i][0] == space[i][1] && space[i][1] == space[i][2] || 
        space[0][i] == space[1][i] && space[1][i] == space[2][i]){
            return true ;
        }
    }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] ||
    space[0][2] == space[1][1] && space[1][1] == space[2][0]){
        return true ;
    }
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if (space[i][j]!= 'x' && space[i][j]!= 'o'){
                return false ;
            }
        }
    }
    tie = true ;
    return false ;
}

        cout << "\033[1;37m\n\n\t\t\t   Do You Want To Play Again (Y/N) : " ;
        cin >> play ;
        cout << RESET ; 
    } while (tolower(play) == 'y');

    cout << "\n\n\t\t\t\t\033[1;32mThank you for playing....\033[0m\n\n";

    return 0;
}
