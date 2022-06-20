#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

class SupportingMethods
{

public:
    static string intToStringConversion(int number);
    static int stringToIntConversion(string number);
    static string downloadNumber(string text, int &charPosition);
    static string loadLine();
    static char loadCharacter();
    static string replaceFirstLetterToUppercaseAndRestToLowercase(string text);
    static int loadIntegerNumber();
    static string deleteDashFromDate(string date);
};
#endif // SUPPORTINGMETHODS_H
