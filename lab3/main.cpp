#include <iostream>
#include "extra.h"
#include "tests.h"


void Test() {
    WriteIntoFile("tests.txt");
}

void Run() {
    string vars0[] = {"", "Directed graph", "Undirected graph"};
    const int vars0_size = sizeof(vars0) / sizeof(vars0[0]);
    string request0 = "Choose a type of a graph:\n";
    int* choice0 = new int;

    string vars1[] = {"", "Generate", "Fill by hand"};
    const int vars1_size = sizeof(vars1) / sizeof(vars1[0]);
    string request1 = "Choose an action:\n";
    int* choice1 = new int;

    string vars2[] = {"", "Find the shortest way", "Find a skeleton"};
    const int vars2_size = sizeof(vars2) / sizeof(vars2[0]);
    string request2 = "Choose an action:\n";
    int* choice2 = new int;

    string vars_end[] = {"", "Yes", "No"};
    const int vars_end_size = sizeof(vars_end) / sizeof(vars_end[0]);
    string request_end = "Do you want to continue?\n";
    int* choice_end = new int;

    Graph<int>* graph = new Graph<int>();

    do{
        bool mode;
        dialog(vars0, vars0_size, request0, choice0);
        if (*choice0 == 1) mode = 1;
        if (*choice0 == 2) mode = 0;

        dialog(vars1, vars1_size, request1, choice1);

        cout << "Enter size: ";
        int* size = new int;
        enterDefInt(size, 1);

        if (*choice1 == 1) graph = new Graph<int>(GenerateGraphRand(*size, mode));  //Generate
        if (*choice1 == 2) graph = new Graph<int>(FillGraph(*size, mode));   //Fill

        cout << endl;
        graph->ShowMatrix();
        cout << endl;

        bool connected = false;

        if (*choice0 == 2) {
            connected = graph->IsConnected();
            if (connected) cout << "The graph is connected" << endl << endl;
            else cout << "The graph is disconnected" << endl << endl;
        }

        if (*choice0 == 2 && connected) {
            dialog(vars2, vars2_size, request2, choice2);

            if (*choice2 == 1) {    //Find way
                cout << endl << "Enter start dot: ";
                int* start = new int;
                enterDefInt(start, 1, *size);
                (*start)--;
                ShowShortest(*start, graph->FindShortest(*start));
                cout << endl;
                delete start;
            }
            if (*choice2 == 2) {    //Find skeleton
                Graph<int>* skeleton = new Graph<int>(graph->FindSkeleton());
                skeleton->ShowMatrix();
                cout << endl;
                int cost = skeleton->Cost();
                cout << "Cost: " << cost << endl << endl;

                delete skeleton;
            }
        }

        if (*choice0 == 1 || (*choice0 == 2 && !connected)) {
            cout << "Find the shortest way" << endl << "Enter start dot: ";
            int* start = new int;
            enterDefInt(start, 1, *size);
            (*start)--;
            ShowShortest(*start, graph->FindShortest(*start));
            cout << endl;
            delete start;
        }

        dialog(vars_end, vars_end_size, request_end, choice_end);
        if (*choice_end == 2) cout << "Goodbye!";

        delete size;
        delete graph;

    } while (*choice_end == 1);

    delete choice0;
    delete choice1;
    delete choice2;
    delete choice_end;
}


int main() {

    Run();
    //Test();

    return 0;
}
