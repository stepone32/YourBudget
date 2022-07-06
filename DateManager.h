#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "Date.h"
#include <windows.h>

#include "SupportingMethods.h"

using namespace std;
enum relationType {Precedes,Same,Follows};

 class DateManager{

time_t timeResult;
struct tm *date;
int year;
int month;
int day;
const int MIN_VALUE_YEAR = 2000;
const int DAYS_NUMBER[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                                 {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
public:
    int getActualDate();
    int getActualYear();
    int getActualMonth();
    int getActualDay();

    bool checkLeapYear(int year);
    int maxNumberDays(int month, int year);

    Date enterDate();
    bool isDayCorrect(int enteredDay, int enteredMonth, int enteredYear);
    bool isMonthCorrect(int enteredMonth);
    bool isYearCorrect(int enteredYear);
    bool isDateCorrect(string date);
    bool isDateFormatCorrect(string date);
    void displayDate(DateManager date);

    relationType dateAcomparedToDateB(Date dateA, Date dateB);

};
#endif //DATEMANAGER_H
