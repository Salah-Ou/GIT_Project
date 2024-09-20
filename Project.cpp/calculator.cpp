#include <iostream>
using namespace std;
int main(){
    calculator :
    system("cls");
    system("color A");
    cout << "\n\t\t Welcome To The Simple Calculator in C++" << endl ;
    cout << "\t\t-----------------------------------------" << endl ;
    int num1 , num2 ;
    char op ;
    cout << "\n\t\t\tEnter the first number : " ;
    cin >> num1 ;
    cout << "\n\t\t\tEnter the operator : " ; 
    cin >> op ;
    cout << "\n\t\t\tEnter the second number : " ;
    cin >> num2 ;
    switch(op){
        case '+' : cout << "\n\t\t   /==) the sum of " << num1 << " and " << 
            num2 << " is : " << num1 + num2 << endl ;
            break ;
        case '-' : cout << "\n\t\t   ==) the subtraction of " << num1 << " and " << 
            num2 << " is : " << num1 - num2 << endl ;
            break ;
        case '*' : cout << "\n\t\t   ==) the multiply of " << num1 << " and " << 
            num2 << " is : " << num1 * num2 << endl ;
            break ;
        case '/' : if (num2 != 0){ cout << "\n\t\t   ==) the division of " << num1 << " and " << 
            num2 << " is : " << num1 / num2 << endl ;}
            else cout << "\n\n\t\t\t\033[1;31mError...!!! \n\033[0m";
            break ;
        default : cout << "\n\n\t\t\t\033[1;31mError...!!! Invalid operator \n\033[0m" ;
            break ;
    }
    cout << "\t\t-----------------------------------------\n" ;
    while(1){
        cout << "\n\t\t \033[1;34mDo you want to continue (y/n) : ";
        char choice ;
        cin >> choice ;
        cout << "\033[32m" ;
        if(choice == 'n'){
            cout << "\n\t\t\t\tExiting...\n\n" << endl ;
            break ;
        }
        goto calculator ;
    }

    return 0;
}
