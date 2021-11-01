#include <iostream>
#include "sequence.h"
#include "listsequence.h"
#include "listsequence.cpp"
#include "arraysequence.h"
#include "arraysequence.cpp"
#include "isorter.h"
#include "isorter.cpp"
#include "extra.h"
#include <string>
#include <chrono>
using namespace std;


int main() {
    string vars1[] = {"", "Array sequence", "List sequence"};
    const int vars1_size = sizeof(vars1) / sizeof(vars1[0]);
    string request1 = "Choose a type of a sequence:\n";
    int* choice1 = new int;

    string vars2[] = {"", "Generate", "Fill by hand"};
    const int vars2_size = sizeof(vars2) / sizeof(vars2[0]);
    string request2 = "Choose an action:\n";
    int* choice2 = new int;

    string vars3[] = {"", "Sorted forward", "Sorted backwards", "Not sorted"};
    const int vars3_size = sizeof(vars3) / sizeof(vars3[0]);
    string request3 = "Choose a way of generation:\n";
    int* choice3 = new int;

    string vars4[] = {"", "Shaker sort", "Quick sort", "Heap sort", "Shell sort"};
    const int vars4_size = sizeof(vars4) / sizeof(vars4[0]);
    string request4 = "Choose a sorting method:\n";
    int* choice4 = new int;

    string vars_end[] = {"", "Yes", "No"};
    const int vars_end_size = sizeof(vars_end) / sizeof(vars_end[0]);
    string request_end = "Do you want to continue?\n";
    int* choice_end = new int;

    int* length = new int;
    do{
        dialog(vars1, vars1_size, request1, choice1);

        Sequence<int>* seq;

        if (*choice1 == 1)  //Array seq
            seq = (Sequence<int>*) new ArraySequence<int>;
        if (*choice1 == 2)  //List seq
            seq = (Sequence<int>*) new ListSequence<int>;

        dialog(vars2, vars2_size, request2, choice2);

        cout << "Enter a length of a sequence: ";
        enterLength(length);

        if (*choice2 == 1) {  //Generate
            dialog(vars3, vars3_size, request3, choice3);
            if (*choice3 == 1) {    // Sorted forward
                generate_sorted_forward(seq, length);
                out(seq);
            }
            if (*choice3 == 2) {    // Sorted backwards
                generate_sorted_backwards(seq, length);
                out(seq);
            }
            if (*choice3 == 3) {    // Not sorted
                generate_not_sorted(seq, length);
                out(seq);
            }
        }

        if (*choice2 == 2) {    // Fill
            fill(seq, length);
            out(seq);
        }

        dialog(vars4, vars4_size, request4, choice4);

        if (*choice4 == 1){ //Shaker
            ShakerSort<int> Sorter;
            auto t_1 = std::chrono::high_resolution_clock::now();
            Sorter.Sort(seq, cmp);
            auto t_2 = std::chrono::high_resolution_clock::now();
            out(seq);

            auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
            cout << "Time: " << time << " microseconds" << endl << endl;
        }
        if (*choice4 == 2){ //Quick
            QuickSort<int> Sorter;
            auto t_1 = std::chrono::high_resolution_clock::now();
            Sorter.Sort(seq, cmp);
            auto t_2 = std::chrono::high_resolution_clock::now();
            out(seq);

            auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
            cout << "Time: " << time << " microseconds" << endl << endl;
        }
        if (*choice4 == 3){ //Heap
            HeapSort<int> Sorter;
            auto t_1 = std::chrono::high_resolution_clock::now();
            Sorter.Sort(seq, cmp);
            auto t_2 = std::chrono::high_resolution_clock::now();
            out(seq);

            auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
            cout << "Time: " << time << " microseconds" << endl << endl;
        }
        if (*choice4 == 4){ //Shell
            ShellSort<int> Sorter;
            auto t_1 = std::chrono::high_resolution_clock::now();
            Sorter.Sort(seq, cmp);
            auto t_2 = std::chrono::high_resolution_clock::now();
            out(seq);

            auto time = std::chrono::duration_cast<std::chrono::microseconds>(t_2 - t_1).count();
            cout << "Time: " << time << " microseconds" << endl << endl;
        }

        dialog(vars_end, vars_end_size, request_end, choice_end);

        if (*choice_end == 2) cout << "Goodbye!";
    } while (*choice_end == 1);

    delete length;
    delete choice1;
    delete choice2;
    delete choice3;
    delete choice4;
    delete choice_end;

    return 0;
}
