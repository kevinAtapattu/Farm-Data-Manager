
#include <iostream>
#include <string>
#include <vector>
#include "Control.h"


const vector<string> Control::menu ={
    "Set province",
    "Sort by animal name",
    "Sort by number of farms",
    "Sort by number of animals",
    "Print all data",
    "Print current data"
};

// void sortByAnimalName();
// void sortByNumberOfFarms();
// void sortByNumberOfAnimals();
// void printAllData();
// void printCurrentData();

void Control::launch(){
    //make a view, get input, launch the appropriate test
    View view;
    int choice = -1;

    string province;
    while (choice!= 0){
        view.menu(menu, choice);
        switch(choice){
            case 1:
                view.getProvince(province);
                farmData.setProvince(province);
                break;
            case 2:
                farmData.sortByAnimalName();
                break;
            case 3:
                farmData.sortByNumberOfFarms();
                break;
            case 4:
                farmData.sortByNumberOfAnimals();
                break;
            case 5:
                farmData.printAllData();
                break;
            case 6:
                farmData.printCurrentData();
                break;
            case 0:
                cout<<"Goodbye!"<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }
}



