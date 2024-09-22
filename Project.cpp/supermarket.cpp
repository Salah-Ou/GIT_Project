#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <string>
#include <conio.h>

using namespace std;

class Administrator {
    private : 
        struct Product {
            string name ;
            float price ;
            int discount ;
            float price_discount ;
            int id ;
        };
        vector <Product> product;
    
    public : 
        void add_product(){
            system("CLS");
            Product p;
            cout << "\n\t\t Enter Product ID : " ;
            cin >> p.id ;
            cout << "\t\t Enter Product Name : " ;
            cin.ignore();
            getline(cin,p.name);
            cout << "\t\t Enter Product Price : " ;
            cin >> p.price ;
            cout << "\t\t Enter Product Discount : " ;
            cin >> p.discount ;
            p.price_discount = p.price - (p.price * p.discount / 100);
            product.push_back(p);
            cout << "\n\t\t Product Added Successfully!\n";
            cout << "\n\t      Press any key to continue...... " ;
            _getch();
            save_product();
        }

        void save_product(){
            system("CLS");
            ofstream file("Product.txt", ios::out);
            if (!product.empty()){
                file << "ID" << "\t   " << "Product Name" << "\t     " 
                    << "Price" << "\t   " << "Discount of Product" << "\t    " << 
                    "Price Of Discount" << endl ;
                for(const auto& p : product){
                    file << "----------------------------------------------------------------------------------\n" ;
                    file << p.id << "\t    " << p.name << "\t     " << p.price 
                        << " DH" << "   \t\t   " << p.discount << "%" << "    \t\t\t     " << p.price_discount << " DH" ; 
                    file << endl ;
                    file << "----------------------------------------------------------------------------------\n" ;
                }
                file.close();
            } else {
                file << "\n\t\t    No Product to Save...\n" ;
                file.close();
            }
        }

        void modify_product(){
            system("CLS");
            if (product.empty()){
                cout << "\n\t\t No Products Available!\n";
            } else {
                int id;
                cout << "\n\t\t Enter Product ID to Modify : " ;
                cin >> id ;
                for(auto& p : product){
                    if (p.id == id){
                        cout << "\n\t\t Enter New Product ID : " ;
                        cin >> p.id ;
                        cout << "\t\t Enter New Product Name : " ;
                        cin.ignore();
                        getline(cin,p.name);
                        cout << "\t\t Enter New Product Price : " ;
                        cin >> p.price ;
                        cout << "\t\t Enter New Product Discount : " ;
                        cin >> p.discount ;
                        p.price_discount = p.price - (p.price * p.discount / 100);
                        cout << "\n\t\t Product Modified Successfully!\n";
                        cout << "\n\t      Press any key to continue...... " ;
                        _getch();
                        save_product();
                    }
                }
                cout << "\n\t\t Product Not Found!\n";
            }
        }

        void delete_product(){
            system("CLS");
            if (product.empty()){
                cout << "\n\t\t No Products Available!\n";
            } else {
                int id ;
                cout << "\t\t Enter Product ID To Delete : " ;
                cin >> id ;
                for(int i = 0 ; i < product.size() ; i++){
                    if (product[i].id == id){
                        product.erase(product.begin() + i);
                        cout << "\n\t\t Product Deleted Successfully!\n";
                        cout << "\n\t      Press any key to continue...... " ;
                        _getch();
                        save_product();
                    }
                }
                cout << "\n\t\t Product Not Found!\n";
            }
        }

        void display_products(){
            system("CLS");
            if (product.empty()){
                cout << "\n\t\t No Products Available!\n";
            } else {
                cout << "\t\t ID" << "\t   " << "Product Name" << "\t     " 
                     << "Price" << "\t   " << "Discount of Product" << "\t    " << 
                     "Price Of Discount" << endl ;
                for(const auto& p : product){
                    cout << "\t\t--------------------------------------------------------------------------------------\n" ;
                    cout << "\t\t " << p.id << "\t    " << p.name << "\t     " << p.price 
                         << " DH" << "   \t\t   " << p.discount << "%" << "    \t\t " << p.price_discount << " DH" ; 
                    cout << endl ;
                    cout << "\t\t--------------------------------------------------------------------------------------\n" ;
                }
                cout << "\n\t\t\t\t\t Press any key to continue...... " ;
                _getch();
            }
        }

        float get_product_price(int id) {
            for (auto& p : product) {
                if (p.id == id) {
                    return p.price_discount;
                }
            }
            return -1;  // Indicates product not found
        }

        // Method to get product name by ID
        string get_product_name(int id) {
            for (const auto& p : product) {
                if (p.id == id) {
                    return p.name;
                }
            }
            return "Product Not Found";  // Indicates product not found
        }
};


class Buyer {
    private :
        struct Buy {
            int id ;
            int quantity ;
            float amount ;
        };
        vector<Buy> buy;
    
    public : 
        void receipt(Administrator& admin) {
            system("CLS");
            if (buy.empty()) {
                cout << "\n\t\t No Products Bought!\n";
                return;
            }

            float total_amount = 0;
            cout << "\n\t\t\t\t\t\t      Receipt\n";
            cout << "\t\t\t\t\t\t..................\n\n" ;
            cout << "\t\t ID" << "\t   " << "Product Name" << "\t     " 
            << "Quantity" << "  \t      " << "Price" << "  \t\t    " 
            << "Amount" << endl ;
            for (auto& b : buy) {
                float price = admin.get_product_price(b.id);
                string product_name = admin.get_product_name(b.id);  // Get product name
                if (price != -1) {
                    b.amount = price * b.quantity;
                    total_amount += b.amount;
                    cout << "\t\t--------------------------------------------------------------------------------------\n";
                    cout << "\t\t " << b.id << "\t    " << product_name << "\t\t " << b.quantity 
                    << " \t    " << price << " DH" << " \t\t   " << b.amount << " DH" ; 
                    cout << endl;
                    cout << "\t\t--------------------------------------------------------------------------------------\n";
                }
            }
            cout << "\n\t\t\t\t----------------------------" ;
            cout << "\n\t\t\t\t Total Amount : " << total_amount << " DH\n";
            cout << "\t\t\t\t----------------------------\n";
            buy.clear();
            cout << "\n\t\t\t\t\t Press any key to continue...... " ;
            _getch();
        }

        void buy_product(Administrator& admin){
            system("CLS");
            admin.display_products();
            Buy b;
            char continue_shopping = 'Y';
            do {
                cout << "\n\n\t\t  Enter Product ID to Buy : " ;
                cin >> b.id ;
                if (admin.get_product_price(b.id) == -1) {
                    cout << "\n\t\t\t\033[1;31m  Product Not Found!\n";
                }
                else{
                    cout << "\n\t\t Enter Product Quantity : " ;
                    cin >> b.quantity ;
                    buy.push_back(b);
                    cout << "\n\t\t Do you want to continue shopping (Y/N) : ";
                    cin >> continue_shopping ;
                }
            } while(continue_shopping == 'Y' || continue_shopping == 'y');
            receipt(admin);
            cout << "\n\t\t Thank you for shopping with us! Have a great day!\n";
            _getch();
        }
};


int main(){
    system("cls");
    system("color A");
    int choice;
    Administrator a;
    Buyer b;
    cout << "\n\t\t -----------------------------------------\n";
    cout << "\t\t|          SuperMarket Mini Menu          |\n";
    cout << "\t\t -----------------------------------------\n";
    while (true){
        // system("cls");
        SuperMarket :
        cout << "\t\t      1. Administrator.\n";
        cout << "\t\t      2. Buyer.\n";
        cout << "\t\t      3. Exit.\n";
        cout << "\t\t -----------------------------------------\n";
        cout << "\t\t      Enter your choice: ";
        cin >> choice;
        if (choice == 1){
            while(true){
                system("CLS");
                cout << "\n\t\t    Administrator Menu  \n";
                cout << "\t\t --------------------------------\n";
                cout << "\t\t      1. Add Product.\n";
                cout << "\t\t      2. Modify Product.\n";
                cout << "\t\t      3. Delete Product.\n";
                cout << "\t\t      4. Display Products.\n";
                cout << "\t\t      5. Back.\n";
                cout << "\t\t --------------------------------\n";
                cout << "\t\t      Enter your choice: ";
                cin >> choice;
                switch(choice){
                    case 1 : a.add_product(); break ;
                    case 2 : a.modify_product(); break ;
                    case 3 : a.delete_product(); break ;
                    case 4 : a.display_products(); break ;
                    case 5 : cout << "\n\t\t Go to SuperMarket Mini Menu....\n\n" ; 
                        _getch(); goto SuperMarket ;
                    default : cout << "Invalid choice.\n"; break ;
                }
            }
        }
        else if (choice == 2){
            while(true){
                cout << "\n\t\t    Buyer Menu  \n";
                cout << "\t\t --------------------------------\n";
                cout << "\t\t      1. Buy Product.\n";
                cout << "\t\t      2. Back.\n";
                cout << "\t\t --------------------------------\n";
                cout << "\t\t      Enter your choice: ";
                cin >> choice;
                switch(choice){
                    case 1 : b.buy_product(a); break ;
                    case 2 : cout << "\n\t\t Go to SuperMarket Mini...\n\n" ; exit(0); break ;
                    default : cout << "Invalid choice.\n"; break ;
                }
            }
        }
        else if (choice == 3){
            system("cls");
            cout << "\n\t\t Thank you for using SuperMarket Mini...\n\n";
            exit(0);
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
    return 0 ;
}
