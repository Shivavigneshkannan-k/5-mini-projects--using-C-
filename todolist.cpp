#include<bits/stdc++.h>//I have used this instead of <iostream> 
//I have used "using std::objname" instead of "using namespace std;"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::ignore;
#include <string>
#include <vector>


class Todo{
        public:
            vector<string> toDoList;
            vector<string> completed;
            string newTask,updatedTask;
            int delTask,update;
            int option;
        //to display all task in the list 
        void displayTask(){
            cout<<endl<<"Task"<<endl;
            if(toDoList.size()==0){
                cout<<"No task\n";
            }
            else{
                for(int i=0;i<toDoList.size();i++){
                    cout<<i+1<<"."<<toDoList[i]<<endl;
                }
            }
            cout<<endl;
            return;
        };
        //to add new task 
        void addTask(void){
            int s=1;//to make the loop run again and again--to add task as much as user wants
            do{
            cout<<"Enter New Task:  ";
            cin.ignore();//without this piece of code getline() in the next line gets ignored hence you can't enter any value
            getline(cin,newTask);
            cin.clear();
            fflush(stdin);
            toDoList.push_back(newTask);
            cout<<endl<<"To add new task enter 0:      ";
            cin>>s;
             cin.clear();
            fflush(stdin);
            }while(s==0);
            return;
        };
        //to delete a task
        void deleteTask(void){
            displayTask();
            cout<<"Delete Task"<<endl;
            cout<<"Enter task number:   ";
            cin>>delTask;
             cin.clear();
            fflush(stdin);
            toDoList.erase(toDoList.begin()+delTask-1);
            return;
        };
        //to display the menu of the application
        void displayMenu(void){
            for (int i=0;i<=50;i++){
                cout<<"*";
            };
            cout<<endl;
            cout<<"\t\tYour To-Do List\n";
            for (int i=0;i<=50;i++){
                cout<<"*";
            };
            cout<<endl<<endl;
            cout<<"                       Enter\n\n";

            cout<<"View all task:          1\nAdd new task:           2\nDelete a task:          3\nUpdate a task:          4\nMark as completed:      5\nDelete all task:        6";

            cout<<endl<<endl;
            for (int i=0;i<=50;i++){
                cout<<"*";
            };
            };
        //to modify or change the existing task
        void updateTask(void){
            displayTask();
            cout<<"\nUpdate task\n";
            cout<<"Enter task number:       ";
            cin>>update;
             cin.clear();
            fflush(stdin);
            cout<<"Task"<<update<<":  "<<toDoList[update-1]<<endl;
            cout<<"Enter updated task:      ";
            cin.ignore();
            getline(cin,updatedTask);
             cin.clear();
            fflush(stdin);
            toDoList[update-1]=updatedTask;


            return;
        };
        //to delete all the task in the to do list
        void deleteAllTask(void){
            toDoList.clear();
            cout<<"All tasks are deleted";
            return;
        };
        // to mark a task as completed and show the completed tasks
        void completedTask(void){
            int comp;
            displayTask();
            cout<<"\nMark as Completed\n";
            cout<<"\nEnter task number:   ";
            cin>>comp;
             cin.clear();
            fflush(stdin);
            toDoList.erase(toDoList.begin()+comp-1);//toDoList.begin()-->refers to the address of first element in toDoList vector -- which is basically means toDoList[0].
            completed.push_back(toDoList[comp-1]);
            cout<<"Completed tasks\n";
            for(int i=0;i<completed.size();i++){
                cout<<i+1<<"."<<completed[i]<<endl;
                
            }
            return;
        }


};

int main(){
    Todo obj;
    int r=1;//to make the loop run again and again -- untill the user wants to stop
    do{
    obj.displayMenu();
    cout<<endl<<"Enter You choice:      ";
    cin>>obj.option;
    cin.clear();
    fflush(stdin);
    switch(obj.option){
        case 1:
            obj.displayTask();
            break;
        case 2:
            obj.addTask();
            break;
        case 3:
            obj.deleteTask();
            break;
        case 4:
            obj.updateTask();
            break;
        case 5:
            obj.completedTask();
            break;
        case 6:
            obj.deleteAllTask();
            break;
        default:
            break;}

    
    cout<<"\nBack:        0\nExit:         9\n";
    cin>>r;
    cin.clear();
    fflush(stdin);

    }while(r==0);

    return 0;
}