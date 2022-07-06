#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date{

string date;
int year;
int month;
int day;

public:
    Date(string date= "")
    {
        this->date = date;
    }

   void setYear(int newYear);
   void setMonth(int newMonth);
   void setDay(int newDay);

   string getDate();
   int getYear();
   int getMonth();
   int getDay();

};

#endif // DATE_H
