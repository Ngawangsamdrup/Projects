#include "userInfo.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// By :Annifa Ghanie && Mikel Lewis

userInfo::userInfo(string userName, string date) {  // Constructor to initialize user name and date
    this->userName = userName;
    this->date = date;
}

string userInfo::getUserName() const {   
    return userName;
}

string userInfo::getDate() const {
    return date;
}

void userInfo::addExinfo(exercise temp) {
    exList.push_back(temp);
}

// By: Alberto Santana && Ngawang Samdrup

void userInfo::removeEx(string exN) {
    bool found = false;
    for (int i = 0; i < exList.size(); i++) {
        if (exList.at(i).getExName() == exN) {
            found = true;
            exList.erase(exList.begin() + i);
            break;
        }
    }
    if (found == true) {  // Inform user whether the exercise was found and removed
        cout << endl;
        cout << "Exercise -" << exN << "- has been removed." << endl;
    }
    if (!found) {
        cout << endl;
        cout << "*Exercise not found or list is empty!" << endl;
    }
}
// By :Annifa Ghanie && Ngawang Samdrup

void userInfo::updateEx(string currentName, exercise temp) {    // Update an existing exercise with new details
    bool found = false;
    for (int i = 0; i < exList.size(); i++) {
        if (exList.at(i).getExName() == currentName) {
            found = true;
            if (!temp.getExName().empty()) {
                exList.at(i).setExName(temp.getExName());
            }
            if (temp.getExTime() != 0) {
                exList.at(i).setExTime(temp.getExTime());
            }
            if (temp.getExSets() != 0) {
                exList.at(i).setExSets(temp.getExSets());
            }
            if (temp.getExReps() != 0) {
                exList.at(i).setExReps(temp.getExReps());
            }
            if (temp.getExWeight() != 0) {
                exList.at(i).setExWeight(temp.getExWeight());
            }
        }
        if (found == true) {
            cout << endl;
            cout << "Exercise Info of -" << currentName << "- has been updated." << endl;
            break;
        }
    }
    if (!found) {
        cout << endl;
        cout << "*Exercise not found or list is empty!" << endl;
    }
}
// By: Alberto Santana && Mikel Lewis

void userInfo::aboveExTime(int t) {    // Display exercises where the time exceeds the given threshold
    for (int i = 0; i < exList.size(); i++) {
        if (exList.at(i).getExTime() > t) {
            cout << endl;
            cout << exList.at(i).getExTime() << " minutes. Name: " << exList.at(i).getExName() << endl;
        }
    }
}

void userInfo::maxTime() {    // Find and display the exercise with the maximum time
    if (exList.empty()) {
        cout << endl;
        cout << "*No exercises to check." << endl;
        return;
    }
    double max = exList.at(0).getExTime();
    int maxIndex = 0;
    for (int i = 1; i < exList.size(); i++) {
        if (exList.at(i).getExTime() > max) {
            max = exList.at(i).getExTime();
            maxIndex = i;
        }
    }
    cout << endl;
    cout << "Max exercise time: " << max << " minutes" << ". Exercise name: " << exList.at(maxIndex).getExName() << endl;
}
// By :Annifa Ghanie && Ngawang Samdrup

void userInfo::showL() {    // Display exercises in reverse order
    exercise temp;
    if (exList.empty()) {
        cout << endl;
        cout << "*Exercise list empty." << endl;
        return;
    }
    for (int i = 0; i < exList.size() / 2; i++) {     // Reverse the list of exercises in place
        temp = exList.at(i);
        exList.at(i) = exList.at(exList.size() - 1 - i);
        exList.at(exList.size() - 1 - i) = temp;
    }
    cout << endl;
    cout << "Exercises in reverse order:" << endl;
    for (int i = 0; i < exList.size(); i++) {
        cout << i + 1 << ". ";
        exList.at(i).exPrintInfo();
    }
}
// By: Alberto Santana && Mikel Lewis

void userInfo::findEx(string exN) {     // Find a specific exercise by name and display its information
    bool found = false;
    for (int i = 0; i < exList.size(); i++) {
        if (exList.at(i).getExName() == exN) {
            found = true;
            cout << endl;
            cout << "Sets: " << exList.at(i).getExSets() << ", Reps: " << exList.at(i).getExReps() << " (Exercise Name: " << exN << ")" << endl;
            break;
        }
    }
    if (!found) {
        cout << endl;
        cout << "*Exercise not found or list is empty!" << endl;
    }
}

void userInfo::outPut() const {
    cout << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "               FITNESS TRACKER                 " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "User name: " << userName << ", Date: " << date << endl;
    cout << "-----------------------------------------------" << endl;

    if (exList.empty()) {
        cout << endl;
        cout << "* No exercise data available! ***" << endl;
    } else {
        cout << endl;
        cout << "************* Exercise List *************" << endl;
        for (int i = 0; i < exList.size(); i++) {
            cout << "Exercise " << i + 1 << ": ";
            exList.at(i).exPrintInfo();
        }
    }

    cout << "-----------------------------------------------" << endl;

}
// By: Alberto Santana && Ngawang Samdrup

void userInfo::insert(exercise temp, int pos) {    // Insert a new exercise at a specific position in the list
    if (pos < 0 || pos > exList.size()) {
        cout << endl;
        cout << "*Error: Invalid position. Cannot insert exercise." << endl;
        return;
    }
    exList.insert(exList.begin() + pos, temp);
    cout << endl;
    cout << "Exercise: " << temp.getExName() << ". Inserted at position: " << pos << endl;
}

void userInfo::sort() {    // Sort the exercises alphabetically by name
    int min = 0;
    for (int i = 0; i < exList.size() - 1; i++) {
        min = i;
        for (int j = i + 1; j < exList.size(); j++) {
            if (exList.at(j).getExName() < exList.at(min).getExName()) {
                min = j;
            }
        }
        
            exercise temp = exList.at(i);        // Swap exercises to sort the list
            exList.at(i) = exList.at(min);
            exList.at(min) = temp;
      
    }
    cout << endl;
    cout << "Sorted Exercise Name:" << endl;
    for (int a = 0; a < exList.size(); a++) {
        cout << a + 1 << ". " << exList.at(a).getExName() << endl;
    }
}
// By :Annifa Ghanie && Mikel Lewis

void userInfo::printEx() const {
    for (int i = 0; i < exList.size(); i++) {
        cout << i + 1 << ". ";
        exList.at(i).exPrintInfo();
    }

}
// By :Annifa Ghanie && Ngawang Samdrup

void userInfo :: findBMI (){        // BMI calculation and guessing game
        double BMI = 0.0;
         double weight = 0.0;
          double height = 0.0;
          double guess = 0.0;
        int count = 0;
        cout << "Enter your weight (Kg): ";
        cin >> weight;
        cout << "Enter your height (Meter): ";
        cin >> height;

        BMI = weight /  (height * height);     // BMI formula
        BMI = static_cast <int> (BMI * 100) / 100.0;  // Round to two decimal places
        cout << BMI << " :(Testing)" << endl;  // For testing purposes

    
     while (count  < 3) {     // Allow the user three guesses to match their BMI
         cout << "Enter  your guess: " ;
          cin >> guess;
         if (guess == BMI) {
             cout << "Congratulations! Your  guess is correct." << endl;
             cout << "Your BMI is: " << BMI << endl;
             break;
         } else {
             count ++;
             if ( guess < BMI) {
                 cout << count << ". Guess completed!" << endl;
                 cout  << "Hint: your guess is too low." << endl;
             } else {
                 cout << count << ". Guess completed!" << endl;
                  cout  << "Hint: your guess is too high." << endl;
             }
         }
     }
        if (count == 3) {
            cout << "Used up all of  your  guesses!" << endl;
            cout << "Your BMI is: " << BMI  << endl;
        }
}

