#include "SupportingMethods.h"

string SupportingMethods::intToStringConversion(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
int SupportingMethods::stringToIntConversion(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}


string SupportingMethods::loadLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char SupportingMethods::loadCharacter()
{
    string input = "";
    char character = {0};

    while (true)
    {
        getline(cin, input);
        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string SupportingMethods::replaceFirstLetterToUppercaseAndRestToLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int  SupportingMethods::loadIntegerNumber()
{
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);
        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;

    }
    return number;
}

string SupportingMethods :: deleteDashFromDate(string date) {

    string stringDateWithoutDash;

    for (int i = 0 ; i <= date.length(); i++) {
        if (date[i] != '-') {
            stringDateWithoutDash += date[i];
        }
    }

    return stringDateWithoutDash;
}

Date SupportingMethods :: convertingStringDateToDateClassObject(string dateString) {

    Date enteringDate;

    string yearString = "";
    string monthString = "";
    string dayString = "";


    for(int charPosition = 0; charPosition >= 0 && charPosition <= 9; charPosition ++)
    {

        if(charPosition >= 0 && charPosition <=3 && isdigit(dateString[charPosition]) == true){
            yearString += dateString[charPosition];
        }else if(charPosition >= 5 && charPosition <=6 && isdigit(dateString[charPosition]) == true){
            monthString += dateString[charPosition];
        }else if(charPosition >= 8 && charPosition <=9 && isdigit(dateString[charPosition]) == true){
            dayString += dateString[charPosition];
        }

    }
    enteringDate.setYear(stringToIntConversion(yearString));
    cout << "enteringDate.setYear: " << stringToIntConversion(yearString) << endl;
    enteringDate.setMonth(stringToIntConversion(monthString));
    cout << "enteringDate.setMonth: " << stringToIntConversion(monthString) << endl;
    enteringDate.setDay(stringToIntConversion(dayString));
    cout << "enteringDate.setDay: " << stringToIntConversion(dayString) << endl;

    return enteringDate;

}
