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
    return DAYS_NUMBER[checkLeapYear(year)][month];
}

bool DateManager :: isDayCorrect(int enteredDay, int enteredMonth, int enteredYear) {

    if (enteredDay >= 1 && (enteredDay <= maxNumberDays(enteredMonth, enteredYear))) {
            cout << "isDayCorrect true" << endl;
            return true;
        } else{
            cout << "isDayCorrect false" << endl;
            return false;
        }
}

bool DateManager :: isMonthCorrect(int enteredMonth) {

   if (enteredMonth < 1 || enteredMonth > 12){
        cout << "isMonthCorrect false" << enteredMonth << endl;
        return false;
    }
    cout << "isMonthCorrect true" << endl;
    return true;
}

bool DateManager :: isYearCorrect(int enteredYear) {

    if (enteredYear > getActualYear() || enteredYear < MIN_VALUE_YEAR) {
        cout << "isYearCorrect false" << endl;
        return false;
    }
    cout << "isYearCorrect true" << endl;
    return true;
}

bool DateManager :: isDateCorrect(string date) {


Date enteringDate = (SupportingMethods :: convertingStringDateToDateClassObject(date));


    if (isDateFormatCorrect(date) == false) {
        return false;
    } else if (isYearCorrect(enteringDate.getYear()) == false) {
        return false;
    } else if (isMonthCorrect(enteringDate.getMonth()) == false || ( enteringDate.getYear () == getActualYear() && enteringDate.getMonth() > getActualMonth())) {
        return false;
    } else if (isDayCorrect(enteringDate.getDay(), enteringDate.getMonth(), enteringDate.getYear()) == true) {
            return true;
        } else {
            return false;
        }

    return true;

}

bool DateManager :: isDateFormatCorrect(string date){

    if ((date.size() == 10)&&(date[0] == '2') && (date[4] == '-') && (date[7] == '-')){
        return true;
    }else{
        return false;
    }
}

relationType DateManager :: dateAcomparedToDateB(Date dateA, Date dateB) {

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

Date DateManager :: enterDate(){
     string enteringDate = "";
     DateManager dateManager;

    do {
            cout << "Enter date in format YYYY-MM-DD: ";

            enteringDate = (SupportingMethods :: loadLine());
            dateManager.isDateCorrect(enteringDate);

        } while (dateManager.isDateCorrect(enteringDate) == false);


    return SupportingMethods :: convertingStringDateToDateClassObject(enteringDate);

 }


void DateManager :: displayDate(DateManager date)
{
    cout << "Rok: " << date.getActualYear() << endl;
    cout << "miesiac: " << date.getActualMonth() << endl;
    cout << "dzien: " << date.getActualDay() << endl;
    system("pause");


}
