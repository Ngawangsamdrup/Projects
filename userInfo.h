#ifndef USERINFO_H
#define USERINFO_H
#include "exercise.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class userInfo {
public:
// Constructor to initialize user information with optional parameters
    userInfo(string userName = "none", string date = "none");
    void addExinfo(exercise temp);     // Adds an exercise to the list
    void removeEx(string exN);         // Removes an exercise by name
    void updateEx(string currentName,exercise temp);     // Updates an existing exercise
    void aboveExTime(int t);    // Filters exercises based on time
    void maxTime(); // Finds the exercise with the max time
    void showL(); // Displays all exercises
    void findEx(string exN); // Finds an exercise by name
    void insert (exercise temp, int pos); // Inserts an exercise at a specific position
    void sort(); // Sorts the exercises in the list
    void outPut() const; // Outputs user information and exercises
    void printEx () const; // Prints detailed exercise info
    string getUserName() const;
    string getDate() const;
    void findBMI (); // Calculates and displays BMI

private:
    string userName;
    string date;
    vector<exercise> exList; // List of exercises
};

#endif

 // By :Annifa Ghanie , Mikel Lewis ,Alberto Santana && Ngawang Samdrup.
