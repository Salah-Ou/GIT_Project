#include <iomanip>
#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

class Prison {
    private :
        struct Prisoner {
            string name ;
            string gender ;
            string age ;
            int height ;
            string eye_color ;
            string crime ;
            int cell_no[11] = {999,1000,1001,1002,1003,1004,1005,1006,1007,1008,1009};
            int choice_cell ;
            int arrest_day , arrest_mon , arrest_year ;
            int release_day , release_mon , release_year ;
            int punishment_days , punishment_months , punishment_years ; 
        };
        vector <Prisoner> prisoner ;
    public : 
        void Time(){
            system("cls");
            time_t now = time(NULL);
            tm *ltm = localtime(&now);
            cout << "\n\t\t\t\t\t\t\t\t\t" << asctime(ltm);
            Sleep(1000);
        }

        void menu(){
            system("cls");
            Time();
            cout << "\n\t\t\t\t   ----- PRISON MANAGEMENT MAIN MENU ----- \n" ;
            while(true){
                cout << "\n\t\t\t\t============================================\n" ;
                cout << "\n\t\t\t\t    1.  New Prisoner entry.\n" ;
                cout << "\n\t\t\t\t    2.  Prisoner Details.\n" ;
                cout << "\n\t\t\t\t    3.  Attendance Prisoner.\n" ;
                cout << "\n\t\t\t\t    4.  Release Prisoner.\n" ;
                cout << "\n\t\t\t\t    5.  Search Prisoner.\n" ;
                cout << "\n\t\t\t\t    6.  Prison File.\n" ;
                cout << "\n\t\t\t\t    7.  Exip.\n\n" ;
                cout << "\t\t\t\t============================================\n" ;
                cout << "\n\t\t\t\t  Enter your choice (1 - 7) : ";
                int choice ;
                cin >> choice ;
                switch(choice){
                    case 1 : new_prisoner(); break ;
                    case 2 : prisoner_details(); break ;
                    case 3 : attendance_prisoner(); break ;
                    case 4 : release_prisoner(); break ;
                    case 5 : search_prisoner(); break ;
                    case 6 : prison_file(); break ;
                    case 7 : cout << "\n\t\t\t\t  Exiting Program...\n" ; exit(0); break ;
                    default : cout << "\n\t\t\t  Invalid choice...!!!\n" ; break ;
                }
            }
        }

        void login(){
            system("cls");
            Time();
            cout << "\n\t\t\t\t  Prison Station Management System " ;
            cout << "\n\t\t\t\t------------------------------------" ;
            cout << "\n\t\t\t\t  1. Login" ;
            cout << "\n\t\t\t\t  2. Exit" ;
            cout << "\n\t\t\t\t------------------------------------" ;
            cout << "\n\t\t\t\t  Please enter your choice (1 - 2) : ";
            int choice ;
            cin >> choice ;
            if (choice == 1){
                Login :
                system("cls");
                Time();
                char ch ;
                string username = "admin" ;
                string password = "admin" ;
                int pass_legth = 10 ;
                password.clear();
                cout << "\n\t\t\t\t\t Login : \n" ;
                cout << "\t\t\t\t-------------------------";
                cout << "\n\t\t\t\t  Username : ";
                cin >> username ;
                cout << "\t\t\t\t  Password : " ;
                for (int i = 0 ; i < pass_legth ; i++){
                    ch = _getch();
                    if (ch == 13){
                        break ;
                    }
                    password += ch ;
                    cout << "*" ;
                }
                cout << "\n\t\t\t\t-------------------------";
                cout << "\n\n\t\t\t\t   Loading " ;
                for(int i = 0 ; i < 10 ; i++){
                    cout << "." ;
                    Sleep(500);
                }
                if (username == "admin" && password == "admin"){
                    cout << "\n\n\t\t\t\t  Login Successful!\n" ;
                    Sleep(1000);
                    cout << "\n\t\t\t\tPress any key to Continue... " ;
                    _getch();
                    system("cls");
                    Time();
                }
                else{
                    cout << "\n\n\t\t\t\t  Invalid username or password!\n" ;
                    Sleep(1000);
                    cout << "\n\n\t\t\t\t  Press any key to Continue... " ;
                    _getch();
                    goto Login ;
                }
            }
        }

        void new_prisoner(){
            Prisoner p ;
            cout << "\n\t\t\t\tEnter Prisoner's Name : ";
            cin.ignore();
            getline(cin,p.name);
            cout << "\n\t\t\t\tEnter Prisoner's Gender (Male/Female) : ";
            getline(cin,p.gender);
            cout << "\n\t\t\t\tEnter Prisoner's Age : ";
            cin >> p.age ;
            cout << "\n\t\t\t\tEnter Prisoner's Height : ";
            cin >> p.height ;
            cout << "\n\t\t\t\tEnter Prisoner's Eye Color : ";
            cin.ignore();
            getline(cin,p.eye_color);
            cout << "\n\t\t\t\tEnter The arrest date : " ;
            cin >> p.arrest_day >> p.arrest_mon >> p.arrest_year ;
            cout << "\n\t\t\t\tEnter Prisoner's Crime : ";
            cin.ignore();
            getline(cin,p.crime);
            cout << "\n\t\t\t\tEnter Prisoner's Release Date : ";
            cin >> p.release_day >> p.release_mon >> p.release_year ;
            p.punishment_years = -((p.release_year - p.arrest_year)); 
            p.punishment_months = -((p.release_mon - p.arrest_mon));
            p.punishment_days = (p.release_day - p.arrest_day);
            cout << "\n\t\t\t\tPrisoner's Punishment date : " << p.punishment_years << " years , " 
            << p.punishment_months << " months , " << p.punishment_days << " days.\n" ;
            cout << "\n\t\tExisting Cell no : " ;
            for(int i = 0 ; i < 11 ; i++){
                cout << p.cell_no[i] << "  " ;
            }
            cout << "\n\n\t\t\t\tEnter any cell for prisoner : " ;
            cin >> p.choice_cell ;
            Sleep(2000);
            prisoner.push_back(p);
            cout << "\n\t\t\t\tNew Prisoner added successfully!\n" ;
            cout << "\n\t\t\t\tPress any key to Continue... " ;
            _getch();
            Sleep(1000);
        }

        void prisoner_details(){
            system("cls");
            Time();
            if (prisoner.empty()){
                cout << "\n\t\t\t\t No Prisoner Existing in the lisp.\n" ;
            }
            else{
                cout << "\n\t\t\t\t\t <===================> Prisoner List <===================> \n" ;
                for(int i = 0 ; i < prisoner.size() ; i++){
                    cout << "\n\t\t\t\t\t\t No              :   " << i + 1 ;
                    cout << "\n\t\t\t\t\t\t Name            :   " << prisoner[i].name ;
                    cout << "\n\t\t\t\t\t\t Gender          :   " << prisoner[i].gender ;
                    cout << "\n\t\t\t\t\t\t Age             :   " << prisoner[i].age << " years." ;
                    cout << "\n\t\t\t\t\t\t Height          :   " << prisoner[i].height << " cm" ;
                    cout << "\n\t\t\t\t\t\t Eye Color       :   " << prisoner[i].eye_color ;
                    cout << "\n\t\t\t\t\t\t Crime           :   " << prisoner[i].crime ;
                    cout << "\n\t\t\t\t\t\t Cell No         :   " << prisoner[i].choice_cell ;
                    cout << "\n\t\t\t\t\t\t Release Date    :   " << prisoner[i].release_day 
                    << prisoner[i].release_mon << prisoner[i].release_year ;
                    cout << "\n\t\t\t\t\t\t Punishment Date :   " << prisoner[i].punishment_years << "years ," << prisoner[i].punishment_months << "months ," 
                         << prisoner[i].punishment_days << "days.\n" ;
                        cout << "\n\t\t\t\t\t <========================================================>" ;
                }
                cout << "\n\t\t\t\tPress any key to Continue... " ;
                _getch();
            }
        }

        void attendance_prisoner(){
            system("cls");
            Time();
            if (prisoner.empty()){
                cout << "\n\t\t\t\t No Prisoner Existing in the lisp.\n" ;
            }
            else{
                int no ;
                cout << "\n\t\t\t\tEnter Prisoner's No : " ;
                cin >> no ;
                if (no > 0 && no <= prisoner.size()){
                    cout << "\n\t\t\t\tPrisoner's Attendance : " << prisoner[no - 1].choice_cell << endl ;
                    cout << "\n\t\t\t\tPress any key to Continue... " ;
                    _getch();
                }
            }
        }

        void release_prisoner(){
            system("cls");
            Time();
            if (prisoner.empty()){
                cout << "\n\t\t\t\t No Prisoner Existing in the lisp.\n" ;
            }
            else{
                int no ;
                cout << "\n\t\t\t\tEnter Prisoner's No : " ;
                cin >> no ;
                if (no > 0 && no <= prisoner.size()){
                    prisoner.erase(prisoner.begin() + no - 1);
                    cout << "\n\t\t\t\tPrisoner released successfully!\n" ;
                    cout << "\n\t\t\t\tPress any key to Continue... " ;
                    _getch();
                }
            }
        }

        void search_prisoner(){
            system("cls");
            Time();
            if (prisoner.empty()){
                cout << "\n\t\t\t\t No Prisoner Existing in the lisp.\n" ;
            }
            else{
                string name ;
                int found = 0 ;
                cout << "\n\t\t\t\tEnter Prisoner's Name : ";
                cin.ignore();
                getline(cin,name);
                for(int i = 0 ; i < prisoner.size() ; i++){
                    if (prisoner[i].name == name){
                        cout << "\n\t\t\t\t prisoner found in cell.\n" ;
                        found = 1 ; 
                        Sleep(1000);
                        cout << "\n\t\t\t\tPress any key to Continue... " ;
                        _getch();
                        break ;
                    }
                    else{
                        cout << "\n\t\t\t\tPrisoner not found in cell.\n" ;
                        Sleep(1000);
                        cout << "\n\t\t\t\tPress any key to Continue... " ;
                        _getch();
                    }
                }
            }
        }

        void prison_file(){
            system("cls");
            Time();
            int choice ;
            cout << "\n\t\t\t\t  1.  TXT FILE.\n" ;
            cout << "\t\t\t\t  2.  HTML FILE.\n" ;
            cout << "\n\t\t\t\tEnter your choice : " ;
            cin >> choice ;
            if (choice == 1){
                ofstream file ;
                file.open("Prison.txt") ;
                if (!file.is_open()){
                    cout << "\n\t\t\t\tError in opening file.\n" ;
                    Sleep(2000);
                    return ;
                }
                file << "\n\t\t\t============= Prisoner List ============= \n" ;
                for(int i = 0 ; i < prisoner.size() ; i++){
                    file << "\n\tNo : " << i + 1 ;
                    file << "\n\tName : " << prisoner[i].name ;
                    file << "\n\tGender : " << prisoner[i].gender ;
                    file << "\n\tAge : " << prisoner[i].age << " years." ;
                    file << "\n\tHeight : " << prisoner[i].height << " cm" ;
                    file << "\n\tEye Color : " << prisoner[i].eye_color ;
                    file << "\n\tCrime : " << prisoner[i].crime ;
                    file << "\n\tCell No : " << prisoner[i].choice_cell ;
                    file << "\n\tRelease Date : " << prisoner[i].release_day << prisoner[i].release_mon << prisoner[i].release_year ;
                    file << "\n\tPunishment Date : " << prisoner[i].punishment_years << "years ," << prisoner[i].punishment_months << "months ," 
                         << prisoner[i].punishment_days << "days.\n\n" ;
                    file << "----------------------------------------------------------------\n" ;
                }
                file.close() ;
                cout << "\n\t\t\t\tPrisoner List saved in Prison.txt file successfully!\n" ;
                Sleep(2000);
                return ;
            }
            else if (choice == 2){
                ofstream file ;
                file.open("Prison.html") ;
                if (!file.is_open()){
                    cout << "\n\t\t\t\tError in opening file.\n" ;
                    Sleep(2000);
                    return ;
                }
                file << "<html>\n" ;
                file << "<head>\n" ;
                file << "<title>Prisoner List</title>\n" ;
                file << "</head>\n" ;
                file << "<body>\n" ;
                file << "<h1>Prisoner List</h1>\n" ;
                file << "<table border='1'>\n" ;
                file << "<tr>\n" ;
                file << "<th>No</th>\n" ;
                file << "<th>Name</th>\n" ;
                file << "<th>Gender</th>\n" ;
                file << "<th>Age</th>\n" ;
                file << "<th>Height</th>\n" ;
                file << "<th>Eye Color</th>\n" ;
                file << "<th>Crime</th>\n" ;
                file << "<th>Cell No</th>\n" ;
                file << "<th>Release Date</th>\n" ;
                file << "<th>Punishment Date</th>\n" ;
                file << "</tr>\n" ;
                for(int i = 0 ; i < prisoner.size() ; i++){
                    file << "<tr>\n" ;
                    file << "<td>" << i + 1 << "</td>\n" ;
                    file << "<td>" << prisoner[i].name << "</td>\n" ;
                    file << "<td>" << prisoner[i].gender << "</td>\n" ;
                    file << "<td>" << prisoner[i].age << " years.</td>\n" ;
                    file << "<td>" << prisoner[i].height << " cm</td>\n" ;
                    file << "<td>" << prisoner[i].eye_color << "</td>\n" ;
                    file << "<td>" << prisoner[i].crime << "</td>\n" ;
                    file << "<td>" << prisoner[i].choice_cell << "</td>\n" ;
                    file << "<td>" << prisoner[i].release_day << prisoner[i].release_mon << prisoner[i].release_year << "</td>\n" ;
                    file << "<td>" << prisoner[i].punishment_years << " years," << prisoner[i].punishment_months << " months," 
                         << prisoner[i].punishment_days << " days.</td>\n" ;
                    file << "</tr>\n" ;
                    file << "</table>\n" ;
                    file << "</body>\n" ;
                    file << "</html>\n" ;
                    file.close() ;
                    cout << "\n\t\t\t\tPrisoner List saved in Prison.html file successfully!\n" ;
                    Sleep(2000);
                    return ;
                }
            }
            else{
                cout << "\n\t\t\t\tInvalid choice.\n" ;
                Sleep(1000);
                prison_file();
                return ;
            }
        }
};

int main(){
    system("cls");
    system("color A");
    Prison p ;
    // p.login();
    p.menu();
    return 0 ;
}