#include <iostream>
#include <string>
#include "exercise.h"
#include "userInfo.h"

using namespace std;

class Menu {
// By :Annifa Ghanie && Mikel Lewis
public:
    void printMenu(userInfo &store);    // Displays the menu to the user
    void executeMenu(char choice, userInfo &store1);  // Executes the menu options based on user choice
};

void Menu::executeMenu(char choice, userInfo &store1) {
    string exName;
    double exTime;
    int exSets;
    int exReps;
    int exWeights;
    // By :Mikel Lewis &&   Ngawang Samdrup
    
    if (choice == 'a') {    // Option 'a' for adding exercise information
        int temp = 0;
        int pos = 0;
        while (true) {
            cout << endl;
            cout << "Choose the type of exercise you want to add:" << endl;
            cout << "1. Weightlifting exercise" << endl;
            cout << "2. Cardio exercise" << endl;
            cout << "3. Insert an Exercise at Any Position:" << endl;
            cout << "Enter your choice: ";
            cin >> temp;
            cout << endl;

            if (temp >= 1 && temp <= 3) { // Handle different cases for adding exercises
                if (temp == 3) {
                    cout << "Current Exercise List:" << endl;
                    cout << endl;
                    store1.printEx();
                    cout << "Enter the position to insert the exercise: ";
                    cin >> pos;

                    cout << "Enter the exercise Name: ";
                    cin.ignore();
                    getline(cin, exName);
                    cout << "Enter the exercise Time (minutes): ";
                    cin >> exTime;

                    cout << "Enter the exercise Sets: ";
                    cin >> exSets;
                    cout << "Enter the exercise Reps: ";
                    cin >> exReps;
                    cout << "Enter the exercise Weights (pounds): ";
                    cin >> exWeights;

                    exercise tempEx(exName, exTime, exSets, exReps, exWeights);  
                    store1.insert(tempEx, pos);  // Create an exercise object and insert it at the specified position
                    break;
                }

                cout << "Enter the number of exercises you want to log: "; // Logic for adding multiple exercises
                int q;
                cin >> q;

                for (int i = 0; i < q; i++) {
                    cout << i + 1 << ". Enter the exercise Name: ";
                    cin.ignore();
                    getline(cin, exName);
                    cout << "Enter the exercise Time (minutes): ";
                    cin >> exTime;

                    cout << "Enter the exercise Sets: ";
                    cin >> exSets;
                    cout << "Enter the exercise Reps: ";
                    cin >> exReps;

                    if (temp == 1) { // Add exercise to the appropriate category (1.Weightlifting or 2.Cardio)
                        cout << "Enter the exercise Weights (pounds): ";
                        cin >> exWeights;
                        store1.addExinfo(exercise(exName, exTime, exSets, exReps, exWeights));
                    } else if (temp == 2) {
                        store1.addExinfo(exercise(exName, exTime, exSets, exReps, 0));
                    }
                }

                break;
            } else {
                cout << "*Invalid input. Please enter 1 for Weightlifting, 2 for Cardio, or 3 to Insert an Exercise." << endl;
            }
        }
        // By: Alberto Santana &&  Annifa Ghanie
        
        // Other menu options follow similar structure
    } else if (choice == 'd') {
        cout << "REMOVE EXERCISE INFO:" << endl;
        cout << "Enter the exercise Name: ";
        getline(cin, exName);
        store1.removeEx(exName);
    } else if (choice == 'u') {
        int temp1;
        string Nex;
        while (true) {
             cout << endl;
            cout << "UPDATE YOUR EXERCISE INFO:" << endl;
            cout << "1. Exercise Name" << endl;
            cout << "2. Exercise Time" << endl;
            cout << "3. Exercise Sets and Reps" << endl;
            cout << "4. Weights Used" << endl;
            cout << "Choose the info you want to change: ";
            cin >> temp1;
            cout << endl;
            if (temp1 >= 1 && temp1 <= 4) { // Handle different updates based on the choice (Name, Time, Sets/Reps, Weights)
                if (temp1 == 1) {
                    cout << "UPDATE YOUR EXERCISE NAME INFO" << endl;
                    cout << "Enter the exercise Name: ";
                    cin.ignore();
                    getline(cin, exName);

                    cout << "Enter the New Exercise Name: ";
                    getline(cin, Nex);

                    exercise temp(Nex, 0, 0, 0, 0);
                    store1.updateEx(exName, temp);
                } else if (temp1 == 2) {
                    cout << "UPDATE YOUR EXERCISE TIME INFO" << endl;
                    cout << "Enter the exercise Name: ";
                    cin.ignore();
                    getline(cin, exName);

                    cout << "Enter the new exercise time (minutes): ";
                    cin >> exTime;

                    exercise temp(exName, exTime, 0, 0, 0);
                    store1.updateEx(exName, temp);
                } else if (temp1 == 3) {
                    cout << "UPDATE YOUR EXERCISE SETS AND REPS INFO" << endl;
                    cout << "Enter the exercise Name: ";
                    cin.ignore();
                    getline(cin, exName);

                    cout << "Enter the New Sets: ";
                    cin >> exSets;
                    cout << "Enter the New Reps: ";
                    cin >> exReps;
                    cin.ignore();

                    exercise temp(exName, 0, exSets, exReps, 0);
                    store1.updateEx(exName, temp);

                } else if (temp1 == 4) {
                     cout << endl;
                    cout << "UPDATE YOUR EXERCISE WEIGHTS INFO" << endl;
                    cout << "Enter the exercise Name: ";
                    cin.ignore();
                    getline(cin, exName);

                    cout << "Enter the exercise Weights: ";
                    cin >> exWeights;
                    exercise temp(exName, 0, 0, 0, exWeights);
                    store1.updateEx(exName, temp);
                }
                break;
            } else {
                cout << "*Invalid input. Please pick an option from 1-4" << endl;
            }
        }
        // By: Alberto Santana &&  Annifa Ghanie
        // Other options like 'm' for max duration, 't' for exercises above a time, and so on are implemented similarly
    } else if (choice == 'm') {
        cout << "MAX EXERCISE DURATION: " << endl;
        store1.maxTime();

        // By :Mikel Lewis &&   Ngawang Samdrup
    } else if (choice == 't') {
        cout << "ABOVE EXERCISE TIME:" << endl;
        cout << "Enter the time: ";
        cin >> exTime;
        cin.ignore();
        cout << "Exercises with time above " << exTime << " minutes:" << endl;
        store1.aboveExTime(exTime);

    } else if (choice == 's') {
        int temp2;
        while (true) {
            cout << endl;
            cout << "1. OUTPUT THE UPDATED EXERCISE INFO" << endl;
            cout << "2. OUTPUT THE EXERCISE NAME (SORTED)" << endl;
            cout << "Enter the option: ";
            cin >> temp2;
            cout << endl;
            
            if (temp2 == 1 || temp2 == 2) {
                if (temp2 == 1) {
                    store1.showL();
                }
                if (temp2 == 2) {
                    store1.sort();
                }
                break;
            } else {
                cout << "*Invalid input. Please enter 1 or 2" << endl;
            }
        }

    } else if (choice == 'f') {    // By :Mikel Lewis &&   Ngawang Samdrup
        cout << "FIND THE SETS AND REPS:" << endl;
        cout << "Enter the exercise Name: ";
        getline(cin, exName);
        store1.findEx(exName);
        
    } else if (choice == 'g') {    // By :Mikel Lewis &&   Ngawang Samdrup
        cout << endl;
        cout << "BMI is a measure of healthy weight for height. Calculated as: BMI = weight (kg) ÷ height² (m²)." << endl;
        cout << endl;

        double height = 0.0 ;
          double weight = 0.0 ;
          int temp;
          while (true) {
            cout << "1. Convert your height and weight meteric Units (Kg/meters)." << endl;
            cout << "2. Find your BMI." << endl;
            cout << "Enter your choice: ";
            cin >> temp;
             cout << endl;
            if (temp >= 1 && temp <= 2) {
              if (temp == 1) {
                 cout << "Enter your weight: ";
                 cin >> weight;
                  cout << "Enter your height: ";
                  cin >> height;
                  
                height = height * 0.3048;
                weight = weight * 0.453592;

                cout << endl;
                cout << "Weight (Pounds): " << weight << ".Height (Meter): " << height << endl;
                cout << endl;
                cout << "Find your BMI:2 or Quite:3 ";
                cin >> temp;

              } 
                if (temp == 2) {
                    store1.findBMI ();
                     break;
                } else if (temp == 3) {
                    break;
                }
            } else {
               cout << "*Invalid input. Please enter 1 or 2" << endl;
            }
          }


    } else if (choice == 'o') {
        cout << "ALL EXERCISE INFO:" << endl;
        store1.outPut();
    }
}

void Menu::printMenu(userInfo &store) {

    char option = '?';
    cout << endl;
    cout << "***********************************************" << endl;
    cout << "*************** FITNESS TRACKER ***************" << endl;
    cout << "***********************************************" << endl;
    cout << "a - Add Exercise Info" << endl;
    cout << "d - Remove Exercise Info" << endl;
    cout << "u - Update Exercise Info" << endl;
    cout << "m - Output Max Exercise Duration" << endl;
    cout << "t - Above Exercise Time" << endl;
    cout << "s - Output the Updated Exercise Info" << endl;
    cout << "f - Find the Sets and Reps" << endl;
    cout << "g - Guess your BMI" << endl;
    cout << "o - Output All Exercise Info" << endl;
    cout << "q - Quit" << endl;
    cout << "***********************************************" << endl << endl;


    while (option != 'q') {    // Loop for the user to select an option from the menu
        cout << "Enter your choice : ";
        cin >> option;
        cin.ignore();
         // Execute menu option if valid
        if (option == 'a' || option == 'd' || option == 'u' || option == 'm' || option == 't' || option == 's' || option == 'f' || option == 'g' || option == 'o' || option == 'q') {
            executeMenu(option, store); // Call the function to handle the selected option

            cout << "***********************************************" << endl;
            cout << "*************** FITNESS TRACKER ***************" << endl;
            cout << "***********************************************" << endl;
            cout << "a - Add Exercise Info" << endl;
            cout << "d - Remove Exercise Info" << endl;
            cout << "u - Update Exercise Info" << endl;
            cout << "m - Output Max Exercise Duration" << endl;
            cout << "t - Above Exercise Time" << endl;
            cout << "s - Output the Updated Exercise Info" << endl;
            cout << "f - Find the Sets and Reps" << endl;
            cout << "g - Guess your BMI" << endl;
            cout << "o - Output All Exercise Info" << endl;
            cout << "q - Quit" << endl;
            cout << "***********************************************" << endl << endl;
        }
    }
    cout << "Thank you for choosing Fitness Tracker!" << endl;
}
