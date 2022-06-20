#include "DateManager.h"


int DateManager :: getActualDate() {
    int actualDate = 0;
    year = getActualYear();
    actualDate = (year * 10000);
    month = getActualMonth();
    actualDate += (month * 100);
    day = getActualDay();
    actualDate += day;

    return actualDate;
}

int DateManager :: getActualYear() {
    time(&timeResult);
    date = localtime(&timeResult);
    year = date -> tm_year+1900;

    return year;
}

int DateManager :: getActualMonth() {
    time(&timeResult);
    date = localtime(&timeResult);
    month = date -> tm_mon+1;

    return month;
}

int DateManager :: getActualDay() {
    time(&timeResult);
    date = localtime(&timeResult);
    day = date -> tm_mday;

    return day;
}

bool DateManager :: checkLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int DateManager :: maxNumberDays(int month, int year)
{
    cout << "maxNumberDays:" << DAYS_NUMBER[checkLeapYear(year)][month] << endl;
    return DAYS_NUMBER[checkLeapYear(year)][month];
}

bool DateManager :: isDayCorrect(int enteredDay, int enteredMonth, int enteredYear) {

    if (enteredDay >= 1 && (enteredDay <= maxNumberDays(enteredMonth, enteredYear))) {
            cout << "isDayCorrect:" << "true" << endl;
            return true;
        } else{
            cout << "isDayCorrect:" << "false" << endl;
            return false;
        }
}

bool DateManager :: isMonthCorrect(int enteredMonth) {

   if (enteredMonth < 1 || enteredMonth > 12) {
        cout << "isMonthCorrect:" << "false" << endl;
        return false;
    }
   cout << "isMonthCorrect:" << "true" << endl;
    return true;
}

bool DateManager :: isYearCorrect(int enteredYear) {

    if (enteredYear > getActualYear() || enteredYear < MIN_VALUE_YEAR) {
            cout << "isYearCorrect:" << "false" << endl;
        return false;
    }
    cout << "isYearCorrect:" << "true" << endl;
    return true;
}

bool DateManager :: isDateCorrect(string date) {

 int charPosition=0;
 int year = SupportingMethods::stringToIntConversion(SupportingMethods::downloadNumber(date, charPosition));
 cout << "Year:" << year << endl;
 int month = SupportingMethods::stringToIntConversion(SupportingMethods::downloadNumber(date, charPosition));
 cout << "Month:" << month << endl;
 cout << "charPosition:" << charPosition << endl;
 int day = SupportingMethods::stringToIntConversion(SupportingMethods::downloadNumber(date, charPosition));
 cout << "Day:" << day << endl;
 cout << "charPosition:" << charPosition << endl;

 maxNumberDays(month, year);
 isDayCorrect(day, month, year);

    if (isDateFormatCorrect(date) == false) {
        return false;
    } else if (isYearCorrect(year) == false) {
        return false;
    } else if (isMonthCorrect(month) == false || month > getActualMonth()) {
        return false;
    } else if (day >= 1 && day <= 31) {             //do usuniêcia dmax
        if (isDayCorrect(day, month, year) == true) {
                cout << "isDayCorrect:" << "true" << endl;
            return true;
        } else {
            cout << "isDayCorrect:" << "true" << endl;
            return false;
        }
    } else {
        cout << "isDayCorrect:" << "true" << endl;
        return false;
    }
    cout << "isDateCorrect:" << "true" << endl;
    return true;

}

bool DateManager :: isDateFormatCorrect(string date){

    if ((date.size() == 10)&&(date[0] == '2') && (date[4] == '-') && (date[7] == '-')){

        cout << "isDateFormatCorrect:" << "true" << endl;
        return true;
    }else{
        cout << "isDateFormatCorrect:" << "false" << endl;
        cout << "date.size():" << date.size() << endl;
        cout << "date[0]:" << date[0] << endl;
        cout << "date[4]:" << date[4] << endl;
        cout << "date[7]:" << date[7] << endl;
        return false;
    }
}

relationType DateManager :: comparedTo(Date dateA, Date dateB) {
if (dateA.getYear() < dateB.getYear())
    return Precedes;
if (dateA.getYear() > dateB.getYear())
    return Follows;
if (dateA.getMonth() < dateB.getMonth())
    return Precedes;
if (dateA.getMonth() > dateB.getMonth())
    return Follows;
if (dateA.getDay() < dateB.getDay())
    return Precedes;
if (dateA.getDay() > dateB.getDay())
    return Follows;
return Same;
}
