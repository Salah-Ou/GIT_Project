#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
#include <time.h>
#include <conio.h>
#include <vector>

#define RESET "\033[0m "
#define WHITE "\033[37m"
#define RED   "\033[31m"
#define GREEN "\033[32m"
#define BLACK "\033[30m"

using namespace std;

class AgeCalculator { 
    public : 
        int current_date , current_month , current_year ;
        int birth_day , birth_month , birth_year ;
        int age_date , age_month , age_year ;


        void current_time(){
            time_t t = time(NULL);
            struct tm time = *localtime(&t);
            current_year = time.tm_year + 1900 ;
            current_month = time.tm_mon + 1 ;
            current_date = time.tm_mday ;
            cout << "\n\t\t" ;
            cout << "         The current time : " << (current_date < 10 ? "0" : "") 
            << current_date << "/" << (current_month < 10 ? "0" : "") 
            << current_month << "/" << current_year << "  ";
            set_reminder();
        }

        set_reminder(){
            system("cls");
            cout << "\n\t\t\t\t\t\t\t      " ;
            time_t now = time(0);
            tm endOftime = *localtime(&now);
            endOftime.tm_min = endOftime.tm_min ;
            endOftime.tm_sec = endOftime.tm_sec ;
            mktime(&endOftime);
            cout << asctime(&endOftime) << endl ;
        }

        birth_age_info(){
            cout << "\t\t\t\tWelcome To Age Calculator : \n" ;
            cout << "\t\t----------------------------------------------------------\n" ; 
            cout << "\n\t\t\t    Enter your birth day : " ;
            cin >> birth_day ;
            cout << "\t\t\t   Enter your birth month : " ;
            cin >> birth_month ;
            cout << "\t\t\t   Enter your birth year : " ;
            cin >> birth_year ;
        }
        
        void Calculate_Age(){
            age_date = current_date - birth_day ;
            age_month = current_month - birth_month ;
            age_year = current_year - birth_year ;
            cout << "\n\t\t\t==) Your Age is : " << age_year << " Years Old ," 
            << age_month << " Months ," << age_date << " Days." << endl ;
            cout << "\n\t\t----------------------------------------------------------\n" ;
        }

        void birthday(){
            Sleep(1000);
            set_reminder();
            cout << "\n\t\t" ; 
            current_time();
            cout << "\n\t\t\t\t\t        From : *****..." ;
            cout << "\n\t\t\t\t\t        To : Salah " << endl ; 
            char h = 2 ;
            cout << "\n\t\t       " ;
            for(int i = 0 ; i < 59 ; i++){
                cout << "*" ;
            }
            cout << "\n";
            Sleep(1000);
            system("color A");
            cout << "\t\t\t\t             i   i   i   i   i\n" ;
            Sleep(1000);
            system("color 7");
            cout << "\t\t\t\t             i   i   i   i   i\n" ;
            Sleep(1000);
            system("color A");
            cout << "\t\t\t\t          ___i___i___i___i___i___\n" ;
            Sleep(1000);
            system("color 7");
            cout << "\t\t\t\t         | ** FREE  PALESTINE ** |\n";
            Sleep(1000);
            system("color A");
            cout << "\t\t\t\t      ___| " << h << " * " << h << "  22 / 08  " << h << " * " << h << " |___\n";
            Sleep(1000);
            system("color 7");
            cout << "\t\t\t\t     | " << h << " *** " << h << " ** " << h << "  *  " << h << " ** " << h << " *** " << h << " |\n"; 
            Sleep(1000);
            system("color A");
            cout << "\t\t\t\t  ___| " << h << " *** " << h << " * " << h << " HAPPY " << h << " * " << h << " *** " << h << " |___\n";
            Sleep(1000);
            system("color 7");
            cout << "\t\t\t\t | " << h << " ** " << h << " * " << h << "     BIRTHDAY    " << h << " * " << h << " ** " << h << " |\n";
            Sleep(1000);
            system("color A");
            cout << "\t\t\t      ___| " << h << " *** " << h << " * " << h << "     SALAH     " << h << " * " << h << " *** " << h << " |___\n" ;
            Sleep(1000);
            system("color 7");
            cout << "\t\t\t     | " << h << " *** " << h << " ** " << h << " * " << h << "  B** *5 CS  " << h << " * " << h << " ** " << h << " *** " << h << " |\n";
            Sleep(1000);
            system("color A");
            cout << "\t\t\t  ___| ***   *   *** _____ TRAT99 ____ ***   *   *** |___\n" ;
            Sleep(1000);
            system("color 7");
            cout << "\t\t\t | " << h << "  ****  " << h << "  ***  " << h << " *** " << h << "  *  " << h << " *** " << h << "  ***  " << h << "  ****  " << h << " |\n";
            Sleep(1000);
            system("color A");
            cout << "\t\t\t |_______________________________________________________|\n"; 
        }

        void free_palestine(){
            set_reminder();
            cout << "\n\n" ;
            Sleep(1000);
            cout << RED << "\t\t\t\t\t|" << BLACK << "|||||||||||||||||||||||||||\n";
            Sleep(1000);
            cout << RED << "\t\t\t\t\t||" << BLACK << "||||||||||||||||||||||||||\n";
            Sleep(1000);
            cout << RED << "\t\t\t\t\t|||" << BLACK << "|||||||||||||||||||||||||\n";
            Sleep(1000);
            cout << RED << "\t\t\t\t\t||||" << WHITE << "||||||||||||||||||||||||\n";
            Sleep(1000);
            cout << RED << "\t\t\t\t\t|||||" << WHITE << "|||||||||||||||||||||||\n";
            Sleep(1000);
            cout << RED << "\t\t\t\t\t||||" << WHITE << "||||||||||||||||||||||||\n";
            Sleep(1000);
            cout << RED << "\t\t\t\t\t|||" << GREEN << "|||||||||||||||||||||||||\n";
            Sleep(1000);
            cout << RED << "\t\t\t\t\t||" << GREEN << "||||||||||||||||||||||||||\n";
            Sleep(1000);
            cout << RED << "\t\t\t\t\t|" << GREEN << "|||||||||||||||||||||||||||\n";
            cout << "\n" ;
            Sleep(1000);
            char sml = 3 ;
            cout << GREEN << "\t\t\t\t\t    FREE" << BLACK << " PAL" << WHITE << "EST" << RED << "INE " << GREEN << sml << " " << BLACK << sml << " " << WHITE << sml << " " RED << sml ; 

        }
};

int main(){
    signIn :
    AgeCalculator ac ;
    ac.set_reminder();
    system("color A");
    string username ;
    string password ;
    int username_size = 20 ;
    int password_size = 5 ;
    char ch ;
    
    do{
        username.clear();
        password.clear();
        cout << "\n\n\t\t\t\t       Sign in \n";
        cout << "\t\t---------------------------------------------------";
        // Username Input : 
        cout << "\n\t\t  Enter your Username , Phone or Email : ";
        while((ch = _getch()) != '\r'){
            if (ch == '\b'){
                if (!username.empty()){
                    username.pop_back();
                    cout << "\b \b";
                }
            }
            else if (username.size() < username_size){
                username.push_back(ch);
                cout << "*" ;
            }
        }
        // Password Input : 
        cout << "\n\t\t  Enter your Password : " ;
        while((ch = _getch()) != '\r'){
            if (ch == '\b'){
                if (!password.empty()){
                    password.pop_back();
                    cout << "\b \b";
                }
            }
            else if (password.size() < password_size){
                password.push_back(ch);
                cout << "*" ;
            }
        }
        if (username == "salahoublla" && password == "12345"){
            cout << "\n\t\t\t\t  " ;
            Sleep(400);
            cout << "\n\t\t\t\t   LOGIN";
            for(int j = 0 ; j < 10 ; j++){
                Sleep(500);
                cout << "." ;
            }
            cout << "\n\n\t\t\t\t    LOGIN SUCCESSEFUL!\n" ;
            cout << "\n\t\tAre you want to show your Username and Password ? (Y / N) : " ;
            char choice ;
            cin >> choice ;
            if (choice != 'N'){
                cout << "\n\t\t   Your Username is : " << username << endl ;
                cout << "\t\t   Your Password is : " << password << endl ;
                Sleep(2000);
            }
            else{
                cout << "\n\t\t\tNo ,I don't want to show My Information.\n";
                cout << "\n\t\t\tThank you for your understanding.\n";
                Sleep(4500);
            }
            system("cls");
            goto AgeCalculator ;
        }
        else{
            cout << "\n\t\t\t\t  " ;
            Sleep(400);
            cout << "\n\t\t\t\t   LOGIN";
            for(int j = 0 ; j < 10 ; j++){
                Sleep(500);
                cout << "." ;
            }
            cout << "\n\t\t\t*------------------------------------*" ;
            cout << "\n\t\t\t| LOGIN UNSUCCESSEFUL! Try Again!... |\n" ;
            cout << "\t\t\t|                ----                |" ;
            cout << "\n\t\t\t|               | \\/ |               |" ;
            cout << "\n\t\t\t|               | /\\ |               |" ;
            cout << "\n\t\t\t|                ----                |" ;
            cout << "\n\t\t\t*------------------------------------*" ;
            cout << "\n\n\t\t\t    Press (X) To Try Again..!!  " ;
            char choice ;
            cin >> choice ;
            if (choice == 'X'){
                Sleep(1500);
                system("cls");
                goto signIn ;
            }
        }
    }while(true);

    AgeCalculator :
    ac.current_time();
    ac.birth_age_info();
    ac.Calculate_Age();
    Sleep(1000);
    ac.birthday();
    cout << RED << "\n\t\t\t\t\t     WAIT WAIT......!!!!";
    Sleep(1000);
    ac.free_palestine();
    return 0 ;
}