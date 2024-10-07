#include <iostream>
#include <windows.h>

using namespace std;

int gotoxy(int x , int y){
    COORD c ;
    c.X = x ;
    c.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return 0 ;
}

void CurrencyConvertor(){
    int choice ; 
    float dollarValue ;
    while(true){
        gotoxy(26,0);
        cout << "CURRENCY CONERTOR......" << endl ;
        gotoxy(20,4);
        cout << "1. Dollar To Euro (EUR)." ;
        gotoxy(20,6);
        cout << "2. Dollar To Pound Sterling (GBP)." ;
        gotoxy(20,8);
        cout << "3. Dollar To Austrzlian Dollar (AUD)." ;
        gotoxy(20,10);
        cout << "4. Dollar To Canadian Dollar (CAD)." ;
        gotoxy(20,12);
        cout << "5. Dollar To Swiss Franc (CHF)." ;
        gotoxy(20,14);
        cout << "6. Dollar To Indian Rupee (INR)." ;
        gotoxy(20,16);
        cout << "7. Dollar To Moroccan Dirhams (MAD)." ;
        gotoxy(20,18);
        cout << "8. Dollar To Dinar koweitien (KWD)." ;
        gotoxy(20,20);
        cout << "9. Dollar To Algerian Dinars (DZD)." ;
        gotoxy(24,23);
        cout << "Select Option.......... " ;
        cin >> choice ;
        gotoxy(20,25);
        cout << "Enter How much Dollars you have : " ;
        cin >> dollarValue ;
        switch(choice){
            case 1 :  
                gotoxy(9,27);
                cout << " ==) Euro (EUR) value of \033[1;37m" << dollarValue << "\033[1;32m dollar is : \033[1;34m" << dollarValue * 0.92 << "\033[1;32m EUR" ;
                break ;
            case 2 : 
                gotoxy(9,27);
                cout << " ==) Pound Sterling (GBP) value of \033[1;37m" << dollarValue << "\033[1;32m dollar is : \033[1;34m" << dollarValue * 0.79 << "\033[1;32m GBP" ;
                break ;
            case 3 : 
                gotoxy(9,27);
                cout << " ==) Austrzlian Dollar (AUD) value of \033[1;37m" << dollarValue << "\033[1;32m dollar is : \033[1;34m" << dollarValue * 1.54 << "\033[1;32m AUD" ;
                break ;
            case 4 : 
                gotoxy(9,27);
                cout << " ==) Canadian Dollar (CAD) value of \033[1;37m" << dollarValue << "\033[1;32m dollar is : \033[1;34m" << dollarValue * 1.38 << "\033[1;32m CAD" ;
                break ;
            case 5 : 
                gotoxy(9,27);
                cout << " ==) Swiss Franc (CHF) value of \033[1;37m" << dollarValue << "\033[1;32m dollar is : \033[1;34m" << dollarValue * 0.86 << "\033[1;32m CHF" ;
                break ;
            case 6 : 
                gotoxy(9,27);
                cout << " ==) Indian Rupee (INR) value of \033[1;37m" << dollarValue << "\033[1;32m dollar is : \033[1;34m" << dollarValue * 83.93 << "\033[1;32m INR" ;
                break ;
            case 7 : 
                gotoxy(9,27);
                cout << " ==) Moroccan Dirhams (MAD) value of \033[1;37m" << dollarValue << "\033[1;32m dollar is : \033[1;34m" << dollarValue * 9.84 << "\033[1;32m MAD" ;
                break ;
            case 8 : 
                gotoxy(9,27);
                cout << " ==) Dinar koweïtien (KWD) value of \033[1;37m" << dollarValue << "\033[1;32m dollar is : \033[1;34m" << dollarValue * 0.31 << "\033[1;32m KWD" ;
                break ;
            case 9 : 
                gotoxy(9,27);
                cout << " ==) Algerian Dinars (DZD) value of \033[1;37m" << dollarValue << "\033[1;32m dollar is : \033[1;34m" << dollarValue * 134.76 << "\033[1;32m DZD" ;
                break ;
            default : 
                gotoxy(28,27);
                cout << "\033[1;31mInvalid choice...!\033[0m" ;
                break ;
        }
        gotoxy(15,29);
        cout << "\033[1;32mIf you want to continue then enter 1 else 0.......... " ;
        int continueChoice ;
        cin >> continueChoice ;
        if(continueChoice == 1) {
            system("cls");
            CurrencyConvertor();
        }
        else gotoxy(35,33); cout << "\033[32mExiting Program.......\033[0m\n\n\n" ; exit(0);
    }
}
int main(){
    system("cls");
    system("color A");
    CurrencyConvertor();
    return 0;
 
}