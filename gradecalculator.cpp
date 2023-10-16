#include <iostream>
#include <string>
using namespace std;

//function overloading concept and Exception handling
void validityChecker(float x){
        if (x<0){
                throw "You can't Enter Negative value\n";
        }else if(x>10){
                throw "The total mark of assignment and quiz is 10, it not possible to get more than 10\n";

        };
        return;
};
void validityChecker(double x){
        if (x<0){
                throw "You can't Enter Negative value\n";
        }else if(x>100){
                throw "The total mark for exam is 100, it not possible to get more than 100\n";

        };

};

class Grade{
        //abstraction
        private:
                //management of data
                int totalAssignmentMark=10;
                int totalQuizMark=10;
                int totalExamMark=100;

                // student data
                float obtainedAssignmentMark;//I have used float datatype of 1st two variable and double for obtainedExamMark to use function overloading concept.
                float obtainedQuizMark;
                double obtainedExamMark;

        //encapsulation  
        public:
                // setData() -- to get data from the student 
                void setData(void){
                        cout<<"Enter your assignment mark\n";
                        cin>>obtainedAssignmentMark;
                        validityChecker(obtainedAssignmentMark);

                        cout<<"Enter your quiz mark"<<endl;
                        cin>>obtainedQuizMark;
                        validityChecker(obtainedQuizMark);
                        
                        cout<<"Enter your exam mark\n";
                        cin>>obtainedExamMark;
                        validityChecker(obtainedExamMark);

                        return;
                        };
                // gradeCalculator() --used to calculate the grade 
                void gradeCalculator(void){
                        double assignmentMark=obtainedAssignmentMark/totalAssignmentMark;
                        double quizMark=obtainedQuizMark/totalQuizMark;
                        double examMark=obtainedExamMark/totalExamMark;

                        //weightage of assignment --40% and weightage of quiz -- 30% and weightage of exam --30%
                        double grade=(assignmentMark*40)+(quizMark*30)+(examMark*30);

                        cout<<"You got "<<grade<<" out of "<<"100\n";
                        return;
                
                };
};

int main(){
        int count=0;
        Grade obj;
        try{
        obj.setData();}
        catch(const char * txtException){
                cout<<"Exception: "<<txtException;
                count=1;
                
        };
        
        if (count==0){
        obj.gradeCalculator();
        };
        return 0;
}