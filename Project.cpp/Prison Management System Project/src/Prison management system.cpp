#include <iomanip>
#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <string>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREY "\033[30m"
#define WHITE "\033[1;37m"
#define SKYBLUE "\033[1;36m"

using namespace std;

int gotoxy(int x , int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return 0;
}

void Time() {
    time_t now = time(NULL);
    tm* ltm = localtime(&now);
    cout << WHITE << " Current Time's : " << SKYBLUE << asctime(ltm) << WHITE ; 
}

class Prison {
    private:

        struct Prisoner {
            string name;
            string gender;
            string age;
            int height;
            string eye_color;
            string crime;
            int cell_no[11] = {999, 1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009};
            string penalty_period ;
            int choice_cell ;
        };

        vector<Prisoner> prisoners;

    public:

        void login(){
            system("cls");
            gotoxy(30,1);
            Time();
            gotoxy(33,3);
            cout << BLUE << "  Prison Station Management System " ;
            gotoxy(33,5);
            cout << GREY << "------------------------------------" ;
            gotoxy(40,7);
            cout << WHITE << " 1. Sign in" ;
            gotoxy(40,9);
            cout << WHITE << " 2. Exit" ;
            gotoxy(33,11);
            cout << GREY << "------------------------------------" ;
            gotoxy(32,13);
            cout << WHITE << " Please enter your choice (1 - 2) : ";
            int choice ;
            cin >> choice ;
            if (choice == 1){
                char ch ;
                string username ;
                string password ;
                int pass_legth = 10 ;
                password.clear();
                gotoxy(45,15);
                cout << BLUE << "Sign in : " ;
                gotoxy(37,17);
                cout << "-------------------------";
                gotoxy(42,19);
                cout << "Username : " << WHITE ;
                cin >> username ;
                gotoxy(42,21);
                cout << BLUE << "Password : " << WHITE ;
                for (int i = 0 ; i < pass_legth ; i++){
                    ch = _getch();
                    if (ch == 13){
                        break ;
                    }
                    password += ch ;
                    cout << "*" ;
                }
                gotoxy(37,23);
                cout << BLUE << "-------------------------";
                Sleep(1000);
                gotoxy(38,25);
                cout << WHITE << "PRESS TO GO LOGIN..... " ;
                _getch();
                system("cls");
                Time();
                Login :
                system("cls");
                gotoxy(29,1);
                Time();
                string USERNAME , PASSWORD ;
                gotoxy(46,3);
                cout << BLUE << "Login : " ;
                gotoxy(37,5);
                cout << "-------------------------";
                gotoxy(42,7);
                cout << WHITE << "Username : " << BLUE ;
                cin >> USERNAME ;
                gotoxy(42,9);
                cout << WHITE << "Password : " << BLUE ;
                for (int i = 0 ; i < pass_legth ; i++){
                    ch = _getch();
                    if (ch == 13){
                        break ;
                    }
                    PASSWORD += ch ;
                    cout << "*" ;
                }
                gotoxy(37,11);
                cout << "-------------------------";
                gotoxy(41,13);
                cout << "Loading " ;
                for(int i = 0 ; i < 10 ; i++){
                    cout << "." ;
                    Sleep(500);
                }
                if (USERNAME == username && PASSWORD == password){
                    gotoxy(41,15);
                    cout << GREEN << "Login Successful!" ;
                    Sleep(1000);
                    gotoxy(36,17);
                    cout << WHITE << "Press any key to Continue... " ;
                    _getch();
                    system("cls");
                    Time();
                }
                else{
                    gotoxy(35,15);
                    cout << RED << "Invalid username or password!" ;
                    gotoxy(37,17);
                    cout << RED << "PLEASE TRY AGAIN ...." ;
                    Sleep(1000);
                    gotoxy(36,19);
                    cout << WHITE << "Press any key to Continue... " ;
                    _getch();
                    goto Login ;
                }
            }
        }

        void menu() {
            system("cls"); 
            while (true) {
                system("cls");
                gotoxy(32,1);
                Time();
                gotoxy(32,3);
                cout << " ----- PRISON MANAGEMENT MAIN MENU ----- ";
                gotoxy(31,5);
                cout << "============================================";
                gotoxy(33,7);
                cout << "    1.  New Prisoner entry.";
                gotoxy(33,9);
                cout << "    2.  Prisoner Details.";
                gotoxy(33,11);
                cout << "    3.  Attendance Prisoner.";
                gotoxy(33,13);
                cout << "    4.  Release Prisoner.";
                gotoxy(33,15);
                cout << "    5.  Search Prisoner.";
                gotoxy(33,17);
                cout << "    6.  Prison File.";
                gotoxy(33,19);
                cout << "    7.  Exit.";
                gotoxy(31,21);
                cout << "============================================\n";
                gotoxy(37,23);
                cout << "Enter your choice (1 - 7) : ";
                int choice;
                cin >> choice;
                switch (choice) {
                    case 1: new_prisoner(); break;
                    case 2: prisoner_details(); break;
                    case 3: attendance_prisoner(); break;
                    case 4: release_prisoner(); break;
                    case 5: search_prisoner(); break;
                    case 6: prison_file(); break;
                    case 7: gotoxy(44,25);
                        cout << GREEN << "Exiting Program...\n" << WHITE ;
                        exit(0); 
                        break;
                    default : gotoxy(44,25);   
                        cout << RED << "Invalid choice...!!!" << WHITE ; 
                        break;
                }
            }
        }

        void new_prisoner() {
            Prisoner p;
            system("cls");
            gotoxy(32,1);
            Time();
            gotoxy(30,3);
            cout << "Enter Prisoner's Name : ";
            cin.ignore();
            getline(cin, p.name);
            gotoxy(30,5);
            cout << "Enter Prisoner's Gender (Male/Female) : ";
            getline(cin, p.gender);
            gotoxy(30,7);
            cout << "Enter Prisoner's Age : ";
            cin >> p.age;
            gotoxy(30,9);
            cout << "Enter Prisoner's Height : ";
            cin >> p.height;
            gotoxy(30,11);
            cout << "Enter Prisoner's Eye Color : ";
            cin.ignore();
            getline(cin, p.eye_color);
            gotoxy(30,13);
            cout << "Enter Prisoner's Crime : ";
            getline(cin, p.crime);
            gotoxy(30,15);
            cout << "Enter The penalty period by months or years : ";
            getline(cin, p.penalty_period);
            gotoxy(30,17);
            cout << "Existing Cell no : " << GREY ;
            int found = 0 ;
            for (int i = 0; i < 11; i++) {
                cout << p.cell_no[i] << "  ";
            }
            gotoxy(30,19);
            cout << WHITE << "Enter any cell for prisoner : ";
            cin >> p.choice_cell;
            for (int i = 0; i < 11; i++){
                if (p.choice_cell == p.cell_no[i]) {
                    found = 1;
                    break;
                }
            }
            if (found == 0){
                gotoxy(37,22);
                cout << RED << "This cell is not available." << WHITE ;
                gotoxy(36,24);
                cout << "Press any key to Continue... ";
                _getch();
                Sleep(1000);
                return ;
            }
            else {
                prisoners.push_back(p);
                gotoxy(37,22);
                cout << GREEN << "New Prisoner added successfully!" << WHITE ;
                gotoxy(38,24);
                cout << "Press any key to Continue... " ;
                _getch();
                Sleep(1000);
            }
        }

        void prisoner_details() {
            system("cls");
            gotoxy(33,1);
            Time();
            if (prisoners.empty()) {
                gotoxy(38,3);
                cout << RED << " The prisoner is not on the list." << WHITE ;
                gotoxy(38,5);
                cout << " Press any key to Continue... ";
                _getch();
                Sleep(1000);
                return ;
            } else {
                gotoxy(25,5);
                cout << GREY << " <===================> Prisoner List <===================> " << WHITE ;
                for (int i = 0; i < prisoners.size(); i++) {
                    gotoxy(33,7);
                    cout << "No              :   " << i + 1 << endl ;
                    gotoxy(33,9);
                    cout << WHITE << "Name            :   " << SKYBLUE << prisoners[i].name << endl ;
                    gotoxy(33,11); 
                    cout << WHITE << "Gender          :   " << SKYBLUE << prisoners[i].gender << endl ;
                    gotoxy(33,13); 
                    cout << WHITE << "Age             :   " << SKYBLUE << prisoners[i].age << " years old." << endl ;
                    gotoxy(33,15); 
                    cout << WHITE << "Height          :   " << SKYBLUE << prisoners[i].height << " cm" << endl ;
                    gotoxy(33,17); 
                    cout << WHITE << "Eye Color       :   " << SKYBLUE << prisoners[i].eye_color << endl ;
                    gotoxy(33,19); 
                    cout << WHITE << "Crime           :   " << SKYBLUE << prisoners[i].crime << endl ;
                    gotoxy(33,21); 
                    cout << WHITE << "Cell No         :   " << SKYBLUE << prisoners[i].choice_cell << endl ;
                    gotoxy(33,23); 
                    cout << WHITE << "Penalty Period  :   " << SKYBLUE << prisoners[i].penalty_period << endl ;
                    gotoxy(25,25);
                    cout << GREY << " <========================================================>" << endl ;
                }
                gotoxy(38,28);
                cout << WHITE << "Press any key to Continue... " ;
                _getch();
            }
        }

        void attendance_prisoner() {
            system("cls");
            gotoxy(33,1);
            Time();
            if (prisoners.empty()) {
                gotoxy(39,3);
                cout << RED << " The prisoner is not on the list." << WHITE ;
                gotoxy(40,5);
                cout << " Press any key to Continue... ";
                _getch();
                return;
            } else {
                int no ;
                gotoxy(41,3);
                cout << WHITE << "Enter Prisoner's No : ";
                cin >> no ;
                if (no > 0 && no <= prisoners.size()) {
                    gotoxy(40,5);
                    cout << GREEN << "Prisoner's Attendance : " << prisoners[no - 1].choice_cell << WHITE ;
                    gotoxy(39,7);
                    cout << "Press any key to Continue... ";
                    _getch();
                }
                else{
                    gotoxy(42,5);
                    cout << RED << "Invalid Prisoner's No." << WHITE ;
                    gotoxy(39,7);
                    cout << " Press any key to Continue... ";
                    _getch();
                }
            }
        }

        void release_prisoner() {
            system("cls");
            gotoxy(33,1);
            Time();
            if (prisoners.empty()) {
                gotoxy(38,3);
                cout << RED << " The prisoner is not on the list.";
                gotoxy(39,5);
                cout << WHITE << " Press any key to Continue... ";
                _getch();
                return;
            } else {
                int no ;
                gotoxy(38,3);
                cout << WHITE << "Enter Prisoner's No : ";
                cin >> no;
                if (no > 0 && no <= prisoners.size()) {
                    prisoners.erase(prisoners.begin() + no - 1);
                    gotoxy(38,5);
                    cout << GREEN << "Prisoner released successfully!" << WHITE ;
                    gotoxy(38,7);
                    cout << "Press any key to Continue... " ;
                    _getch();
                }
            }
        }

        void search_prisoner() {
            system("cls");
            gotoxy(33,1);
            Time();
            if (prisoners.empty()) {
                gotoxy(38,3);
                cout << RED << " The prisoner is not on the list.";
                gotoxy(39,5);
                cout << WHITE << " Press any key to Continue... ";
                _getch();
                return;
            } else {
                string name;
                int found = 0;
                gotoxy(38,3);
                cout << WHITE << "Enter Prisoner's Name : ";
                cin.ignore();
                getline(cin, name);
                for (int i = 0; i < prisoners.size(); i++) {
                    if (prisoners[i].name == name) {
                        prisoner_details();
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    gotoxy(42,5);
                    cout << RED << "Prisoner not found.\n";
                }
            }
            gotoxy(39,7);
            cout << WHITE << "Press any key to Continue... ";
            _getch();
        }

        void prison_file() {
            system("cls");
            gotoxy(33,1);
            Time();
            if (prisoners.empty()) {
                gotoxy(38,3);
                cout << RED << " The prisoner is not on the list." ;
                gotoxy(39,5);
                cout << WHITE << " Press any key to Continue... ";
                _getch();
                return;
            } else {
                ofstream file("prison_file.txt");
                file << "\n\t<===================> Prisoners Lists <===================> \n";
                for (int i = 0; i < prisoners.size(); i++) {
                    file << "\n\t\t\tNo              :   " << i + 1;
                    file << "\n\t\t\tName            :   " << prisoners[i].name;
                    file << "\n\t\t\tGender          :   " << prisoners[i].gender;
                    file << "\n\t\t\tAge             :   " << prisoners[i].age << " years old.";
                    file << "\n\t\t\tHeight          :   " << prisoners[i].height << " cm";
                    file << "\n\t\t\tEye Color       :   " << prisoners[i].eye_color;
                    file << "\n\t\t\tCrime           :   " << prisoners[i].crime;
                    file << "\n\t\t\tCell No         :   " << prisoners[i].choice_cell;
                    file << "\n\t\t\tPenalty Period  :   " << prisoners[i].penalty_period;
                    file << "\n\n\t<========================================================>";
                }
                file.close();
                gotoxy(32,4);
                cout << GREEN << "The prisoner file has been saved successflly ! " ;
                gotoxy(40,6);
                cout << WHITE << "Press any key to Continue... ";
                _getch();
            }
        }
};

int main() {
    Prison p;
    p.login();
    p.menu();
    return 0;
}
