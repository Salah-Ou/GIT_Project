#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int gotoxy(int x , int y){
    COORD c ;
    c.X = x ;
    c.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return 0 ;
}

void Time(){
    time_t now = time(NULL);
    tm* local = localtime(&now);
    gotoxy(50,0);
    cout << "\033[1;4;32mThe Current Time :\033[0m \033[1;34m" <<asctime(local) << "\033[0m" ; 
}

int leapyear(int year){
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int days_in_month(int year , int month){
    if (month == 2){
        if (leapyear(year)){
            return 29 ;
        }
        else{
            return 28 ;
        }
    }
    if (month == 4 || month == 6 || month == 7 || month == 9 || month == 11){
        return 30 ;
    }
    else{
        return 31 ;
    }
}

int main(){
    system("cls");
    system("color A");
    Time();
    int year , month ;
    gotoxy(20,2);
    cout << "\033[1;3;34mWelcome To The Calender Project\033[0m" ;
    gotoxy(25,4);
    cout << "\033[1;4;33mEnter a year :\033[0m \033[1;37m" ; 
    cin >> year ;
    gotoxy(25,6);
    cout << "\033[1;4;33mEnter month (1 - 12) :\033[0m \033[1;37m" ; 
    cin >> month ;
    int days = days_in_month(year,month);
    gotoxy(15,8);
    cout << "\033[1;33m=============================================\n" ;
    gotoxy(24,10);
    cout << "\033[1;33m** \033[1;4;34mCalendar For\033[0m \033[1;37m" << (month < 10 ? "0" : "") << month << " / " << year << "\033[0m\033[1;33m **\033[0m" ;
    gotoxy(15,12);
    cout << "\033[1;33m=============================================\n" ;
    gotoxy(21,14);
    cout << "\033[1;3;33mMon  Tue  Wed  Thu  Fri  Sat  Sun\n" ;
    tm time = {} ;
    time.tm_year = year - 1900 ;
    time.tm_mon = month - 1 ;
    time.tm_mday = 0 ;
    mktime(&time);
    int first_day = time.tm_wday ;
    gotoxy(21,16);
    for(int i = 0 ; i < first_day ; i++){
        cout << "     " ;
    }
    for(int day = 1 ; day <= days ; day++){
        cout << "\033[37m" << (day < 10 ? "0" : "") << day << "   " ;
        if ((day + first_day) % 7 == 0 || day == days){
            cout << "\n\n\t\t     " ;
        } 
    }
    cout << "\033[0m" ;
    gotoxy(15,24);
    cout << "\033[1;33m=============================================\n" ;
    cout << "\n\n\033[0m" ;
    return 0 ;
}