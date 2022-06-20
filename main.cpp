#include <iostream>
#include "SupportingMethods.h"
#include "DateManager.h"

using namespace std;

int main()
{
    DateManager dateManager;
    string enteringDate = "";
    string stringDateWithoutDash;
    int intDateWithoutDash;

    do {
            cout << "Enter date in format YYYY-MM-DD: ";

            enteringDate = (SupportingMethods :: loadLine());
            dateManager.isDateCorrect(enteringDate);

        } while (dateManager.isDateCorrect(enteringDate) == false);

        stringDateWithoutDash = SupportingMethods :: deleteDashFromDate(enteringDate);
        intDateWithoutDash = SupportingMethods :: stringToIntConversion(stringDateWithoutDash);

    return 0;
}
