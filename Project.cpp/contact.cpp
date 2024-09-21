#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include <time.h>

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
    gotoxy(75,0);
    cout << "\033[1;32m==) \033[1;4;3;32mThe current Time :\033[0m  \033[37m" << asctime(local) << "\033[0m";
}

class Contact {
    private : 
        struct Info {
            string name ;
            string phone_no ;
            string adress ;
            string email ;
            string password ;
        };
        vector <Info> info ;
    public :

        void add_contact();
        void show_contacts();
        void update_contact();
        void delete_contact();
        void search_contact();
};

void Contact::add_contact(){
    system("cls");
    Time();
    Info new_contact ;
    gotoxy(28,3);
    cout << "\033[3;34mAdding New Contact : " ;
    gotoxy(17,5);
    cout << "\033[1;34m-----------------------------------------\n" ;
    gotoxy(20,7);
    cout << "\033[37mEnter your name : \033[34m" ;
    cin >> new_contact.name ;
    gotoxy(20,9);
    cout << "\033[37mEnter your phone number : \033[34m" ;
    cin >> new_contact.phone_no ;
    gotoxy(20,11);
    cout << "\033[37mEnter your adress : \033[34m" ;
    cin >> new_contact.adress ;
    gotoxy(20,13);
    cout << "\033[37mEnter your email : \033[34m" ;
    cin >> new_contact.email ;
    gotoxy(20,15);
    char ch ;
    new_contact.password.clear();
    cout << "\033[37mEnter your password email : \033[34m" ;
    for(int i = 0 ; i < 10 ; i++){
        ch = _getch();
        if (ch == 13) break ;
        new_contact.password += ch ;
        cout << "*" ;
    }
    info.push_back(new_contact);
    gotoxy(17,17);
    cout << "\033[1;34m-----------------------------------------\033[0m" ;
    gotoxy(23,19);
    cout << "\033[3;32mContact added Successufully  !\033[0m" ;
    for(int i = 5 ; i >= 0 ; i--){
        cout << "\r" ;
        gotoxy(25,21);
        cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
        Sleep(500);
        Beep(500,500);
    }
}

void Contact::show_contacts(){
    system("cls");
    Time();
    if (!info.empty()){
        for (auto& info : info){
            gotoxy(28,2);
            cout << "\033[3;33m *** Contacts ***  \033[0m" ;
            gotoxy(18,4);
            cout << "\033[1;34m--------------------------------------" ;
            gotoxy(22,6);
            cout << "\033[1;3;34mName           : \033[37m" << info.name ;
            gotoxy(22,8);
            cout << "\033[1;3;34mPhone Number   : \033[37m" << info.phone_no ; 
            gotoxy(22,10);
            cout << "\033[1;3;34mAdress         : \033[37m" << info.adress ; 
            gotoxy(22,12);
            cout << "\033[1;3;34mEmail          : \033[37m" << info.email ; 
            gotoxy(22,14);
            cout << "\033[1;3;34mPassword Email : \033[37m" << info.password ;
            gotoxy(18,16);
            cout << "\033[1;34m--------------------------------------\033[0m" ;
            for(int i = 5 ; i >= 0 ; i--){
                cout << "\r" ;
                gotoxy(24,19);
                cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                Sleep(500);
                Beep(500,500);
            }
        }
    }
    else {
        gotoxy(20,4);
        cout << "\033[1;31mNo contact in the directory. \033[0m" ;
        gotoxy(18,6);
        system("pause");
    }
}

void Contact::update_contact(){
    system("cls");
    Time();
    if (!info.empty()){
        string up_name ;
        gotoxy(28,2);
        cout << "\033[3;33m* Updating Contact *\033[0m" ;
        gotoxy(18,4);
        cout << "\033[1;34m--------------------------------------" ;
        gotoxy(10,6);
        cout << "\033[32mEnter the name of the contact you want to update : " ;
        cin >> up_name ;
        for(auto& info : info){ 
            if (up_name == info.name){
                gotoxy(22,8);
                cout << "\033[37mEnter the new name : \033[34m" ;
                cin >> info.name ;
                gotoxy(22,10);
                cout << "\033[37mEnter the new phone number : \033[34m" ;
                cin >> info.phone_no ;
                gotoxy(22,12);
                cout << "\033[37mEnter the new adress : \033[34m" ;
                cin >> info.adress ;
                gotoxy(22,14);
                cout << "\033[37mEnter the new email : \033[34m" ;
                cin >> info.email ;
                gotoxy(22,16);
                char ch ;
                info.password.clear();
                cout << "\033[37mEnter the new password email : \033[34m" ;
                for(int i = 0 ; i < 10 ; i++){
                    ch = _getch();
                    if (ch == 13) break ;
                    info.password += ch ;
                    cout << "*" ;
                }
                gotoxy(25,18);
                cout << "\033[1;32mContact updated Successfully  !\033[0m" ;
                for(int i = 5 ; i >= 0 ; i--){
                    cout << "\r" ;
                    gotoxy(25,22);
                    cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                    Sleep(500);
                    Beep(500,500);
                }
            }
        }
    }
    else {
        gotoxy(20,4);
        cout << "\033[1;31mNo contact in the directory\033[0m" ;
        gotoxy(18,6);
        system("pause");
    }
}

void Contact::delete_contact(){ 
    search :
    system("cls");
    Time();
    if (!info.empty()){
        string del_name ;
        gotoxy(25,2);
        cout << "\033[1;32mEnter the name of the contact you want to delete : " ;
        cin >> del_name ;
        bool found = false ;
        for(int i = 0 ; i < info.size() ; i++){
            if (del_name == info[i].name){
                info.erase(info.begin() + i);
                gotoxy(33,6);
                cout << "\033[1;32mContact deleted Successfully !\033[0m" ;
                for(int i = 5 ; i >= 0 ; i--){
                    cout << "\r" ;
                    gotoxy(34,9);
                    cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                    Sleep(500);
                    Beep(500,500);
                }
                found = true ;
            }
            else {
                gotoxy(39,4);
                cout << "\033[1;31mNo such contact found\033[0m" ;
                gotoxy(35,6);
                system("pause");
                found = false ;
                goto search ;
                break ;
            }
        }
    }
    else {
        gotoxy(20,4);
        cout << "\033[1;31mNo contact in the directory\033[0m" ;
        gotoxy(18,6);
        system("pause");
    }
}

void Contact::search_contact(){
    Search : 
    system("cls");
    Time();
    if (!info.empty()){
        int option ;
        gotoxy(26,2);
        cout << "\033[3;33m* Searching Contact *\033[0m" ;
        gotoxy(18,4);
        cout << "\033[1;34m--------------------------------------\n" ;
        gotoxy(23,6);
        cout << "1. Search by Name \n" ;
        gotoxy(23,8);
        cout << "2. Search by Phone Number \n" ;
        gotoxy(23,10);
        cout << "3. Search by Adress \n" ;
        gotoxy(23,12);
        cout << "4. Search by Email \n" ;
        gotoxy(18,14);
        cout << "\033[1;34m--------------------------------------\n" ;
        gotoxy(23,16);
        cout << "Choose an option : " ;
        cin >> option ;
        cout << "\033[0m" ;
        if (option == 1){
            string search_name ;
            gotoxy(10,18);
            cout << "\033[1;37mEnter the name you want to search in the contact : " ;
            cin >> search_name ;
            bool found = false ;
            for(int i = 0 ; i < info.size() ; i++){
                if (search_name == info[i].name){
                    gotoxy(20,21);
                    cout << "\033[1;37mSeached by " << info[i].name << " name\'s\033[0m" ;
                    gotoxy(13,23);
                    cout << "\033[1;33m------------------------------------------" ;
                    gotoxy(16,25);
                    cout << "Name : \033[1;37m" << info[i].name ;
                    gotoxy(16,27);
                    cout << "\033[1;33mPhone Number : \033[1;37m" << info[i].phone_no ;
                    gotoxy(16,29);
                    cout << "\033[1;33mAdress : \033[1;37m" << info[i].adress ;
                    gotoxy(16,31);
                    cout << "\033[1;33mEmail : \033[1;37m" << info[i].email ;
                    gotoxy(16,33);
                    cout << "\033[1;33mPassword Email : \033[1;37m" << info[i].password ;
                    gotoxy(13,35);
                    cout << "\033[1;33m------------------------------------------" ;
                    for(int i = 5 ; i >= 0 ; i--){
                        cout << "\r" ;
                        gotoxy(22,37);
                        cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                        Sleep(500);
                        Beep(500,500);
                    }
                }
                found = true ;
                if (!found){
                    gotoxy(25,20);
                    cout << "\033[1;31mThis name " << search_name << " not found in contact.\033[0m" ;
                }
            }
        }
        else if (option == 2){
            string search_phone_no ;
            gotoxy(10,18);
            cout << "Enter the phone number you want to search in the contact : " ;
            cin >> search_phone_no ;
            bool found = false ;
            for(int i = 0 ; i < info.size() ; i++){
                if (search_phone_no == info[i].phone_no){
                    gotoxy(20,21);
                    cout << "\033[1;37mSeached by " << info[i].phone_no << " name\'s\033[0m" ;
                    gotoxy(13,23);
                    cout << "\033[1;33m------------------------------------------" ;
                    gotoxy(16,25);
                    cout << "Name : \033[1;37m" << info[i].name ;
                    gotoxy(16,27);
                    cout << "\033[1;33mPhone Number : \033[1;37m" << info[i].phone_no ;
                    gotoxy(16,29);
                    cout << "\033[1;33mAdress : \033[1;37m" << info[i].adress ;
                    gotoxy(16,31);
                    cout << "\033[1;33mEmail : \033[1;37m" << info[i].email ;
                    gotoxy(16,33);
                    cout << "\033[1;33mPassword Email : \033[1;37m" << info[i].password ;
                    gotoxy(13,35);
                    cout << "\033[1;33m------------------------------------------" ;
                    for(int i = 5 ; i >= 0 ; i--){
                        cout << "\r" ;
                        gotoxy(22,37);
                        cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                        Sleep(500);
                        Beep(500,500);
                    }
                }
                found = true ;
                if (!found){
                    gotoxy(25,20);
                    cout << "\033[1;31mThis name " << search_phone_no<< " not found in contact.\033[0m" ;
                }
            }
        }
        else if (option == 3){
            string search_adress ;
            gotoxy(10,17);
            cout << "Enter the adress you want to search in the contact : " ;
            cin >> search_adress ;
            bool found = false ;
            for(int i = 0 ; i < info.size() ; i++){
                if (search_adress == info[i].adress){
                    gotoxy(20,21);
                    cout << "\033[1;37mSeached by " << info[i].adress << " name\'s\033[0m" ;
                    gotoxy(13,23);
                    cout << "\033[1;33m------------------------------------------" ;
                    gotoxy(16,25);
                    cout << "Name : \033[1;37m" << info[i].name ;
                    gotoxy(16,27);
                    cout << "\033[1;33mPhone Number : \033[1;37m" << info[i].phone_no ;
                    gotoxy(16,29);
                    cout << "\033[1;33mAdress : \033[1;37m" << info[i].adress ;
                    gotoxy(16,31);
                    cout << "\033[1;33mEmail : \033[1;37m" << info[i].email ;
                    gotoxy(16,33);
                    cout << "\033[1;33mPassword Email : \033[1;37m" << info[i].password ;
                    gotoxy(13,35);
                    cout << "\033[1;33m------------------------------------------" ;
                    for(int i = 5 ; i >= 0 ; i--){
                        cout << "\r" ;
                        gotoxy(22,37);
                        cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                        Sleep(500);
                        Beep(500,500);
                    }
                }
                found = true ;
                if (!found){
                    gotoxy(25,20);
                    cout << "\033[1;31mThis name " << search_adress << " not found in contact.\033[0m" ;
                }
            }
        }
        else if (option == 4){
            string search_email ;
            gotoxy(10,17);
            cout << "Enter the name you want to search in the contact : " ;
            cin >> search_email ;
            bool found = false ;
            for(int i = 0 ; i < info.size() ; i++){
                if (search_email == info[i].name){
                    gotoxy(20,21);
                    cout << "\033[1;37mSeached by " << info[i].email << " name\'s\033[0m" ;
                    gotoxy(13,23);
                    cout << "\033[1;33m------------------------------------------" ;
                    gotoxy(16,25);
                    cout << "Name : \033[1;37m" << info[i].name ;
                    gotoxy(16,27);
                    cout << "\033[1;33mPhone Number : \033[1;37m" << info[i].phone_no ;
                    gotoxy(16,29);
                    cout << "\033[1;33mAdress : \033[1;37m" << info[i].adress ;
                    gotoxy(16,31);
                    cout << "\033[1;33mEmail : \033[1;37m" << info[i].email ;
                    gotoxy(16,33);
                    cout << "\033[1;33mPassword Email : \033[1;37m" << info[i].password ;
                    gotoxy(13,35);
                    cout << "\033[1;33m------------------------------------------" ;
                    for(int i = 5 ; i >= 0 ; i--){
                        cout << "\r" ;
                        gotoxy(22,37);
                        cout << "\033[1;33mLoading... Wait " << i << " Seconds.\033[0m" ;
                        Sleep(500);
                        Beep(500,500);
                    }
                }
                found = true ;
                if (!found){
                    gotoxy(25,20);
                    cout << "\033[1;31mThis name " << search_email << " not found in contact.\033[0m" ;
                }
            }
        }
        else {
            gotoxy(20,18);
            cout << "\033[1;31mInvalid choice\033[0m" ;
            gotoxy(18,20);
            system("pause");
        }
    }
    else {
        gotoxy(20,4);
        cout << "\033[1;31mNo contact in the directory\033[0m" ;
        gotoxy(18,6);
        system("pause");
    }
}

int main(){
    system("cls");
    system("color A");
    int choice ; 
    Contact c ;
    while(true){
        system("cls");
        Time();
        gotoxy(21,2);
        cout << "\033[1;33m** \033[1;3;34mWelcome To The Telephone Directory \033[1;33m**\033[0m";
        gotoxy(17,4);
        cout << "\033[1;33m------------------------------------------------\n";
        gotoxy(20,5);
        cout << "1. Add a Contact." ;
        gotoxy(20,6);
        cout << "2. Show all contacts." ;
        gotoxy(20,7);
        cout << "3. Update a contact." ;
        gotoxy(20,8);
        cout << "4. Delete a Contact." ;
        gotoxy(20,9);
        cout << "5. Search a Contact by name or phone number." ;
        gotoxy(20,10);
        cout << "6. Exit.\n" ;
        gotoxy(17,11);
        cout << "------------------------------------------------\n\033[0m" ;
        gotoxy(19,13);
        cout << "\033[3;34mEnter your choice : ";
        cin >> choice ;
        cout << "\033[0m" ;
        switch(choice){
            case 1 : c.add_contact(); break ;
            case 2 : c.show_contacts(); break ;
            case 3 : c.update_contact(); break ;
            case 4 : c.delete_contact(); break ;
            case 5 : c.search_contact(); break ; 
            case 6 : gotoxy(28,15); cout << "\033[1;32mExiting Contact....\n\033[0m" ; exit(0); break ;
            default : gotoxy(28,15); cout << "\033[1;31mInvalid Choice.\n\033[0m" ; break ;
        }
    }
    return 0 ;
}