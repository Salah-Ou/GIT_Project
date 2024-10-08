#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <time.h>
#include <vector>
#include <iomanip>

using namespace std;

int gotoxy(int x , int y){
    COORD c ;
    c.X = x ;
    c.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return 0 ;
}

string Time();

string Time(){
    time_t now = time(NULL);
    tm *local = localtime(&now);
    return asctime(local);
}

class ALSA {
    private : 
        struct Student {
            string name , surnames , CNI ;
            string school_level , etablish ;
            string phone_no ;
            string dt_of_birth ;
            string gender ;
            string province , city , adress ;
            string email ;
            string agency , date ;
            string time = {"07:00 am - 16:00 pm"};
        };
        vector <Student> students ;
        struct Shop {
            string card_start_date , card_end_date ;
            float card_price , recharge_price , total ;
        };
        vector <Shop> shops ;
    public : 
        void about_us(); 
        void student_card();
        void shop_card();
        void receipt_card();
};

void ALSA::about_us(){
    system("cls");
    gotoxy(55,0);
    string current_time = Time();
    cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m" ;  
    gotoxy(40,3);
    cout << "\033[1;34m** \033[1;7;34m OUR MISSION \033[0m" ;
    gotoxy(40,5);
    cout << "\033[1;37m   Our mission at \033[1;34mALSA City Agadir\033[0m\033[1;37m is to transport our customers safely" ;
    gotoxy(40,7);
    cout << "with a high quality of service. Since September 1,2010, we have started" ;
    gotoxy(40,9);
    cout << "the delegated management of public transport in the greater Agadir. By";
    gotoxy(40,11);
    cout << "applying our experience in the field of transport, we have assisted and";
    gotoxy(40,13); 
    cout << "collaborated in the development of the entire region by moving citizens" ;
    gotoxy(40,15);
    cout << "to their destinations through a network that consists of 40 lines with" ;
    gotoxy(40,17);
    cout << "a fleet of 201 buses and a staff of 640 employees, traveling an average " ;
    gotoxy(40,19);
    cout << "of 50,000 km every day.\033[0m" ;
    
    gotoxy(40,24);
    cout << "\033[1;34m** \033[1;7;34m OUR SERVICES \033[0m" ;
    gotoxy(40,26);
    cout << "\033[1;37m   Regarding our services, we offer a wide network that extends over \033[1;32m60 " ;
    gotoxy(40,28);
    cout << "kilometers \033[0m\033[1;37mfrom the North to Tamri, \033[1;32m50km\033[0m\033[1;37m to the East to Ouled Teima and" ;
    gotoxy(40,30);
    cout << "to the South, up to \033[1;32mMassa 67km (Agadir-Inezgane +40km)." ;
    gotoxy(40,32);
    cout << "\033[0m\033[1;37m \033[1;34m  ALSA City Agadir\033[0m\033[1;37m also offers you student cards and Ikhlas cards to " ;
    gotoxy(40,34);
    cout << "facilitate your travel with a reduced price. It also offers free travel " ;
    gotoxy(40,36);
    cout << "to children under 6 years old." ;
   
    gotoxy(40,40);
    cout << "\033[1;34m** \033[1;7;34m OUR ENVIRONMENT \033[0m" ;
    gotoxy(40,42);
    cout << "\033[1;37m   As pollution has an impact on our daily lives, and transport contr- " ;
    gotoxy(40,44);
    cout << "-ibutes significantly to it, we have trained our drivers in economical, " ;
    gotoxy(40,46);
    cout << "efficient and non-polluting driving. This demonstrates our involvement " ;
    gotoxy(40,48);
    cout << "in reducing the amount of CO2 emitted in the Greater Agadir region. Soft- " ;
    gotoxy(40,50); 
    cout << "-ware that intervenes on the driver's behavior and emphasizes economical " ;
    gotoxy(40,52);
    cout << "driving is also implemented. At \033[1;34mALSA\033[0m\033[1;37m, we are committed to sustainable" ;
    gotoxy(40,54);
    cout << "development." ;
    gotoxy(57,57);
    cout << "\033[1;34m" ;
    system("pause");
    cout << "\033[0m" ;
    return ;
}

void ALSA::student_card(){
    system("cls");
    gotoxy(50,0);
    string current_time = Time();
    cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m" ;  
    Student new_student ;
    gotoxy(18,1);
    cout << "\033[1;7;34m Card Request\033[0m\033[1;37m" ;
    gotoxy(18,3);
    cout << "\033[1;32mFields With \033[1;31m(*)\033[1;32m are required \033[1;37m" ;
    gotoxy(18,5);
    cout << "\033[1;37mSchool Level : Primaire / College / Lycee / University / OFPPT " ;
    gotoxy(18,7);
    cout << "   \033[1;31m(*) \033[1;34mSelcet option : " ;
    cin >> new_student.school_level ;
    gotoxy(18,9);
    cout << "\033[1;37mEstablishment : ENAA / ENSA / FSA / ENCG / EST / BTS / FS Lettres / FS Economie / Another Establishment " ;
    gotoxy(18,11);
    cout << "   \033[1;31m(*) \033[1;34mSelcet option : " ;
    cin >> new_student.etablish ;
    if (new_student.etablish == "another"){
        gotoxy(18,13);
        cout << "\033[1;31m(*) \033[1;34mAnother Establishment : " ;
        cin >> new_student.etablish ;
    }
    gotoxy(18,13);
    cout << "\033[1;31m(*) \033[1;37m Name : " ;
    cin >> new_student.name ;
    gotoxy(18,15);
    cout << "\033[1;31m(*) \033[1;37m Surnames : " ;
    cin >> new_student.surnames ;
    gotoxy(18,17);
    cout << "\033[1;31m(*) \033[1;37m Phone number : " ;
    cin >> new_student.phone_no ;
    gotoxy(18,19);
    cout << "\033[1;31m(*) \033[1;37m Email : " ;
    cin >> new_student.email ;
    gotoxy(18,21);
    cout << "\033[1;31m(*) \033[1;37m Date of Birth : " ;
    cin >> new_student.dt_of_birth ;
    gotoxy(18,23);
    cout << "\033[1;31m(*) \033[1;37m CNI : " ;
    char ch ;
    new_student.CNI.clear();
    for(int i = 0 ; i < 8 ; i++){
        ch = _getch();
        if (ch == 13) break ;
        new_student.CNI += ch ;
        cout << "*" ;
    }
    gotoxy(18,25);
    cout << "\033[1;7;34m To Ask For A Date \033[0m\033[1;37m" ;
    gotoxy(18,27);
    cout << "\033[1;32mFields With \033[1;31m(*)\033[1;32m are required\033[1;37m" ;
    gotoxy(18,29);
    cout << "WILAYA VALLEE / PLACE SALAM D\'AGADIR / PLACE MASSIRA D\'INZGANE" ;
    gotoxy(18,31);
    cout << "   \033[1;31m(*) \033[1;34mAgency : " ;
    cin.ignore();
    getline(cin,new_student.date);
    gotoxy(18,33);
    cout << "\033[1;31m(*) \033[1;37m ( If you can go today, write today ) \033[1;34mOR\033[0m\033[1;37m Select Date : " ;
    cin >> new_student.date ;
    if (new_student.date == "today" || new_student.date == "TODAY"){
        gotoxy(18,35);
        string current_time = Time();
        cout << "\033[1;31m(*) \033[1;37m Current Time's : \033[1;30m" << current_time << "\033[1;37m" ;    
        gotoxy(18,37);
        cout << "\033[1;31m(*) \033[1;37m Schedule : \033[1;30m" << new_student.time << "\033[1;37m" ;
    }
    students.push_back(new_student);
    gotoxy(25,40);
    cout << "\033[1;34m" ;
    system("pause");
    cout << "\033[0m" ;
}

void ALSA::shop_card(){
    system("cls");
    gotoxy(50,0);
    string current_time = Time();
    cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m" ;  
    if (students.empty()){
        gotoxy(25,5);
        cout << "\033[1;30mNo Student Found In The List !" ;
        gotoxy(27,9);
        cout << "\033[1;31mPlease Add A Student First" ;
        gotoxy(25,11);
        system("pause");
    }
    else{
        gotoxy(18,1);
        cout << "\033[1;7;34m Shopping Card\033[0m\033[1;37m" ;
        gotoxy(18,3);
        cout << "\033[1;32mFields With \033[1;31m(*)\033[1;32m are required \033[1;37m" ;
        string name , cni ;
        Shop new_shop ;
        gotoxy(18,5);
        cout << "\033[1;31m(*) \033[1;37mPlease Enter your name : \033[1;34m" ;
        cin.ignore();
        getline(cin,name);
        gotoxy(18,7);
        cout << "\033[1;31m(*) \033[1;37mPlease Enter your CNI : \033[1;34m" ;
        char ch ;
        cni.clear();
        for(int i = 0 ; i < 8 ; i++){
            ch = _getch();
            if (ch == 13) break ;
            cni += ch ;
            cout << "*" ;
        }
        int found = 0 ;
        for(int i = 0 ; i < students.size() ; i++){
            if (name == students[i].name && cni == students[i].CNI){
                found = 1 ;
                gotoxy(27,9);
                cout << "\033[1;32m Keep Shopping ...\033[1;37m" ;
                gotoxy(18,11);
                cout << "\033[1;31m(*) \033[1;37mCard Start Date : " ;
                cin >> new_shop.card_start_date ;
                gotoxy(18,13);
                cout << "\033[1;31m(*) \033[1;37mCard End Date : " ;
                cin >> new_shop.card_end_date ;
                gotoxy(18,15);
                cout << "\033[1;31m(*) \033[1;37mCard Price : " ;
                cin >> new_shop.card_price ;
                gotoxy(18,17);
                cout << "\033[1;31m(*) \033[1;37mRecharge Price : " ;
                cin >> new_shop.recharge_price ;
                gotoxy(18,19);
                cout << "\033[1;31m(*) \033[1;37mTotal Price : " ;
                new_shop.total = new_shop.card_price + new_shop.recharge_price ;
                cout << fixed << setprecision(2) << new_shop.total << " DH" ;
                shops.push_back(new_shop);
                gotoxy(23,22);
                cout << "\033[1;32mYou Have Successfully Shopped. " ;
                gotoxy(23,24);
                cout << "Thank You For Shopping With Us.\033[1;37m" ;
                gotoxy(22,26);
                cout << "\033[1;34m" ;
                system("pause");
                cout << "\033[0m" ;
                break ;
            }
            else if (i == students.size() - 1){
                gotoxy(27,9);
                cout << "\033[1;31mStudent Not Found In The List !" ;
                gotoxy(25,11);
                system("pause");
            }
        }
    }
}

void ALSA::receipt_card(){
    system("cls");
    gotoxy(50,0);
    string current_time = Time();
    cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m" ;  
    if (!students.empty()){
        string name , cni ;
        gotoxy(18,1);
        cout << "\033[1;7;34m Receipt Card\033[0m\033[1;37m" ;
        gotoxy(18,3);
        cout << "\033[1;32mFields With \033[1;31m(*)\033[1;32m are required \033[1;37m" ;
        gotoxy(18,5);
        cout << "\033[1;31m(*) \033[1;37mPlease Enter your name : \033[1;34m" ;
        cin.ignore();
        getline(cin,name);
        gotoxy(18,7);
        cout << "\033[1;31m(*) \033[1;37mPlease Enter your CNI : \033[1;34m" ;
        char ch ;
        cni.clear();
        for(int i = 0 ; i < 8 ; i++){
            ch = _getch();
            if (ch == 13) break ;
            cni += ch ;
            cout << "*" ;
        }
        for(int i = 0 ; i < students.size() ; i++){
            if (students[i].name == name && students[i].CNI == cni){
                gotoxy(27,9);
                cout << "\033[1;32m Keep Receiving... \033[1;37m" ;
                for(int i = 5 ; i >= 0 ; i--){
                    cout << "\r" ;
                    gotoxy(23,11);
                    cout << "Please Wait ... " << i << " Seconds." ;
                    Sleep(1000);
                }
                system("cls");
                gotoxy(50,0);
                string current_time = Time();
                cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m" ;  
                gotoxy(21,3);
                cout << "\033[1;7;34m A . L . S . A \033[0m" ;
                gotoxy(18,4);
                cout << "\033[1;37mALSA CITY AGADIR S.A." ;
                gotoxy(18,6);
                char numbers[] = "123456789" ;
                char random_number[5] ;
                cout << "\033[1;34mPayment Number  :    \033[0m\033[1;37mAA" ;
                for(int i = 0 ; i < 5 ; i++){
                    random_number[i] = numbers[rand() % 10] ;
                    cout << random_number[i] ;
                }
                gotoxy(18,8);
                cout << "\033[1;34mPayment Number  :    \033[0m\033[1;37mAA" ;
                for(int i = 0 ; i < 5 ; i++){
                    random_number[i] = numbers[rand() % 10] ;
                    cout << random_number[i] ;
                }
                for(int j = 0 ; j < shops.size() ; j++){
                    gotoxy(18,10);
                    cout << "\033[1;34mCard Type       :    \033[0m\033[1;37mNormal" ;
                    gotoxy(18,12);
                    cout << "\033[1;34mRecharge        :    \033[0m\033[1;37mE-Recharge Month" ;
                    gotoxy(18,14);
                    cout << "\033[1;34mCard Start Date :    \033[0m\033[1;32m" << shops[i].card_start_date << "   00:00:00 \033[0m" ;
                    gotoxy(18,16);
                    cout << "\033[1;34mCard End Date   :    \033[0m\033[1;31m" << shops[i].card_end_date << "   23:59:59 \033[0m" ;
                    gotoxy(18,19);
                    cout << fixed << "\033[1;34mCard Price      :    \033[0m\033[1;37m" << setprecision(2) << shops[i].card_price << " DH" ;
                    gotoxy(18,21);
                    cout << fixed << "\033[1;34mRecharge Price  :    \033[0m\033[1;37m" << setprecision(2) << shops[i].recharge_price << " DH" ;
                    gotoxy(18,23);
                    cout << fixed << "\033[1;34mTotal Price     :    \033[0m\033[1;37m" << setprecision(2) << shops[i].total << " DH" ;
                    gotoxy(23,26);
                    cout << "\033[1;32mThank You For Shopping With Us.\033[1;37m" ;
                    time_t now = time(0);
                    tm *tm = localtime(&now);
                    gotoxy(27,30);
                    cout << "\033[1;7;34m " ;
                    cout << ((tm -> tm_mday < 10) ? "0" : "") << tm -> tm_mday << "/" << ((tm -> tm_mon < 10) ? "" : "0") << tm -> tm_mon + 1 << "/" << tm -> tm_year + 1900
                    << "  " << tm -> tm_hour << ":" << ((tm -> tm_min < 10) ? "0" : "") << tm -> tm_min << ":" << ((tm -> tm_sec < 10) ? "0" : "")
                    << tm -> tm_sec << " \033[0m\033[1;37m" ;
                    gotoxy(22,33);
                    cout << "\033[1;34m" ;
                    system("pause");
                    cout << "\033[0m" ;
                }
            }
            else{
                gotoxy(24,10);
                cout << "\033[1;31mStudent Not Found ....!" ;
                gotoxy(27,12);
                cout << "Please Try Again" ;
                gotoxy(21,14);
                system("pause");
            }
        }
    }
    else{
        system("cls");
        gotoxy(25,5);
        cout << "\033[1;30mNo Student Found In The List !" ;
        gotoxy(25,9);
        system("pause");
    }
}

int main(){
    ALSA bus ;
    int option ;
    system("cls");
    while(true){
        system("cls");
        gotoxy(50,0);
        string current_time = Time();
        cout << "\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m" ;  
        gotoxy(18,1);
        cout << "\033[1;7;34m ALSA \033[0m\033[3;7;34mMaroc \033[0m " ;
        gotoxy(18,2);
        cout << "\033[37mWelcome To ALSA Agadir\n\033[0m" ; 
        gotoxy(12,4);
        cout << "\033[1;36m---------------------------------\n" ;
        gotoxy(16,6);
        cout << "\033[1;36m1. \033[1;37mAbout Us.\n" ;
        gotoxy(16,8);
        cout << "\033[1;36m2. \033[1;37mStudent Card.\n" ;
        gotoxy(16,10);
        cout << "\033[1;36m3. \033[1;37mShopping Cart.\n" ;
        gotoxy(16,12);
        cout << "\033[1;36m4. \033[1;37mReceipt Card.\n" ;
        gotoxy(16,14);
        cout << "\033[1;36m5. \033[1;37mExit.\n" ;
        gotoxy(12,16);
        cout << "\033[1;36m---------------------------------\n" ;
        gotoxy(15,18);
        cout << "Select Option : " ;
        cin >> option ;
        cout << "\033[0m" ;
        switch(option){
            case 1 : bus.about_us(); break ;
            case 2 : bus.student_card(); break ;
            case 3 : bus.shop_card(); break ;
            case 4 : bus.receipt_card(); break ;
            case 5 : gotoxy(20,21); cout << "\033[1;36mExit ALSA System...\n\n\033[0m" ; 
                exit(0); break ;
            default : gotoxy(20,21); cout << "\033[1;31mInvalid Option !!\n\n\033[0m" ; 
                gotoxy(14,23); system("pause"); break ;
        }
    }
    return 0 ;
}