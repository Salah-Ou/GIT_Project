#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <vector>
#include <iomanip>

using namespace std;

int main();

int gotoxy(int x , int y){
    COORD c ;
    c.X = x ;
    c.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return 0 ;

}

void Time(){
    time_t now = time(NULL);
    tm *local = localtime(&now);
    gotoxy(50,0);
    cout << "\033[1;32mCurrent Time : \033[1;37m" << asctime(local) ;
    cout << "\033[0m" ;
}

class ATM {
    private :
        struct account {
            string name ;
            string pin ;
            string account_no ;
            float balance ;
            string phone_no ;
            string address ;
        };
        vector <account> accounts ;
         
    public : 

        void create_account();
        void login();
        void deposit();
        void withdraw();
        void check_balance();
        void savings();
};

void ATM::create_account(){
    system("cls");
    Time();
    account new_acc ;
    gotoxy(20,2);
    cout << "\033[1;4;32m Creating Account ATM \033[0m" ;
    gotoxy(15,4);
    cout << "\033[1;33mEnter your name           : \033[37m" ;
    cin.ignore();
    getline(cin,new_acc.name);
    gotoxy(15,6);
    cout << "\033[1;33mEnter your Account Number : \033[37m" ;
    char ch ;
    for(int i = 0 ; i < 10 ; i++){
        ch = _getch();
        if (ch == 13) break ;
        new_acc.account_no += ch ;
        cout << "*";
    }
    gotoxy(15,8);
    cout << "\033[1;33mEnter your PIN            : \033[37m" ;
    for(int i = 0 ; i < 10 ; i++){
        ch = _getch();
        if (ch == 13) break ;
        new_acc.pin += ch ;
        cout << "*";
    }
    gotoxy(15,10);
    cout << "\033[1;33mEnter your Phone Number   : \033[37m" ;
    cin >> new_acc.phone_no ;
    gotoxy(15,12);
    cout << "\033[1;33mEnter your Address        : \033[37m" ;
    cin.ignore();
    getline(cin,new_acc.address);
    gotoxy(15,14);
    cout << "\033[1;33mEnter your balance        : \033[1;32m" ;
    cin >> new_acc.balance ;
    gotoxy(16,16);
    cout << "\033[1;32mAccount Created Successfully!" ;
    accounts.push_back(new_acc);
    for(int i = 5 ; i >= 0 ; i--){
        cout << "\r" ;
        gotoxy(18,18);
        cout << "\033[1;33mLoading ... Wait " << i << " Seconds.\033[0m" ;
        Sleep(500);
        Beep(500,500);
    }
}

void ATM::login(){
    if (!accounts.empty()){
        system("cls");
        Time();
        Login :
        string pin , acc_no ;
        gotoxy(25,2);
        cout << "\033[1;4;32mLogin ATM \033[0m" ;
        gotoxy(15,4);
        char ch ;
        cout << "\033[1;33mEnter your account number : \033[37m" ;
        for(int i = 0 ; i < 10 ; i++){
            ch = _getch();
            if (ch == 13) break ;
            acc_no += ch ;
            cout << "*";
        }
        gotoxy(15,6);
        cout << "\033[1;33mEnter your PIN            : \033[37m" ;
        for(int i = 0 ; i < 10 ; i++){
            ch = _getch();
            if (ch == 13) break ;
            pin += ch ;
            cout << "*";
        }
        for(const auto& acc : accounts){
            if (acc_no == acc.account_no && pin == acc.pin){
                gotoxy(22,10);
                cout << "\033[1;32mLogin Successful!" ;
                gotoxy(24,12);
                cout << "\033[1;4;32mWelcome " << acc.name << "!\033[0m" ;
                for(int i = 5 ; i >= 0 ; i--){
                    cout << "\r" ;
                    gotoxy(17,14);
                    cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                    Sleep(500);
                    Beep(500,500);
                }
                Sleep(2000);
                main();
            }
            else {
                gotoxy(20,10);
                cout << "\033[1;31mLogin Failed!" ;
                for(int i = 5 ; i >= 0 ; i--){
                    cout << "\r" ;
                    gotoxy(17,12);
                    cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                    Sleep(500);
                    Beep(500,500);
                }
                system("cls");
                Sleep(1000);
                goto Login ;
            }
        }
    }
    else{
        gotoxy(20,5);
        cout << "\033[1;31mThey are no Accounts Available to Login !" ;
        gotoxy(15,10);
        cout << "\033[1;31mPlease Press any key to try again !! " ; 
        _getch();
        system("cls");
    }
}

void ATM::check_balance(){
    if (!accounts.empty()){
        Checking :
        system("cls");
        Time();
        string acc_no ;
        gotoxy(24,2);
        cout << "\033[1;4;32mCheck Balance ATM \033[0m" ;
        gotoxy(15,4);
        cout << "\033[1;33mEnter your account number : \033[37m" ;
        char ch ;
        for(int i = 0 ; i < 10 ; i++){
            ch = _getch();
            if (ch == 13) break ;
            acc_no += ch ;
            cout << "*";
        }
        for(const auto& acc : accounts){
            if (acc_no == acc.account_no){
                gotoxy(20,6);
                cout << "\033[1;32mYour Name          : \033[37m" << acc.name ;
                gotoxy(20,8);
                cout << "\033[1;32mYour Phone number : \033[37m" << acc.phone_no ;
                gotoxy(20,10);
                cout << fixed << setprecision(2) << "\033[1;32mCurrent Balance  : \033[32m" << acc.balance << " DH\033[0m" ;
                gotoxy(15,12);
                cout << "\033[1;4;32mThank You For Checking Your Account !\033[0m" ;
                for(int i = 5 ; i >= 0 ; i--){
                    cout << "\r" ;
                    gotoxy(17,14);
                    cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                    Sleep(500);
                    Beep(500,500);
                }
                cout << "\n\n\033[0m" ;
                Sleep(2000);
            }
            else {
                gotoxy(20,8);
                cout << "\033[1;31mInvalid Account Number !" ;
                for(int i = 5 ; i >= 0 ; i--){
                    cout << "\r" ;
                    gotoxy(17,10);
                    cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                    Sleep(500);
                    Beep(500,500);
                }
                gotoxy(13,10);
                cout << "\033[1;31mPlease Press any key to try again !! " ; 
                _getch();
                goto Checking ;
            }
        }
    }
    else{
        system("cls");
        gotoxy(20,5);
        cout << "\033[1;31mThey are No Accounts Available For Checking !" ;
        gotoxy(15,10);
        cout << "\033[1;31mPlease Press any key to try again !! " ; 
        _getch();
    }
}

void ATM::deposit(){
    if (!accounts.empty()){
        Deposit :
        system("cls");
        Time();
        gotoxy(24,2);
        cout << "\033[1;4;32mDeposit Money ATM \033[0m" ;
        float amount ;
        gotoxy(16,4);
        cout << "\033[1;33mEnter your account number : \033[37m" ;
        char ch ;
        string acc_no ;
        for(int i = 0 ; i < 10 ; i++){
            ch = _getch();
            if (ch == 13) break ;
            acc_no += ch ;
            cout << "*";
        }
        for(auto& acc : accounts){
            if (acc_no == acc.account_no){
                gotoxy(11,6);
                cout << "\033[1;34mEnter The amount you want to Desposit : \033[37m" ;
                cin >> amount ;
                if (amount > 0 && amount < acc.balance){
                    acc.balance += amount ;
                    gotoxy(21,8);
                    cout << "\033[1;32mDesposit Successfully !" ;
                    gotoxy(16,10);
                    cout << fixed << setprecision(2) << "\033[1;34mYour Current Balance : \033[37m" << acc.balance << " DH\033[0m" ;
                    gotoxy(18,12);
                    cout << "\033[1;4;32mThank You for your deposit !\033[0m" ;
                    for(int i = 5 ; i >= 0 ; i--){
                        cout << "\r" ;
                        gotoxy(17,15);
                        cout << "\033[1;33mLoading ... Wait " << i << " Seconds.\033[0m" ;
                        Sleep(500);
                        Beep(500,500);
                    }
                    cout << "\n\n\033[0m" ;
                    Sleep(2000);
                }
                else{
                    gotoxy(23,8);
                    cout << "\033[1;31mInvalid Amount!" ;
                    for(int i = 5 ; i >= 0 ; i--){
                        cout << "\r" ;
                        gotoxy(17,10);
                        cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                        Sleep(500);
                        Beep(500,500);
                    }
                    gotoxy(15,10);
                    cout << "\033[1;31mPlease Press any key to try again !! " ; 
                    _getch();
                    goto Deposit ;
                }
            }
            else {
                gotoxy(21,8);
                cout << "\033[1;31mInvalid Account Number !" ;
                for(int i = 5 ; i >= 0 ; i--){
                    cout << "\r" ;
                    gotoxy(17,10);
                    cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                    Sleep(500);
                    Beep(500,500);
                }
                gotoxy(13,10);
                cout << "\033[1;31mPlease Press any key to try again !! " ; 
                _getch();
                goto Deposit ;
            }
        }   
    }
    else{
        system("cls");
        gotoxy(20,5);
        cout << "\033[1;31mThey are No Accounts Available to Desposit !" ;
        gotoxy(15,10);
        cout << "\033[1;31mPlease Press any key to try again !! " ; 
        _getch();
    }
}

void ATM::withdraw(){
    if (!accounts.empty()){
        withdraw :
        system("cls");
        Time();
        float amount ;
        gotoxy(24,2);
        cout << "\033[1;4;32mWithdraw Money ATM \033[0m" ;
        gotoxy(16,4);
        cout << "\033[1;33mEnter your account number : \033[37m" ;
        char ch ;
        string acc_no ;
        for(int i = 0 ; i < 10 ; i++){
            ch = _getch();
            if (ch == 13) break ;
            acc_no += ch ;
            cout << "*";
        }
        for(auto& acc : accounts){
            if (acc_no == acc.account_no){
                gotoxy(11,6);
                cout << "\033[1;34mEnter The amount you want to Withdraw : \033[37m" ;
                cin >> amount ; 
                if (amount > 0 && amount < acc.balance){
                    acc.balance -= amount ;
                    gotoxy(21,8);
                    cout << "\033[1;32mWithdraw Successfully !" ;
                    gotoxy(16,10);
                    cout << fixed << setprecision(2) << "\033[1;34mYour Current Balance : \033[37m" << acc.balance << " DH\033[0m" ;
                    gotoxy(17,12);
                    cout << "\033[1;4;32mThank You for your withdraw !\033[0m" ;
                    for(int i = 5 ; i >= 0 ; i--){
                        cout << "\r" ;
                        gotoxy(17,15);
                        cout << "\033[1;33mLoading ... Wait " << i << " Seconds.\033[0m" ;
                        Sleep(500);
                        Beep(500,500);
                    }
                    cout << "\n\n\033[0m" ;
                    Sleep(2000);
                }
                else{
                    gotoxy(23,10);
                    cout << "\033[1;31mInvalid Amount!" ;
                    for(int i = 5 ; i >= 0 ; i--){
                        cout << "\r" ;
                        gotoxy(17,12);
                        cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                        Sleep(500);
                        Beep(500,500);
                    }
                    gotoxy(15,12);
                    cout << "\033[1;31mPlease Press any key to try again !! " ; 
                    _getch();
                    goto withdraw ;
                }
            }
            else {
                gotoxy(21,8);
                cout << "\033[1;31mInvalid Account Number !" ;
                for(int i = 5 ; i >= 0 ; i--){
                    cout << "\r" ;
                    gotoxy(17,10);
                    cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                    Sleep(500);
                    Beep(500,500);
                }
                gotoxy(13,10);
                cout << "\033[1;31mPlease Press any key to try again !! " ; 
                _getch();
                goto withdraw ;
            }
        }
    }
    else{
        gotoxy(20,5);
        cout << "\033[1;31mThey are No Accounts Available to Withdraw !" ;
        gotoxy(15,9);
        cout << "\033[1;31mPlease Press any key to try again !! " ; 
        _getch();
    }
}

void ATM::savings(){
    if (!accounts.empty()){
        save : 
        system("cls");
        Time();
        float amount ;
        gotoxy(25,2);
        cout << "\033[1;4;32mSavings Account \033[0m" ;
        gotoxy(16,4);
        cout << "\033[1;33mEnter your account number : \033[37m" ;
        char ch ;
        string acc_no ;
        for(int i = 0 ; i < 10 ; i++){
            ch = _getch();
            if (ch == 13) break ;
            acc_no += ch ;
            cout << "*" ;
        }
        for(auto& acc : accounts){
            if (acc_no == acc.account_no){
                gotoxy(16,6);
                cout << "\033[1;34mEnter the amount you want to save : \033[37m" ;
                cin >> amount ; 
                if (amount > 0 && amount < acc.balance){
                    acc.balance += amount ;
                    gotoxy(24,8);
                    cout << "\033[1;32mSave Successfully!" ;
                    gotoxy(16,10);
                    cout << fixed << setprecision(2) << "\033[1;34mYour Current Balance : \033[37m" << acc.balance << " DH\033[0m" ;
                    gotoxy(18,12);
                    cout << "\033[1;4;32mThank You for your savings !\033[0m" ;
                    for(int i = 5 ; i >= 0 ; i--){
                        cout << "\r" ;
                        gotoxy(19,14);
                        cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                        Sleep(500);
                        Beep(500,500);
                    }
                    cout << "\n\n\033[0m" ;
                    Sleep(2000);
                }
                else {
                    gotoxy(25,8);
                    cout << "\033[1;31mInvalid Amount!" ;
                    for(int i = 5 ; i >= 0 ; i--){
                        cout << "\r" ;
                        gotoxy(19,10);
                        cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                        Sleep(500);
                        Beep(500,500);
                    }
                    gotoxy(14,10);
                    cout << "\033[1;31mPlease Press any key to try again !! " ; 
                    _getch();
                    goto save ;
                }
            }
            else {
                gotoxy(23,10);
                cout << "\033[1;31mInvalid Account Number !" ;
                for(int i = 5 ; i >= 0 ; i--){
                    cout << "\r" ;
                    gotoxy(19,12);
                    cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                    Sleep(500);
                    Beep(500,500);
                }
                gotoxy(13,12);
                cout << "\033[1;31mPlease Press any key to try again !! " ; 
                _getch();
                goto save ;
            }
        }
    }
    else{
        gotoxy(20,5);
        cout << "\033[1;31mThey are no accounts available to savings !" ;
        gotoxy(15,9);
        cout << "\033[1;31mPlease Press any key to try again !! " ; 
        _getch();
    }
}

int main(){
    Menu :
    system("cls");
    ATM atm ;
    int option ;
    while(true){
        system("cls");
        Time();
        gotoxy(10,2);
        cout << "\033[1;33m** \033[1;4;33mWelcome To The ATM Project\033[0m\033[1;33m **\033[0m" ;
        gotoxy(13,4);
        cout << "\033[1;31m* \033[30m1. Create A New Account." ;
        gotoxy(13,6);
        cout << "\033[1;31m* \033[30m2. Login." ;
        gotoxy(13,8);
        cout << "\033[1;31m* \033[30m3. Check in your Account." ;
        gotoxy(13,10);
        cout << "\033[1;31m* \033[30m4. Desposit." ;
        gotoxy(13,12);
        cout << "\033[1;31m* \033[30m5. Withdraw." ;
        gotoxy(13,14);
        cout << "\033[1;31m* \033[30m6. Savings." ;
        gotoxy(13,16);
        cout << "\033[1;31m* \033[30m0. Exit." ;
        gotoxy(10,18);
        cout << "\033[1;4;33mSelect Option : \033[0m" ;
        cin >> option ;
        switch(option){
            case 1 : atm.create_account(); break ;
            case 2 : atm.login(); break ; 
            case 3 : atm.check_balance(); break ;
            case 4 : atm.deposit(); break ;
            case 5 : atm.withdraw(); break ;
            case 6 : atm.savings(); break ;
            case 0 : gotoxy(14,20) ; cout << "\033[1;32mExiting Program... !\n\n\033[0m" ; exit(0) ; break ;
            default : gotoxy(13,20); cout << "\033[1;31mInvalid option !!\n\n\033[0m" ;
                cout << "Please Press any key to try again !! " ; 
                _getch(); goto Menu ; break ;
        }
    }
}