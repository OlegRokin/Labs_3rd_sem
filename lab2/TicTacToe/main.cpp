#include <iostream>
#include "sequence.h"
#include "listsequence.h"
#include <fstream>
#include "extrafunctions.h"
#include <string.h>
using namespace std;


int main() {
    int n;
    cout << "Enter dimension of the field: ";
    cin >> n;

    Field field(n);
    field.WriteFieldInFile("field.txt");
    cout << field << endl;
    do{
        cout << "Enter your step: ";
        Point pX;
        cin >> pX.x >> pX.y;

        field.ReadFieldFromFile("field.txt");
        field.ChangeField(pX, 'X');
        field.WriteFieldInFile("field.txt");

        cout << field << endl;

        if(field.CheckFinishStateBigField() == 'X' || field.CheckFinishStateBigField() == 'O' || field.CheckFillField()) break;

        Game game(n);
        game.Init();
        game.MakeTree();

        game.SaveStepInFile("field.txt");

        field.ReadFieldFromFile("field.txt");

        cout << field << endl;

        game.CountChances();

        game.SaveChancesInFile();
        Point pBest = game.FindBestXStep();
        int chance = game.ChancesBestXStep();
        cout << "Recommendation: " << pBest.x << " " << pBest.y << " (win " << chance << "%)" << endl << endl;
    } while(field.CheckFinishStateBigField() == '0');

    if(field.CheckFinishStateBigField() == 'X') cout << "You win!" << endl;
    if(field.CheckFinishStateBigField() == 'O') cout << "You lose" << endl;
    if(field.CheckFinishStateBigField() == '0') cout << "Tie" << endl;

    return 0;

}
