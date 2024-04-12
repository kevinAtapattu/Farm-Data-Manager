#include <iostream>
using namespace std;
#include <string>
#include <vector>

#include "View.h"

void View::menu(const vector<string>& menu, int& choice)
{
  cout << endl;
  cout << "Please make a selection:"<< endl<<endl;
  for (int i = 0; i < menu.size(); ++i){
    cout<<"  ("<<i+1<<") "<<menu[i]<<endl;
  }
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > menu.size()) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::getProvince(string& id)
{
  //Note this data predates Nunavut (NU)  
  string provinces[13] = {"AB", "BC", "MB", "NB", "NL", "NS", "ON", "PE", "QC", "SK", "NT", "YT", "CAN"};
  cout << "Choose the number of the province you want to view, or choose CAN for aggregate data of all provinces: "<<endl;
  for (int i = 0; i < 13; i++){
    cout << "(" << i+1 << ") " << provinces[i] << endl;
  }
  int choice;
  cin >> choice;
  while (choice < 1 || choice > 13) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
  id = provinces[choice-1];
}


