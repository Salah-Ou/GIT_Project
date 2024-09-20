#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;
int main();

void arithmetic(){
    Arithmetic :
    int choice ;
    float num1 , num2 , result ;
    cout << "\n\t\t\t      * Arithmetic Operations * \n" ;
    cout << "\t\t\t------------------------------------" ;
    cout << "\n\t\t\t\t 1. Addition.\n" ;
    cout << "\t\t\t\t 2. Subtraction.\n" ;
    cout << "\t\t\t\t 3. Multiplication.\n" ;
    cout << "\t\t\t\t 4. Division.\n" ;
    cout << "\t\t\t------------------------------------\n" ;
    cout << "\n\t\t\t  Enter your choice : " ;
    cin >> choice ;
    switch(choice){
        case 1 : cout << "\n\t\t\t  Enter Two Numbers : " ;
            cin >> num1 >> num2 ;
            result = num1 + num2 ;
            Beep(222,500);
            cout << "\n\t\t\t     ==) Result : " << num1 << " + " << num2 << " = " << result << "\n" ;
            break ;

        case 2 : cout << "\n\t\t\t  Enter Two Numbers : " ;
            cin >> num1 >> num2 ;
            result = num1 - num2 ;
            Beep(222,500);
            cout << "\n\t\t\t     ==) Result : " << num1 << " - " << num2 << " = " << result << "\n" ;
            break ;

        case 3 : cout << "\n\t\t\t  Enter Two Numbers : " ;
            cin >> num1 >> num2 ;
            result = num1 * num2 ;
            Beep(222,500);
            cout << "\n\t\t\t     ==) Result : " << num1 << " * " << num2 << " = " << result << "\n" ;
            break ;

        case 4 : cout << "\n\t\t\t  Enter Two Numbers : " ;
            cin >> num1 >> num2 ;
            if (num2 != 0) {
                Beep(222,500);
                result = num1 / num2 ;
                cout << "\n\t\t\t     ==) Result : " << num1 << " / " << num2 << " = " << result << "\n" ;
            }
            else { 
                Beep(1000,500); 
                cout << "\n\t\t\t  Error! Division by zero is not allowed.\n" ; 
            }
            break ; 
    }
    char rep ;
    cout << "\n\t\t\t  Do you want to perform another operation? (y/n) : " ;
    cin >> rep ;
    if (rep == 'y' || rep == 'Y'){
        system("CLS");
        goto Arithmetic ;
    }
    else {
        main();
    }
}

void trignometric(){
    Trignometric :
    float angle , result ;
    int choice ;
    cout << "\n\t\t\t      * Trignometric Operations * \n" ;
    cout << "\t\t\t------------------------------------" ;
    cout << "\n\t\t\t\t 1. Sine.\n" ;
    cout << "\t\t\t\t 2. Cosine.\n" ;
    cout << "\t\t\t\t 3. Tangent.\n" ;
    cout << "\t\t\t------------------------------------\n" ;
    cout << "\n\t\t\t  Enter your choice : " ;
    cin >> choice ;
    cout << "\n\t\t\t  Enter the angle in degrees : " ;
    cin >> angle ;
    angle = (angle * M_PI) / 18 ;
    switch(choice){
        case 1 : result = sin(angle);
            Beep(222,500);
            cout << "\n\t\t\t     ==) Result : sin(" << angle << ") = " << result << "\n" ;
            break ;
        case 2 : result = cos(angle);
            Beep(222,500);
            cout << "\n\t\t\t     ==) Result : cos(" << angle << ") = " << result << "\n" ;
            break ;
        case 3 : result = tan(angle);
            Beep(222,500);
            cout << "\n\t\t\t     ==) Result : tan(" << angle << ") = " << result << "\n" ;
            break ;
        default : cout << "\n\t\t\t  Invalid choice! Please try again.\n" ;
    }
    char rep ;
    cout << "\n\t\t\t  Do you want to continue ? (y/n) : " ;
    cin >> rep ;
    if (rep != 'n'){
        system("cls");
        goto Trignometric ;
    }
    else{
        main();
    }
}

void exponetial(){
    Exponetial :
    float base , exponent = 2.7182818285 ;
    float result ;
    cout << "\n\t\t\t  Enter a base : " ;
    cin >> base ;
    result = pow(exponent,base);
    Beep(222,500);
    cout << "\n\t\t\t  ==) Result : " << "exp(" << base << ") = " << result << "\n" ; 
    char rep ;
    cout << "\n\t\t\t  Do you want to continue ? (y/n) : " ;
    cin >> rep ;
    if (rep != 'n'){
        system("cls");
        goto Exponetial ;
    }
    else{
        main();
    }
}

void logaritmic(){
    Logaritmic : 
    float num , result ;
    cout << "\n\t\t\t  Enter the value to calculate log() : " ;
    cin >> num ;
    result = log10(num);
    Beep(222,500);
    cout << "\n\t\t\t     ==) Result : " << "log(" << num << ") = " << result << "\n" ;
    char rep ;
    cout << "\n\t\t\t  Do you want to continue? (y/n) : " ;
    cin >> rep ;
    if (rep != 'n'){
        system("cls");
        goto Logaritmic ;
    }
    else{
        main();
    }
}

int main(){
    int choice ;
    system("cls");
    system("color A");
    cout << "\n\t\t\t * Welcome To Advanced Calculator * \n" ;
    while(1){
        cout << "\t\t\t------------------------------------" ;
        cout << "\n\t\t\t\t1. Arithmetic.\n" ;
        cout << "\t\t\t\t2. Trignometric.\n" ;
        cout << "\t\t\t\t3. Exponetial.\n" ;
        cout << "\t\t\t\t4. Logaritmic.\n" ;
        cout << "\t\t\t\t5. Quit.\n" ;
        cout << "\t\t\t------------------------------------\n" ;
        cout << "\n\t\t\t  Enter your choice : " ;
        cin >> choice ;
        switch(choice){
            case 1 : arithmetic(); break ;
            case 2 : trignometric(); break ;
            case 3 : exponetial(); break ;
            case 4 : logaritmic(); break ;
            case 5 : cout << "\n\t\t Exiting Calculator...\n" ; exit(0); break ;
            default : cout << "\n\t\t Invalid choice...\n" ; break ;
        }
    }
    return 0 ;
}#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;
int main();

void arithmetic(){
    Arithmetic :
    int choice ;
    float num1 , num2 , result ;
    cout << "\n\t\t\t      * Arithmetic Operations * \n" ;
    cout << "\t\t\t------------------------------------" ;
    cout << "\n\t\t\t\t 1. Addition.\n" ;
    cout << "\t\t\t\t 2. Subtraction.\n" ;
    cout << "\t\t\t\t 3. Multiplication.\n" ;
    cout << "\t\t\t\t 4. Division.\n" ;
    cout << "\t\t\t------------------------------------\n" ;
    cout << "\n\t\t\t  Enter your choice : " ;
    cin >> choice ;
    switch(choice){
        case 1 : cout << "\n\t\t\t  Enter Two Numbers : " ;
            cin >> num1 >> num2 ;
            result = num1 + num2 ;
            Beep(222,500);
            cout << "\n\t\t\t     ==) Result : " << num1 << " + " << num2 << " = " << result << "\n" ;
            break ;

        case 2 : cout << "\n\t\t\t  Enter Two Numbers : " ;
            cin >> num1 >> num2 ;
            result = num1 - num2 ;
            Beep(222,500);
            cout << "\n\t\t\t     ==) Result : " << num1 << " - " << num2 << " = " << result << "\n" ;
            break ;

        case 3 : cout << "\n\t\t\t  Enter Two Numbers : " ;
            cin >> num1 >> num2 ;
            result = num1 * num2 ;
            Beep(222,500);
            cout << "\n\t\t\t     ==) Result : " << num1 << " * " << num2 << " = " << result << "\n" ;
            break ;

        case 4 : cout << "\n\t\t\t  Enter Two Numbers : " ;
            cin >> num1 >> num2 ;
            if (num2 != 0) {
                Beep(222,500);
                result = num1 / num2 ;
                cout << "\n\t\t\t     ==) Result : " << num1 << " / " << num2 << " = " << result << "\n" ;
            }
            else { 
                Beep(1000,500); 
                cout << "\n\t\t\t  Error! Division by zero is not allowed.\n" ; 
            }
            break ; 
    }
    char rep ;
    cout << "\n\t\t\t  Do you want to perform another operation? (y/n) : " ;
    cin >> rep ;
    if (rep == 'y' || rep == 'Y'){
        system("CLS");
        goto Arithmetic ;
    }
    else {
        main();
    }
}

void trignometric(){
    Trignometric :
    float angle , result ;
    int choice ;
    cout << "\n\t\t\t      * Trignometric Operations * \n" ;
    cout << "\t\t\t------------------------------------" ;
    cout << "\n\t\t\t\t 1. Sine.\n" ;
    cout << "\t\t\t\t 2. Cosine.\n" ;
    cout << "\t\t\t\t 3. Tangent.\n" ;
    cout << "\t\t\t------------------------------------\n" ;
    cout << "\n\t\t\t  Enter your choice : " ;
    cin >> choice ;
    cout << "\n\t\t\t  Enter the angle in degrees : " ;
    cin >> angle ;
    angle = (angle * M_PI) / 18 ;
    switch(choice){
        case 1 : result = sin(angle);
            Beep(222,500);
            cout << "\n\t\t\t     ==) Result : sin(" << angle << ") = " << result << "\n" ;
            break ;
        case 2 : result = cos(angle);
            Beep(222,500);
            cout << "\n\t\t\t     ==) Result : cos(" << angle << ") = " << result << "\n" ;
            break ;
        case 3 : result = tan(angle);
            Beep(222,500);
            cout << "\n\t\t\t     ==) Result : tan(" << angle << ") = " << result << "\n" ;
            break ;
        default : cout << "\n\t\t\t  Invalid choice! Please try again.\n" ;
    }
    char rep ;
    cout << "\n\t\t\t  Do you want to continue ? (y/n) : " ;
    cin >> rep ;
    if (rep != 'n'){
        system("cls");
        goto Trignometric ;
    }
    else{
        main();
    }
}

void exponetial(){
    Exponetial :
    float base , exponent = 2.7182818285 ;
    float result ;
    cout << "\n\t\t\t  Enter a base : " ;
    cin >> base ;
    result = pow(exponent,base);
    Beep(222,500);
    cout << "\n\t\t\t  ==) Result : " << "exp(" << base << ") = " << result << "\n" ; 
    char rep ;
    cout << "\n\t\t\t  Do you want to continue ? (y/n) : " ;
    cin >> rep ;
    if (rep != 'n'){
        system("cls");
        goto Exponetial ;
    }
    else{
        main();
    }
}

void logaritmic(){
    Logaritmic : 
    float num , result ;
    cout << "\n\t\t\t  Enter the value to calculate log() : " ;
    cin >> num ;
    result = log10(num);
    Beep(222,500);
    cout << "\n\t\t\t     ==) Result : " << "log(" << num << ") = " << result << "\n" ;
    char rep ;
    cout << "\n\t\t\t  Do you want to continue? (y/n) : " ;
    cin >> rep ;
    if (rep != 'n'){
        system("cls");
        goto Logaritmic ;
    }
    else{
        main();
    }
}

int main(){
    int choice ;
    system("cls");
    system("color A");
    cout << "\n\t\t\t * Welcome To Advanced Calculator * \n" ;
    while(1){
        cout << "\t\t\t------------------------------------" ;
        cout << "\n\t\t\t\t1. Arithmetic.\n" ;
        cout << "\t\t\t\t2. Trignometric.\n" ;
        cout << "\t\t\t\t3. Exponetial.\n" ;
        cout << "\t\t\t\t4. Logaritmic.\n" ;
        cout << "\t\t\t\t5. Quit.\n" ;
        cout << "\t\t\t------------------------------------\n" ;
        cout << "\n\t\t\t  Enter your choice : " ;
        cin >> choice ;
        switch(choice){
            case 1 : arithmetic(); break ;
            case 2 : trignometric(); break ;
            case 3 : exponetial(); break ;
            case 4 : logaritmic(); break ;
            case 5 : cout << "\n\t\t Exiting Calculator...\n" ; exit(0); break ;
            default : cout << "\n\t\t Invalid choice...\n" ; break ;
        }
    }
    return 0 ;
}