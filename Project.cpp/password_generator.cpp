#include <iostream>
#include <time.h>
using namespace std;

void password(int length){
    char result[length];
    char word[] = "abcdefghijklmnopqrstuvwxyz1234567890!&@^$#*" ; 
    srand(time(NULL));
    cout << "\n\t\t\t    Random : \033[1;37m" ;
    for(int i = 0 ; i < length ; i++){
        result[i] = word[rand() % 44]; 
        cout << result[i] ;
    }
    cout << "\033[0m\033[32m" ;
}

int main(){
    system("CLS");
    system("color A");  
    Random : 
    cout << "\n\t\t\tRandom Password Generator.........\n" ;
    int passLength ;
    cout << "\n\t\t\t  Enter length of password : ";
    cin >> passLength ;
    password(passLength);
    while(1){
        char ch ;
        cout << "\n\n\t\t  Do you want to generate another password ? (Y/N) : " ;
        cin >> ch ;
        if (ch == 'N' || ch == 'n'){
            break ;
        }
        system("CLS");
        goto Random ;
    }
    return 0 ;
}