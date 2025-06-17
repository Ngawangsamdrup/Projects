#include <iostream>
#include <string>
#include "exercise.h"
#include "userInfo.h"
#include "menu.h"
#include <iomanip>
using namespace std;

int main() {
    string userName, date;
    cout << "Enter your Name: ";
    getline(cin, userName);
    cout << "Enter the date: ";
    cin >> date;
    userInfo tracker(userName, date);    // Initialize userInfo object with user name and date
    Menu trackerMenu;    // Initialize Menu object to display menu options
    cout << endl << "********** WELCOME TO FITNESS TRACKER **********" << endl;
    cout << "***********************************************" << endl;
    cout << "***********************************************" << endl;
    cout << tracker.getUserName() << "  DATE: " << tracker.getDate() << endl; // Display user information
    trackerMenu.printMenu(tracker); // Display the menu for the user

}
 // By :Annifa Ghanie , Mikel Lewis ,Alberto Santana && Ngawang Samdrup.
