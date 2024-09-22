#include<iostream>
using namespace std;

class Vote {
    public :
        float c ;
        float cpp ;
        float java ;
        float python ;
};

void result(int votes , int choice[]){
    Vote v ;
    float percent = 100 / votes ;
    v.c = v.cpp = v.java = v.python = 0 ;
    for(int i = 0 ; i < votes ; i++){
        switch(choice[i]){
            case 1 : (v.c)++ ; break ;
            case 2 : (v.cpp)++ ; break ;
            case 3 : (v.java)++ ; break ;
            case 4 : (v.python)++ ; break ;
            default : cout << "\n\t\t\033[1;31mInvalid choice \n\033[32m" ; break ;
        }
    }
    cout << "\n\t\t\t     Result \n" ;
    cout << "\t\t   =========================\n" << endl ;
    cout << "\t\t    C Laguage      : " << percent * (v.c) << ".0%" << endl ;
    cout << "\t\t    CPP Laguage    : " << percent * (v.cpp) << ".0%" << endl ;
    cout << "\t\t    JAVA Laguage   : " << percent * (v.java) << ".0%" << endl ;
    cout << "\t\t    PYTHON Laguage : " << percent * (v.python) << ".0%\n" << endl ;
    cout << "\t\t   =========================\n" << endl ;
}

int main(){
    system("cls");
    system("color A");
    int votes ;
    cout << "\n\t\t\t Voting System \n";
    cout << "\n\t\t  Enter the number of votes : ";
    cin >> votes;
    int choice[votes];
    for(int i = 0 ; i < votes ; i++){
        cout << "\n\t\t\t1.C Language." << endl ;
        cout << "\t\t\t2.CPP Language." << endl ;
        cout << "\t\t\t3.JAVA Language." << endl ;
        cout << "\t\t\t4.PYTHON Language." ;
        cout << "\n\n\t\t   Select any one option : " ;
        cin >> choice[i] ;
    }
    result(votes,choice);
    return 0 ;
}