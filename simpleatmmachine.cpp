//Simple ATM Machine
#include <iostream>
#include <string>
using namespace std;

void validityChecker(int x,int y){
    if (x<0){
        throw "You have Entered a Negative value";
    }else if(x>y){
        throw "Invalid balance";
    };

    return;
};

void despoitLimit(int x){
    if (x>10000){
        throw "You can't deposit more than 10k at a time";
    };
};



class Bank{
    private:
        static int balance;//static variable
       
        int withdraw;
        int deposit;
    public:
    void withdrawfn(void){
        cout<<"Enter Amount:    \n";
        cin>>withdraw;   
        validityChecker(withdraw,balance);
        balance-=withdraw;
        return;
    };
    void depositfn(void){
        cout<<"Enter Amount:    \n";
        cin>>deposit;
        despoitLimit(deposit);
        balance+=deposit;
        return;
    }
    void checkBalance(void){
        cout<<"Your balance:     "<<balance<<endl;
        return;
    }

};
int r;
int Bank:: balance =10000;//giving value to a static variable balance
int main(){
    int userInput;
    Bank obj;
    do{
    cout<<"Check balance:       1\nWithdraw:            2\nDesposit:            3\n";
    cin>>userInput;
   try{ switch(userInput){
        case 1:
            obj.checkBalance();
            break;
        case 2:
            
            obj.withdrawfn();
            obj.checkBalance();
            break;
        case 3:
            obj.depositfn();
            obj.checkBalance();
            break;
        default:
            "Enter an valid Input";
    };}
    catch(const char * txtException){
        cout<<"Error:   "<<txtException<<endl;
    };
    cout<<"if you want to  continue Enter           0\n";
    cin>>r;
    }while(r==0);

    return 0;
    };




