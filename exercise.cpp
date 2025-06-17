#include "exercise.h"
#include <iostream>
#include <string>
using namespace std;
// Constructor initializes the exercise object with provided values or defaults

exercise::exercise(string exName, double exTime, int exSets, int exReps, int exWeight) {
    this->exName = exName;
    this->exTime = exTime;
    this->exSets = exSets;
    this->exReps = exReps;
    this->exWeight = exWeight;
}

void exercise::setExName(string n) {
    this->exName = n;
}

void exercise::setExTime(double t) {
    this->exTime = t;
}

void exercise::setExSets(int s) {
    this->exSets = s;
}

void exercise::setExReps(int r) {
    this->exReps = r;
}

void exercise::setExWeight(int w) {
    this->exWeight = w;
}

string exercise::getExName() const {
    return this->exName;
}

double exercise::getExTime() const {
    return this->exTime;
}

int exercise::getExSets() const {
    return this->exSets;
}

int exercise::getExReps() const {
    return this->exReps;
}

int exercise::getExWeight() const {
    return this->exWeight;
}

void exercise::exPrintInfo() const {
    // Prints detailed information about the exercise object
    
    cout << "Exercise name: " << exName << " || Exercise time: " << exTime << " minutes "
         << " || Sets completed: " << exSets << " || Reps completed: " << exReps << " || Weights used: " << exWeight << " pounds ||" << endl;
}
// By Alberto Santana and Ngawang Samdrup