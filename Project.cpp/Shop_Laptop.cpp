#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <vector>

#define GREEN "\033[32m"
#define RESET "\033[0m"

using namespace std;

int gotoxy(int x , int y){
    COORD c ;
    c.X = x ;
    c.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c) ;
}

int main();

void Time(){
    time_t now = time(NULL);
    tm *local = localtime(&now);
    gotoxy(170,0);
    cout << "\033[1;32m TIME : ==) " << asctime(local) << "\033[0m\n" ;
}

class Laptop {

    private : 
        struct Buy {
            string customer ;
            string date ;
            string adress ;
            string phone_number ;
            int budget , laptopID ;
        };
        vector <Buy> orders ;

    public :

        int id[14] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};

        string laptopName[14] = {"ASUS ZENBOOK 13" , "SAMSUNG GALAXY BOOK PRO" , "HUAWEI MATEBOOK X" , "Acer Extensa 15" , "ASUS VIVOBOOK 15" 
        , "SAMSUNG GALAXY BOOK PRO", "CLEVO LAFITE PRO II" , "DELL PRECISION 5770" , "HP Probook 470 G7" , "MSI PRESTIGE 14 EVO" 
        , "HP Elitebook 650 G9" , "DELL XPS 13 9300" , "ASUS VIVOBOOK 15" , "MSI STEALTH 18 MERCEDES"} ;
       
        string brand[14] = {"ASUS" , "SAMSUNG" , "HUAWEI" , "acer" , "ASUS" , "SAMSUNG" , "CLEVO" , "DELL" , "hp" , "MSI" , "hp" , "DELL" 
        , "ASUS" , "MSI"} ;
       
        string processor[14] = {"i7-1065G7 8CPUs" , "i7-1165G7 8CPUs" , "i5-12500H 8CPUs" , "i3-1215U 8CPUs" , "i3-1215U 8CPUs" , "i5-1135G7 8CPUs" 
        , "i5-1240P 16CPUs" , "i7-12700H 20CPUs" , "i3-10110U 4CPUs" , "i5-1240U 16CPUs" , "i5-1245U 12CPUs" , "i7 1065G7 8CPUs" 
        , "i5-1135G7 8CPUs" , "ULTRA 9-185H 22CPUs"} ;
       
        string RAM[14] = {"8Gb DDR4" , "16Gb DDR4" , "16Gb DDR4" , "8Gb DDR4" , "12Gb DDR4" , "8Gb DDR4" , "16Gb DDR4" , "32Gb DDR5" , "8Gb DDR4" 
        , "16Gb DRR5" , "16Gb DDR4" , "16Gb LPDDR4X" , "8Gb DDR4" , "64Gb DDR5"} ;
       
        string Storage[14] = {"512Gb ssd" , "512Gb ssd" , "512Gb ssd" , "256Gb ssd" , "512Gb ssd" , "256Gb ssd" , "512Gb ssd" , "512Gb ssd" , "256Gb ssd" 
        , "512Gb ssd nmve" , "256Gb ssd" , "1TB ssd nvme" , "512Gb ssd nvme" , "2TB ssd nvme"} ;
       
        string GraphicCard[14] = {"intel iris Plus Graphics" , "intel iris Xe Graphics" , "intel iris Xe Graphics" , "intel UHD GGRAPHICS" 
        , "intel UHD GGRAPHICS" , "intel iris Xe Graphics" , "intel iris Xe Graphics" , "intel iris Xe Graphics + Nvidia RTX A2000 8Gb" 
        , "Intel UHD GRAPHICS + RADEON 530 Series" , "intel iris Xe Graphics" , "intel iris Xe Graphics" , "intel iris plus Graphics" 
        , "intel iris Xe Graphics" , "Nvidia RTX 4080 12Gb GDDR6"} ;
        
        string Display[14] = {"13\" FULL HD" , "15.6\" Oled FULL HD" , "14\" 2520x1680" , "15.6\" FULL HD" , "15.6\" FULL HD" 
        , "15.6\" FULL HD AMOLED" , "17\" FULL HD" , "15\" FULL UHD+" , "17\" FULL HD" , "14\" FULL HD" , "15.6\" FULL HD" , "13\" UHD+ 4K tactil" 
        , "15.6\" FULL HD" , "18\" UHD+ 120Hz"} ;
        string Price[14] = {"4200 DH" , "4900 DH" , "6500 DH" , "3850 DH" , "3300 DH" , "4500 DH" , "4200 DH" , "12500 DH" , "2400 DH" , "5300 DH" , "3990 DH" , "5300 DH" , "3900 DH" , "38999 DH"} ;

        void take_order(){
            display_order();
            Time();
            gotoxy(55,36);
            cout << "\033[1;4;34mWelcome To Take A New Computer Order \033[0m\n" ;
            gotoxy(45,38);
            Buy b ;
            cout << "\033[1;3;37mEnter the customer name : " ;
            cin >> b.customer;
            gotoxy(45,39);
            cout << "Enter your adress : " ;
            cin >> b.adress;
            gotoxy(45,40);
            cout << "Enter your phone number : " ;
            cin >> b.phone_number ;
            gotoxy(45,41);
            cout << "Enter The date : " ;
            cin >> b.date ;
            gotoxy(45,42);
            cout << "Enter your budget : " ;
            cin >> b.budget ;
            gotoxy(45,43);
            cout << "\033[1;3;37mSelect your laptop : " ;
            cin >> b.laptopID ;
            cout << "\033[0m" ;
            orders.push_back(b);
            gotoxy(55,45);
            cout << "\n\033[1;32mOrder Placed Successfully!!!\033[0m\n";
        }

        void display_order(){
            system("cls");
            Time();
            gotoxy(60, 1);
            cout << "\033[1;32mThe Best Laptops For Me" << "\033[0m\n";
            gotoxy(0, 3);
            for (int i = 0; i < 212; i++) {
                cout << "\033[1;34m-";
            }
            cout << "\n";
            gotoxy(0, 4);
            cout << left;
            cout << setw(11) << " ID" << setw(16) << "Brand" << setw(33) << "Laptop Name" << setw(23) << "Processor" << setw(17) << "RAM" << setw(19)
                << "Storage" << setw(18) << "price" << setw(36) << "Display" << "Graphic Card" << "\033[0m\n\n";
            gotoxy(0, 5);
            for (int i = 0; i < 212; i++) {
                cout << "\033[1;34m-\033[0m";
            }
            cout << "\n";
            for (int i = 0; i < 14; i++) {
                gotoxy(0,6 + (2 * i));
                cout << left;
                cout << " ";
                cout << setw(10) << id[i] << setw(14) << brand[i] << setw(32) << laptopName[i] << setw(24) << processor[i] << setw(18) << RAM[i] << setw(19)
                    << Storage[i] << setw(17) << Price[i] << setw(30) << Display[i] << GraphicCard[i] << "\033[0m\n\n";
            }
            for (int i = 0; i < 212; i++) {
                cout << "\033[1;34m-\033[0m";
            }
            cout << "\n";
            gotoxy(55,36);
            system("pause");
            for(int i = 5 ; i >= 0 ; i--){
                cout << "\r" ;
                gotoxy(55,36);
                Beep(300,500);
                cout << "\033[1;32mPLease Wait ... Loading \033[1;31m" << i << "\033[1;32m seconds.\033[0m" ;
                Sleep(1000);
            }
        }

        void delete_order(){
            system("cls");
            Time();
            if (orders.empty()){
                gotoxy(48, 3);
                cout << "\033[1;31mError : There is no order to delete.\033[0m\n";
                gotoxy(50, 5);
                system("pause");
            }
            else{
                string name ;
                gotoxy(50,3);
                cout << "\033[1;32mEnter the customer name to delete the order : " ;
                cin.ignore();
                getline(cin, name);
                for (int i = 0; i < orders.size(); i++){
                    if (orders[i].customer == name) {
                        orders.erase(orders.begin() + i);
                        gotoxy(60, 5);
                        cout << "\033[1;32mOrder deleted successfully.\033[0m\n";
                        gotoxy(55, 7);
                        system("pause");
                        for(int i = 5 ; i >= 0 ; i--){
                            cout << "\r" ;
                            gotoxy(55,9);
                            cout << "\033[1;32mPLease Wait ... Loading \033[1;31m" << i << "\033[1;32m seconds.\033[0m" ;
                            Sleep(1000);
                        }
                    }
                    else if (i == orders.size() - 1){
                        gotoxy(50, 5);
                        cout << "\033[1;31mCustomer not found.\033[0m\n";
                        gotoxy(53, 7);
                        system("pause");
                        for(int i = 5 ; i >= 0 ; i--){
                            cout << "\r" ;
                            gotoxy(55,9);
                            Beep(300,500);
                            cout << "\033[1;32mPlease Wait ... Loading \033[1;31m" << i << "\033[1;32m seconds.\033[0m" ;
                            Sleep(1000);
                        }
                    }
                }
            }
        }

        void modify_order(){
            system("cls");
            Time();
            if (orders.empty()){
                gotoxy(48, 3);
                cout << "\033[1;31mError : There is no order to modify.\033[0m\n";
                gotoxy(50, 5);
                system("pause");
            }
            else{
                string name ;
                gotoxy(50,3);
                cout << "\033[1;32mEnter the customer name to modify the order : " ;
                cin.ignore();
                getline(cin, name);
                for (int i = 0; i < orders.size(); i++){
                    if (orders[i].customer == name) {
                        Buy b = orders[i];
                        gotoxy(55, 3);
                        cout << "\033[1;32mModify the order :\n";
                        gotoxy(45, 5);
                        cout << "Enter your new customer : " ;
                        cin >> b.customer ;
                        gotoxy(45, 6);
                        cout << "Enter your new adress : " ;
                        cin >> b.adress;
                        gotoxy(45, 7);
                        cout << "Enter your new phone number : " ;
                        cin >> b.phone_number ;
                        gotoxy(45, 8);
                        cout << "Enter your new budget : " ;
                        cin >> b.budget ;
                        gotoxy(45, 9);
                        cout << "Select your new laptop ID : " ;
                        cin >> b.laptopID ;
                        gotoxy(45, 10);
                        cout << "\033[0m" ;
                        orders[i] = b ;
                        gotoxy(50, 11);
                        cout << "\033[1;32mOrder modified successfully.\033[0m\n";
                        gotoxy(50, 13);
                        for(int i = 5 ; i >= 0 ; i--){
                            cout << "\r" ;
                            gotoxy(55,18);
                            Beep(300,500);
                            cout << "\033[1;32mPLease Wait ... Loading \033[1;31m" << i << "\033[1;32m seconds.\033[0m" ;
                            Sleep(1000);
                        }
                    }
                    else{
                        gotoxy(50, 5);
                        cout << "\033[1;31mError : Customer not found.\033[0m\n";
                        gotoxy(50, 7);
                        system("pause");
                    }
                }
            }
        }

        void print_receipt_laptop(){
            receipt :
            system("cls");
            Time();
            if (!orders.empty()) {
                int budget , laptopId ; 
                gotoxy(50, 3);
                cout << "\033[1;37m ==) Please \033[1;32m\"Confirm\" \033[1;37myour budget to purchase your laptop : \033[1;32m";
                cin >> budget ;
                if (budget < stoi(Price[orders[0].laptopID - 1])) {
                    gotoxy(50, 5);
                    cout << "\033[1;31mError : Your budget is insufficient to purchase this laptop.\033[0m\n";
                    gotoxy(50, 7);
                    cout << "\033[1;32mDo you want to try again? (Y/N) : ";
                    char ch ;
                    cin >> ch ;
                    if (ch == 'Y' || ch == 'y') {
                        goto receipt ;
                    }
                }
                cout << " \033[0m" ;
                gotoxy(0, 5);
                for (int i = 0; i < 212 ; i++) {
                    cout << "\033[1;34m-";
                }
                cout << "\n" ;
                gotoxy(0, 6);
                cout << left ;
                cout << setw(11) << " ID" << setw(16) << "Brand" << setw(33) << "Laptop Name" << setw(23) << "Processor" << setw(17) << "RAM" << setw(19)
                    << "Storage" << setw(18) << "price" << setw(36) << "Display" << "Graphic Card" << "\n" ;
                gotoxy(0, 7);
                for (int i = 0; i < 212; i++) {
                    cout << "\033[1;34m-\033[0m";
                }
                cout << "\n" ;
                for(int i = 0 ; i < 14 ; i++){
                    gotoxy(0,8 + (i * stoi(Price[i])));
                    if (budget >= stoi(Price[i])){
                        cout << "\n" ;
                        cout << left;
                        cout << " ";
                        cout << setw(10) << id[i] << setw(14) << brand[i] << setw(32) << laptopName[i] << setw(24) << processor[i] << setw(18) << RAM[i] << setw(19)
                            << Storage[i] << setw(17) << Price[i] << setw(30) << Display[i] << GraphicCard[i] << "\033[0m\n";
                    }
                }
                cout << "\n" ;
                for (int i = 0; i < 212; i++) {
                    cout << "\033[1;34m-\033[0m";
                }
                cout << "\n\033[0m" ;
                LaptopID :
                cout << "\n\t\t\t\t\t\t\033[1;37m   ==) Enter your Laptop ID : \033[1;32m" ;
                cin >> laptopId ;
                cout << "\033[0m" ;
                for(int i = 0 ; i < orders.size() ; i++){
                    if (orders[i].laptopID == laptopId){
                        cout << "\033[0m" ;
                        gotoxy(44,32);
                        cout << "\033[1;32mOrder Placed Successfully!!!\033[0m\n";       
                        cout << "\033[0m" ;
                        gotoxy(45,34);
                        system("pause");
                        gotoxy(55,50);
                        for(int i = 5 ; i >= 0 ; i--){
                            cout << "\r" ;
                            gotoxy(55,36);
                            Beep(300,500);
                            cout << "\033[1;32mPLease Wait ... Loading \033[1;31m" << i << "\033[1;32m seconds.\033[0m" ;
                            Sleep(1000);
                        }
                        bool found = false ;
                        for(int i = 0 ; i < orders.size() ; i++){
                            if(orders[i].laptopID == laptopId && orders[i].budget == budget){
                                system("cls");
                                found = true ;
                                gotoxy(64,1);
                                cout << "\033[1;4;33m Print The Receipt : \033[0m" ;
                                gotoxy(25,3);
                                for (int j = 0 ; j < 100 ; j++) {
                                    cout << "\033[1;34m-\033[0m";
                                }
                                cout << "\n\033[0m" ;
                                gotoxy(37,4);
                                cout << "\033[1;33mThank You For Your Order, " << "\033[1;32m" << orders[i].customer << "\033[0m\n" ;
                                gotoxy(37,6);
                                cout << "\033[1;33mYour Order will be delivered Today On : " << "\033[1;32m" << orders[i].date << "\033[0m\n" ;
                                gotoxy(37,8);
                                cout << "\033[1;33mYour Laptop will be Shipped To : " << "\033[1;32m" << orders[i].adress << "\033[0m\n" ;
                                gotoxy(37,10);
                                cout << "\033[1;33mThe Laptop ID's : " << "\033[1;32m" << orders[i].laptopID << "\033[0m\n" ;
                                gotoxy(37,12);
                                cout << "\033[1;33mThe Customer Phone Number's : " << "\033[1;32m" << orders[i].phone_number << "\033[0m\n" ;
                                for(int j = 0 ; j < 14 ; j++){
                                    if(orders[i].laptopID == id[j]){
                                        gotoxy(37,14);
                                        cout << "\033[1;33mYour Laptop Name : " << "\033[1;32m" << laptopName[j] << "\033[0m\n" ;
                                        gotoxy(37,16);
                                        cout << "\033[1;33mThe Information about your Laptop : " << "\033[1;32m" << brand[j] << " , " << processor[j] << " , " << RAM[j] << " / " << Storage[j] << "\033[0m\n" ;
                                        gotoxy(37,18);
                                        cout << "\033[1;33mGraphics Card : " << "\033[1;32m" << GraphicCard[j] << "\033[0m\n" ;
                                        gotoxy(37,20);
                                        cout << "\033[1;33mDisplay : " << "\033[1;32m" << Display[j] << "\033[0m\n" ;
                                        gotoxy(37,22);
                                        cout << "\033[1;33mPrice : " << "\033[1;32m" << Price[j] << " DH\033[0m\n" ;
                                        gotoxy(37,24);
                                        cout << "\033[1;33mThe Current Budget : " << "\033[1;32m" << budget - stoi(Price[j]) << " DH\033[0m\n" ; 
                                        gotoxy(58,26);
                                    }
                                }
                                cout << "\033[1;33mThank You For Shipping With Us\033[0m" << "\033[1;32m" << "\033[0m\n" ;
                                gotoxy(25,27);
                                for (int j = 0 ; j < 100 ; j++) {
                                    cout << "\033[1;34m-\033[0m";
                                }
                                cout << "\n\033[0m" ;
                            }
                        }
                        gotoxy(55,30);
                        system("pause");
                        for(int i = 5 ; i >= 0 ; i--){
                            cout << "\r" ;
                            gotoxy(55,30);
                            Beep(300,500);
                            cout << "\033[1;32mPLease Wait ... Loading \033[1;31m" << i << "\033[1;32m seconds.\033[0m" ;
                            Sleep(1000);
                        }
                    }
                    else{
                        gotoxy(55,32);
                        cout << "\033[1;31mInvalid Laptop ID entered.\033[0m\n" ;
                        gotoxy(55,34);
                        cout << "Press any key to continue.... " ;
                        _getch();
                        system("cls");
                        goto LaptopID ;
                    }
                }
            }
            else{
                cout << "\n\t\t\t\t\t\t\033[1;31mNo order placed yet!!!\033[0m";
                gotoxy(43,6);
                system("pause");
            }
        }

};

int main(){
    system("cls");
    Time();
    string username , password ;
    int password_lentgh = 10 ;
    char ch ;
    password.clear();
    gotoxy(20,1);
    for(int i = 0 ; i < 42 ; i++){
        cout << "\033[1;33m-" ;
    }
    cout << "\n" ;
    gotoxy(38,2);
    cout << "LOGIN\n";
    gotoxy(20,3);
    for(int i = 0 ; i < 42 ; i++){
        cout << "-" ;
    }
    cout << "\n\033[0m" ;
    gotoxy(22,5);
    cout << "\033[1;30mPlease Enter Your Username : \033[1;32m" ;
    cin.ignore();
    getline(cin,username);
    gotoxy(22,7);
    cout << "\033[1;30mPlease Enter Your Password : " ;
    for(int i = 0 ; i < password_lentgh ; i++){
        ch = _getch();
        if (ch == 13) break ;
        password += ch ;
        cout << "\033[1;32m*" ;
    }
    cout << "\033[0m" ;
    if (password == "12345"){
        gotoxy(33,9);
        cout << "Loading" ;
        for(int i = 0 ; i < 10 ; i++){
            cout << "." ;
            Sleep(800);
        }
        gotoxy(33,11);
        cout << "\033[1;32mLogin Successful\033[0m\n" ;
        gotoxy(25,13);
        system("pause");
        Laptop lp ;
        int choice ;
        while(1){
            system("cls");
            Time();
            gotoxy(20,1);
            for(int i = 0 ; i < 42 ; i++){
                cout << "\033[1;33m-" ;
            }
            cout << "\n" ;
            gotoxy(25,2);
            cout << "Computer Store Management system\n";
            gotoxy(20,3);
            for(int i = 0 ; i < 42 ; i++){
                cout << "-" ;
            }
            cout << "\n\033[0m" ;
            gotoxy(20,5);
            for(int i = 0 ; i < 42 ; i++){
                cout << "\033[1;32m*" ;
            }
            cout << "\n" ;
            gotoxy(20,6);
            cout << "\033[1;32m||                                      ||\n";
            gotoxy(20,7);
            cout << "\033[1;32m||\033[1;39m\t  1.  Take New computer Order.    \033[1;32m  ||\n";
            gotoxy(20,8);
            cout << "\033[1;32m||\033[1;39m\t  2.  Display All Laptops.        \033[1;32m  ||\n";
            gotoxy(20,9);
            cout << "\033[1;32m||\033[1;39m\t  3.  Delete An Order.            \033[1;32m  ||\n";
            gotoxy(20,10);
            cout << "\033[1;32m||\033[1;39m\t  4.  Modify An Order.            \033[1;32m  ||\n";
            gotoxy(20,11);
            cout << "\033[1;32m||\033[1;39m\t  5.  Print The Receipt.\033[1;32m            ||\n";
            gotoxy(20,12);
            cout << "\033[1;32m||\033[1;39m\t  6.  Quit.                       \033[1;32m  ||\n";
            gotoxy(20,13);
            cout << "\033[1;32m||                                      ||\n";
            gotoxy(20,14);
            for(int i = 0 ; i < 42 ; i++){
                cout << "\033[1;32m*" ;
            }
            cout << "\n" ;
            gotoxy(28,16);
            cout << "Enter your choice : " ;
            cin >> choice ;
            cout << "\033[0m" ;
            switch(choice){
                case 1 : lp.take_order(); break ;
                case 2 : lp.display_order(); break ;
                case 3 : lp.delete_order(); break ;
                case 4 : lp.modify_order(); break ;
                case 5 : lp.print_receipt_laptop(); break ;
                case 6 : gotoxy(32,18); cout << "\033[1;33mExiting Program...\033[0m\n\n" ;exit(0); break ;
                default : gotoxy(32,20); cout << "\033[1;31mInvalid choice  !!\033[0m\n\n\n" ; 
                    gotoxy(24,22); system("pause"); break ; 
            }
        }
    }
    else{
        gotoxy(33,9);
        cout << "Loading" ;
        for(int i = 0 ; i < 10 ; i++){
            cout << "." ;
            Sleep(800);
        }
        gotoxy(33,11);
        cout << "\033[1;31mLogin Failed !\033[0m\n" ;
        gotoxy(25,13);
        system("pause");
        main();
    }
    
    return 0 ;
}
