#ifndef EXERCISE_H
#define EXERCISE_H

#include <iostream>
#include <string>
using namespace std;

class exercise {

public:
// Setter and getter functions to modify and access the private data members

    exercise(string exName = "None", double exTime = 0.0, int exSets = 0, int exReps = 0, int exWeight = 0);

// Setter and getter functions to modify and access the private data members

    void setExName(string n);
    void setExTime(double t);
    void setExSets(int s);
    void setExReps(int r);
    void setExWeight(int w);

    void exPrintInfo() const;

    string getExName() const;
    double getExTime() const;
    int getExSets() const;
    int getExReps() const;
    int getExWeight() const;

private:
// Private data members to store the properties of an exercise
    string exName;
    double exTime;
    int exSets;
    int exReps;
    int exWeight;
};

#endif

//  By  Annifa Ghanie and Mikel Lewis