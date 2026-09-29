using namespace std;
#include <iostream>

// 
class User{
    private:
        unsigned int xp {};

    public:
        User(int xp){
            getXP();
        }

        User(){
            xp = 0;
        }

        void addXP(int n){
            if (n < 0){
                cerr << "Invalid, XP number." << endl;
            }else{
                xp += n;
            }
        }

        int getXP(){
            return xp;
        }

        void checkXP(){
         // pass for know   
        }
};

// 

int main(){
    User user(100);

    user.getXP();
}