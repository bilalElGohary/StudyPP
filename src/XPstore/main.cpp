using namespace std;
#include <iostream>
#include <algorithm>

// 
class User{
    private:
        unsigned int xp {};

    public:
        User(int xp){
            addXP(xp);
        }

        User(){
            xp = 0;
        }

        void addXP(int xp){
            if (xp < 0){
                cerr << "Invalid, XP number." << endl;
            }else{
                xp += xp;
            }
        }

        int getXP(){
            return xp;
        }

        void checkXP(){
         // pass for know   
        }
};

class Product{
    private:
        string prodname;
        int prodprice;

    public:
        Product(string name, int price){
            setProdName(name);
            setProdPrice(price);
        }
        Product(){
            prodname = "-";
            prodprice = 0;
        }

        void setProdName(string name){
            name.erase(remove_if(name.begin(), name.end(), ::isdigit), name.end());
            prodname = name; 
        }

        string getProdName(){
            return prodname;
        }

        void setProdPrice(int price){
            prodprice = price;
        }

        int getProdPrice(){
            return prodprice;
        }

        void getProdInfo(){
            cout << "Product Name: " << getProdName() << endl;
            cout << "Product Price: " << getProdPrice() << "$" << endl;
        }
};
// 

int main(){
    Product coffe("coffee", 100);

    coffe.getProdInfo();
}