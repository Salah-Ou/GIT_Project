#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <iomanip>
#include <time.h>

using namespace std;

void Time(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "\n  ==) \033[1;37m Current date : " << asctime(ltm) << "\033[1;32m" ;
}

class Pharmacy {
    private : 
        struct customer {
            string name ;
            string date ;
            int quantity ;
            float price ;
            int id ;
            float total ;
            float total_price ;
            int selection ;
            string product_name ;
            float exact_amount ;
        };

        vector <customer> order ;

    public :

        void products(){
            system("cls");
            Time();
            cout << "\n\n\t\t\t\t\t\t  ADD ORDER DETAILS " ;
            cout << "\n\t\t\t**********************************************************************\n" ;
            cout << "\t\t\t|Product ID |  Product Type  |\t    Product Name    |\tPrice (DH)   |\n" ;
            cout << "\t\t\t**********************************************************************\n" ;
            cout << "\t\t\t|  1        |\t    OTC      |\tProbiotics          |\t 243.00 DH   |\n" ;
            cout << "\t\t\t|  2        |\t    OTC      |\tVitamin C(500mg)    |\t 90.92 DH    |\n" ;
            cout << "\t\t\t|  3        |\t    OTC      |\tAcid free C(500mg)  |\t 75.00 DH    |\n" ;
            cout << "\t\t\t|  4        |\t    OTC      |\tWomen's Multivate   |\t 139.00 DH   |\n" ;
            cout << "\t\t\t|  5        |\t    OTC      |\tMarino Tablet       |\t 20.95 DH    |\n" ;
            cout << "\t\t\t|  6        |\t    OTC      |\tMaxi Cal Tablet     |\t 270.97 DH   |\n" ;
            cout << "\t\t\t|  7        |\t    OTC      |\tAmino Zinc Tablet   | \t 150.28 DH   |\n" ;
            cout << "\t\t\t|  8        |\t    OTC      |\tIdol                |\t 20.00 DH    |\n" ;
            cout << "\t\t\t|  9        |\t    OTC      |\tFabulous            | \t 1300.00 DH  |\n" ;
            cout << "\t\t\t|  10       |  \t    OTC      |\tRoyal Propils       | \t 222.92 DH   |\n" ;
            cout << "\t\t\t**********************************************************************\n" ;  
        }
        void new_medcine(){
            products();
            customer c ;
            cout << "\n\t\t\t\t  Enter Type Order no : " ;
            cin >> c.id ;
            cout << "\n\t\t\t\t  Enter the customer name : " ;
            cin.ignore();
            getline(cin,c.name);
            cout << "\n\t\t\t\t  Enter the date : " ;
            cin >> c.date ;
            cout << "\n\t\t\t\t  Please Enter your selection : " ;
            cin >> c.selection ;
            cout << "\n\t\t\t\t  Medcine Name : " ;
            switch(c.selection){
                case 1 : c.product_name = "Probiotics.\n" ; c.price = 243.00 ; break ;
                case 2 : c.product_name = "Vitamin C(500mg).\n" ; c.price = 90.92 ; break ;
                case 3 : c.product_name = "Acid free C(500mg).\n" ; c.price = 75.00 ; break ;
                case 4 : c.product_name = "Women's Multivate.\n" ; c.price = 139.00 ; break ;
                case 5 : c.product_name = "Marino Tablet.\n" ; c.price = 20.95 ; break ;
                case 6 : c.product_name = "Maxi Cal Tablet.\n" ; c.price = 270.97 ; break ;
                case 7 : c.product_name = "Amino Zinc Tablet.\n" ; c.price = 150.28 ; break ;
                case 8 : c.product_name = "Idol.\n" ; c.price = 20.00 ; break ;
                case 9 : c.product_name = "Fabulous.\n" ; c.price = 1300.00 ; break ;
                case 10 : c.product_name = "Royal Propils.\n" ; c.price = 222.92 ; break ;
                default : cout << "\n\t\t\t\t\033[1;31m  Invalid Selection !! \033[1;32m\n" ; break ;
            }
            cout << c.product_name ;
            cout << "\n\t\t\t\t  How many medcine do you want : " ;
            cin >> c.quantity ;
            c.total = c.price * c.quantity ;
            cout << fixed << setprecision(2); // #include <iomanip> 
            cout << "\n\t\t\t\t  The amount you need to pay is : " << c.total << " DH" ; 
            order.push_back(c);
            cout << "\n\n\t\t\t\t\tOrder Taken Successfully!!!\n" ;
            cout << "\n\t\t\t\t  Press any key to go main menu...... " ;
            _getch();
        }

        void print_order(){
            system("cls");
            Time();
            int id ;
            cout << "\n\n\t\t\t\t Enter teh receipt number to print the receipt : " ;
            cin >> id ;
            for(int i = 0 ; i < order.size() ; i++){
                if(order[i].id == id){
                    system("cls");
                    cout << "\n\t\t\t\t------------------------------------\n\n" ;
                    cout << "\t\t\t\t  Receipt Number : " << id << "\n" ;
                    cout << "\t\t\t\t  Customer Name  : " << order[i].name << "\n" ;
                    cout << "\t\t\t\t  Date           : " << order[i].date << "\n" ;
                    cout << "\t\t\t\t  Product Name   : " << order[i].product_name << "\n" ;
                    cout << "\t\t\t\t  Quantity       : " << order[i].quantity << "\n" ;
                    cout << "\t\t\t\t  Price per unit : " << order[i].price << " DH\n" ;
                    cout << "\t\t\t\t  Total price    : " << fixed << setprecision(2);
                    cout << order[i].total << " DH\n" ;
                    cout << "\n\t\t\t\t------------------------------------\n" ;
                }
                pay : 
                cout << "\n\t\t\t  how many the exact amount you need to pay : " ;
                cin >> order[i].exact_amount ;
                if(order[i].exact_amount == order[i].total){
                    cout << "\n\t\t\t\t\t   Payment Successful!!\n" ;
                }
                else{
                    cout << "\n\t\t\t\t\t \033[1;31m  Payment Failed !! \033[1;32m\n" ;
                    cout << "\n\t\t\t\t\t   Press any key to Continue pay...... " ;
                    _getch();
                    cout << "\n" ;
                    goto pay ;
                }
            }
            cout << "\n\t\t\t\t Press any key to go main menu...... " ;
            _getch();
        }

        void display_order(){
            if (order.empty()){
                cout << "\n\t\t\t\t\033[1;31m  No Orders Available in The List.\033[1;32m\n" ;
                cout << "\n\t\t\t\t Press any key to go main menu...... " ;
                _getch();
                return ;
            }
            else{
                cout << "\n\t\t\t\t-----------------------------------------------\n" ;
                cout << "\t\t\t\t      ********* DISPLAY ALL ORDERS *********" ;
                cout << "\n\t\t\t\t-----------------------------------------------\n" ;
                for(int i = 0 ; i < order.size() ; i++){
                    cout << "\n\t\t\t\t-------------------------------------------\n\n" ;
                    cout << "\t\t\t\t     Receipt Number : " << order[i].id << "\n" ;
                    cout << "\t\t\t\t     Customer Name  : " << order[i].name << "\n" ;
                    cout << "\t\t\t\t     Date           : " << order[i].date << "\n" ;
                    cout << "\n\t\t\t\t-------------------------------------------\n" ;
                    cout << "\n\t\t\t**********************************************************************\n" ;
                    cout << "\t\t\t   |  Product Type |   Product Name   |  Quantity  | Price (DH)  |" ;
                    cout << "\n\t\t\t**********************************************************************\n" ;
                    cout << "\t\t\t   |      OTC      | " << "     " << order[i].name << "      " << " | " << "     " << order[i].quantity << "     " << "|  " << order[i].price << "DH  |\n" ;
                    cout << "\t\t\t**********************************************************************\n" ;
                    cout << "\n\t\t\t\t\t  Total Bill : " << fixed << setprecision(2);
                    cout << order[i].total << " DH\n" ;
                }
            }
            cout << "\n\t\t\t\t Press any key to go main menu...... " ;
            _getch();
        }

        void delete_order(){
            if (order.empty()){
                cout << "\n\t\t\t\t No Orders Available In the list...!!\n" ;
            }
            else{
                int id ;
                cout << "\n\t\t\t\t Enter the receipt number to delete : " ;
                cin >> id ;
                for(int i = 0 ; i < order.size() ; i++){
                    if (order[i].id == id){
                        order.erase(order.begin() + i);
                        cout << "\n\t\t\t\t Order Deleted Successfully!!!\n" ;
                        break ;
                    }
                    else {
                        cout << "\n\t\t\t\t\033[1;31m Order Not Found... !! \033[1;32m\n" ;
                    }
                }
            }
        }

        void modify_order(){
            system("cls");
            Time();
            if (order.empty()){
                cout << "\n\n\t\t\t\t\033[1;31m No Orders Available in the list... !! \033[1;32m\n" ;
            }
            else {
                int id ;
                cout << "\n\n\t\t\t\t Enter the receipt number to modify : " ;
                cin >> id ;
                for(int i = 0 ; i < order.size() ; i++){
                    if (order[i].id == id){
                        system("cls");
                        cout << "\n\t\t\t\t-------------------------------------------\n" ;
                        cout << "\t\t\t\t      ********* Modify Order *********" ;
                        cout << "\n\t\t\t\t-------------------------------------------\n" ;
                        cout << "\n\t\t\t\t Enter tne new receipt number : " ;
                        cin >> order[i].id ;
                        cout << "\n\t\t\t\t Enter new customer name : " ;
                        cin.ignore();
                        getline(cin, order[i].name);
                        cout << "\n\t\t\t\t Enter the new date : " ;
                        cin >> order[i].date ;
                        cout << "\n\t\t\t\t Enter the new selection : " ;
                        cin >> order[i].selection ;
                        cout << "\n\t\t\t\t  Enter The new Medcine Name : " ;
                        switch(order[i].selection){
                            case 1 : order[i].product_name = "Probiotics.\n" ; order[i].price = 243.00 ; break ;
                            case 2 : order[i].product_name = "Vitamin C(500mg).\n" ; order[i].price = 90.92 ; break ;
                            case 3 : order[i].product_name = "Acid free C(500mg).\n" ; order[i].price = 75.00 ; break ;
                            case 4 : order[i].product_name = "Women's Multivate.\n" ; order[i].price = 139.00 ; break ;
                            case 5 : order[i].product_name = "Marino Tablet.\n" ; order[i].price = 20.95 ; break ;
                            case 6 : order[i].product_name = "Maxi Cal Tablet.\n" ; order[i].price = 270.97 ; break ;
                            case 7 : order[i].product_name = "Amino Zinc Tablet.\n" ; order[i].price = 150.28 ; break ;
                            case 8 : order[i].product_name = "Idol.\n" ; order[i].price = 20.00 ; break ;
                            case 9 : order[i].product_name = "Fabulous.\n" ; order[i].price = 1300.00 ; break ;
                            case 10 :order[i].product_name = "Royal Propils.\n" ; order[i].price = 222.92 ; break ;
                            default : cout << "\n\t\t\t\t  Invalid Selection!!\n" ; break ;
                        }
                        cout << order[i].product_name ;
                        cout << "\n\t\t\t\t  How many medcine do you want : " ;
                        cin >> order[i].quantity ;
                        order[i].total = order[i].price * order[i].quantity ;
                        cout << fixed << setprecision(2); // #include <iomanip> 
                        cout << "\n\t\t\t\t  The amount you need to pay is : " << order[i].total << " DH" ; 
                        cout << "\n\t\t\t\tOrder Modified Successfully!!!\n" ;
                        cout << "\n\t\t\t  Press any key to go main menu...... " ;
                        _getch();
                    }
                    else {
                        cout << "\n\t\t\t\t\033[1;31m Order Not Found... !! \033[1;32m\n" ;
                    }
                }
            }
        }
};

int main(){
    Pharmacy py ;
    system("cls");
    system("color A");
    while(true){
        system("cls");
        Time();
        cout << "\n\t\t\t\t  Pharmacy Management System \n" ;
        cout << "\t\t\t  -----------------------------------------\n" ;
        cout << "\t\t\t    1. Take New medcine order.\n" ;
        cout << "\t\t\t    2. Delete Latest Medcine order.\n" ;
        cout << "\t\t\t    3. Modify Order List.\n" ;
        cout << "\t\t\t    4. Print The Receipt and make payment.\n" ;
        cout << "\t\t\t    5. Display All Orders.\n" ;
        cout << "\t\t\t    6. Exit.\n" ;
        cout << "\t\t\t  -----------------------------------------\n" ;
        cout << "\t\t\t    Enter your choice : ";
        int choice ;
        cin >> choice ;
        switch(choice){
            case 1 : py.new_medcine(); break ; 
            case 2 : py.delete_order(); break ;
            case 3 : py.modify_order(); break ;
            case 4 : py.print_order(); break ;
            case 5 : py.display_order(); break ;  
            case 6 : cout << "\n\t\t\t\t\tExiting Program...!\n" ; exit(0); break ;
            default : cout << "\n\t\t\t Invalid Choice!!\n" ; break ;
        }
    }
    return 0 ;
}