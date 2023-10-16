#include <iostream>
#include <string>
using namespace std;

void validityChecker(int x){
    if (x<0 || x>100){
        throw "You have to guessed between 1 and 100";
    };
};

class Guess{
    private:
        int randomNum;
        int guessedNum;
        
    public:
        int r;//r is created to store the random value to run the loop without exposing the randomNum
        void set(void){
        r=randomNum;
        };
        int attempts=0;
        void randomNumgenerator(void){
            randomNum=rand()%100;
            return;
        };
        void guessing(void){
            cout<<"Enter your guess:    ";
            cin>>guessedNum;
            validityChecker(guessedNum);
            return;
        };
        void checker(){
            if(guessedNum==randomNum){ 
                cout<<"You have guessed it correctly\n";
                r=0;//if the answer is correct r is set to 0 and the loop will end,bcoz the condition to execute the loop is r is not equal to zero
            }
            else if(guessedNum<randomNum-10){
                cout<<"You have guessed too low\n";

            }else if(guessedNum>randomNum+10){
                cout<<"You have guessed too high\n";
            }else{
                cout<<"too close\n";
            }
            return;
        }
};

int main(){
    Guess obj;
    obj.set();
    obj.r=1;
    obj.randomNumgenerator();
    do{
        try{
        obj.guessing();}
        catch(const char * txtException){
            cout<<"Error:       "<<txtException<<endl;

        };
        obj.checker();
        obj.attempts+=1;
    }while(obj.r!=0 );
    cout<<"No of attempts:      "<<obj.attempts<<endl;

    return 0;
}