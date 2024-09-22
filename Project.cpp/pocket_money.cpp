#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

int gotoxy(int x , int y){
    COORD c ;
    c.X = x ;
    c.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return 0 ;
}

void Time(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    gotoxy(50,0);;
    cout << "Current date and time : " << asctime(ltm) << "\033[32m";
}

struct Transactions {
    float amount ;
    string description ;
};

class PocketMoney{
    private : 
        vector <Transactions> transaction ;
    public : 
        float budget , expense , saving ;
        PocketMoney(){
            budget = 0.0 ;
            expense = 0.0 ;
            saving = 0.0 ;
        }

        void initialize(); 
        void spend_money();
        void save_money();
        void display_details();
        void show_transac();
};

void PocketMoney::initialize(){
    system("cls");
    Time();
    gotoxy(20,2);
    cout << "Enter your budget for the month : " ;
    cin >> budget ;
}

void PocketMoney::spend_money(){
    system("cls");
    Time();
    float amount ;
    gotoxy(23,4);
    cout << "Enter amount spend : " ;
    cin >> amount ;
    if (amount <= budget - expense){
        gotoxy(23,6);
        cout << "Expense Recorded." << endl ;
        Transactions t ;
        string description ;
        gotoxy(23,8);
        cout << "Enter a brief description for this expenses : " ;
        cin.ignore();
        getline(cin,description);
        t.amount = amount ;
        t.description = description ;
        expense += amount ;
        transaction.push_back(t);
    }
}

void PocketMoney::save_money(){
    float amount ;
    system("cls");
    Time();
    gotoxy(23,5);
    cout << "Enter amount save : " ;
    cin >> amount ;
    string description ;
    Transactions t ;
    gotoxy(18,7);
    cout << "Enter a brief description for this savings : " ;
    cin.ignore();
    getline(cin,description);
    t.amount = amount ;
    t.description = description ;
    saving += amount ;
    transaction.push_back(t);
}

void PocketMoney::display_details(){
    system("cls");
    Time();
    gotoxy(25,2);
    cout << "\033[1;34mPocket Details : \033[32m" << endl ;
    cout << fixed << setprecision(1);
    gotoxy(20,4);
    cout << "---------------------------\n" ;
    gotoxy(22,6);
    cout << "Budget : " << budget << endl ;
    gotoxy(22,8);
    cout << "Expense : " << expense << endl ;
    gotoxy(22,10);
    cout << "Saving : " << saving << endl ;
    gotoxy(20,12);
    cout << "---------------------------\n" ;
    gotoxy(25,16);
    cout << "Press any key to continue..." << endl ;
    getch();
}

void PocketMoney::show_transac(){
    system("cls");
    Time();
    gotoxy(25,2);
    cout << "\033[1;34mTransactions History : \033[32m\n" ;
    for(const auto& t : transaction){
        gotoxy(15,4);
        cout << "--------------------------------------------" << endl ;
        gotoxy(18,6);
        cout << "Description : " << t.description << "  ,  " ;
        cout << "Amount : " << t.amount << " DH" << endl ;
    }
    gotoxy(15,8);
    cout << "--------------------------------------------" << endl ;
    gotoxy(23,10);
    cout << "Press any key to continue... " ;
    getch();
}

int main(){
    system("cls");
    system("color A");
    int choice ;
    PocketMoney pm ;
    pm.initialize();
    do{
        system("cls");
        Time();
        gotoxy(25,2);
        cout << "---------------------------------" << endl ;
        gotoxy(30,4);
        cout << "\033[1;34mPocket Money Management : \033[0m\033[32m\n" ;
        gotoxy(27,6);
        cout << "1. Spend Money." << endl ;
        gotoxy(27,8);
        cout << "2. Save Money." << endl ;
        gotoxy(27,10);
        cout << "3. Dispaly Details." << endl ;
        gotoxy(27,12);
        cout << "4. Show Transactions." << endl ;
        gotoxy(27,14);
        cout << "5. Exit." << endl ;
        gotoxy(25,16);
        cout << "---------------------------------" << endl ;
        gotoxy(28,18);
        cout << "Enter your choice : " ;
        cin >> choice ;
        switch(choice){
            case 1 : pm.spend_money(); break ;
            case 2 : pm.save_money(); break ;
            case 3 : pm.display_details(); break ;
            case 4 : pm.show_transac(); break ;
            case 5 : gotoxy(30,21); cout << "\033[32mExiting Program...... \n\n\033[0m" ; exit(0); break ;
            default : gotoxy(30,20); cout << "\033[1;31mInvalid choice.\n\n\033[0m" ; break ;
        }
    }while(choice != 5);
}