#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;


class temp{
    private:
        double Ftemp;
        double Ctemp;
        
    public:

        void setData(void){
            cout<<"Enter temperature in Fahrenheit:     ";
            cin>>Ftemp;
            return;
        };
        void converter(void){
            Ctemp=(Ftemp-32)* 5/9;
            return;
        };
        void getData(void){
            cout<<"temperature in Celsius:      "<<Ctemp<< " deg C";
            return;
        };


};

int main(){
    temp obj;
    obj.setData();
    obj.converter();
    obj.getData();
    return 0;
}