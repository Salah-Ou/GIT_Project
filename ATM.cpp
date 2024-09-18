#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

using namespace std;

class ATM {
    private : 
        struct account {
            string name ;
            int pin ;
            float balance ;
            int account_no ;
            string phone_no ;
        };
        vector <account> accounts ;
    public : 

        void create_account(){
            account new_account ;
            cout << "\n\t Creating Account ATM " ;
            cout << "\n-------------------------------------\n" ;
            cout << "Enter Your Name : " ;
            cin >> new_account.name ;
            cout << "Enter Your Phone Number : " ;
            cin >> new_account.phone_no ;
            cout << "Enter Your Account Number : " ;
            cin >> new_account.account_no ;
            cout << "Enter Your Account Pin : " ;
            cin >> new_account.pin ;
            cout << "Enter Your Account Starting Balance : " ;
            cin >> new_account.balance ;
            accounts.push_back(new_account);
            cout << "\n-------------------------------------\n" ;
            cout << "   Account created Successufully!!!\n" ;
        }

        void Login(){
            Login : 
            int acc_no ;
            int pin ;
            cout << "\n     Welcome To The Mini ATM : \n" ;
            cout << "\t       Login    \n" ;
            cout << "-----------------------------------\n" ;
            cout << "\n Enter Your Account Number : " ;
            cin >> acc_no ;
            cout << " Enter Your Account Pin : " ;
            cin >> pin ;
            cout << "\n-----------------------------------\n" ;
            for(int i = 0 ; i < accounts.size() ; i++){
                if (acc_no == accounts[i].account_no && pin == accounts[i].pin){
                    cout << "\n\t     " ;
                    for(int j = 0 ; j < 10 ; j++){
                        Sleep(500);
                        cout << "." ;
                    }
                    cout << "\n\n   Login Successufully!!!......\n" ;
                    cout << "\n-----------------------------------\n" ;
                    while(true){
                        cout << "\n-----------------------" ;
                        cout << "\n1. Withdraw.\n" ;
                        cout << "2. Deposit.\n" ;
                        cout << "3. Check Balance.\n" ;
                        cout << "4. Logout.\n" ;
                        cout << "-----------------------\n" ;
                        int option ;
                        cout << "Enter option : " ;
                        cin >> option ;
                        switch(option){
                            case 1 : withdraw(); break ;
                            case 2 : deposit(); break ;
                            case 3 : check_balance(); break ;
                            case 4 : logout(); break ;
                            default : cout << "Invalid Option!!!\n" ; break ;
                        }
                    }
                    
                }
                else{
                    cout << "\n\t     " ;
                    for(int j = 0 ; j < 10 ; j++){
                        Sleep(500);
                        cout << "." ;
                    }
                    cout << "\n\n Your credentials are incorrect..." ;
                    cout << "\n\t        \\/ " ;
                    cout << "\n\t        /\\ " ;
                    cout << "\n\nPress X To Try Again.... " ;
                    char x ;
                    getchar();
                    cin >> x ;
                    if(x == 'x' || x == 'X'){
                        goto Login ;
                    }
                    else{
                        cout << "\n\n   Exiting The System..." ;
                    }
                }
            }
        }

        void withdraw(){
            float amount ;
            cout << "Enter amount to withdraw : " ;
            cin >> amount ;
            for(int i = 0 ; i < accounts.size() ; i++){
                if(accounts[i].balance >= amount){
                    accounts[i].balance -= amount ;
                    cout << "\nWithdrawal Successful... " ;
                    cout << "Your current balance is : $" << accounts[i].balance << endl ;
                }
            }
        }

        void deposit(){
            float amount ;
            cout << "Enter amount to deposit : " ;
            cin >> amount ;
            for(int i = 0 ; i < accounts.size() ; i++){
                accounts[i].balance += amount ;
                cout << "\nDeposit Successful... " ;
                cout << "Your current balance is : $" << accounts[i].balance << endl ;
            }
        }

        void check_balance(){
            for(int i = 0 ; i < accounts.size() ; i++){
                cout << "\nAccount Number : " << accounts[i].account_no << endl ;
                cout << "Account Balance : $" << accounts[i].balance << endl ;
            }
        }

        void logout(){
            cout << "\n    Logget out.....\n" ;
            char reponse ;
            cout << "\n  Do you want to login again ? (Y/N) : " ;
            cin >> reponse ;
            while(reponse != 'N'){
                if(reponse == 'Y'){
                    Login();
                }
                else{
                    cout << "\n   Exiting The System..." ;
                    exit(0);
                }
            }
        }

};

int main(){
    system("cls");
    system("color A");
    ATM atm ;
    atm.create_account();
    atm.Login();
    atm.withdraw();
    return 0 ; 
}