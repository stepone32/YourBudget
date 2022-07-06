#include <iostream>
#include "SupportingMethods.h"
#include "DateManager.h"
#include "Date.h"
#include <windows.h>
#include <cstdlib>
#include <string>

using namespace std;

char chooseOptionFromMainMenu();

int main()
{
    DateManager dateManager;
    Date dateA, dateB;
    enum relationType dateComparisonResult ;

    char choose = chooseOptionFromMainMenu();

        switch(choose)
        {
            case '1':
                {
                dateManager.getActualDate();
                dateManager.displayDate(dateManager);
                }
                break;
            case '2':
                {
                    dateManager.enterDate();
                }
                break;
            case '3':
                {
                    cout << "Wprowadz date A:" << endl;
                    dateA = dateManager.enterDate();
                    cout << "Wprowadz date B:" << endl;
                    dateB = dateManager.enterDate();
                    dateComparisonResult = dateManager.dateAcomparedToDateB(dateA, dateB);

                    if(dateComparisonResult == Same){
                        cout << "Daty sa takie same!" << endl;
                    }
                    if(dateComparisonResult == Precedes){
                         cout << "Data A wystepuje przed data B!" << endl;
                    }
                    if(dateComparisonResult == Follows){
                         cout << "Data A wystepuje po dacie data B!" << endl;
                    }
                }
                break;
            case '4':
                exit(0);
                break;

                default: // oznacza blok instrukcji wykonywany dla wszystkich pozosta³ych wartoœci zmienna
        {
            cout<<"Wybierz poprawna opcje menu wpisujac poprawna liczbe oraz potwierdzajac klawiszem ENTER!";
            Sleep(2000);
            choose = '0';
        }
        break;
        }

    return 0;
}

char chooseOptionFromMainMenu(){
    char choose;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Wyswietl aktulana date" << endl;
    cout << "2. Wprowadz date i sprawdz jej poprawnosc" << endl;
    cout << "3. Porownaj daty" << endl;
    cout << "4. End " << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choose = SupportingMethods::loadCharacter();

    return choose;
}

