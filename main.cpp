#include <iostream>
#include <vector>
#include "algorithms.h"
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

/* Alright, here we compare the actual runtimes of different sorting algorithms.
 * The list remains unchanged throughout the runs because the values are passed,
 * not the actual reference. There's probably some memory management issues.
 * I of course want to add more as I have more time to practice.
 *
 * Also I don't return the functions as void, because I want to have the _option_
 * to cout them. I can also check their values at the end of the run -- just to make
 * sure that they worked as intended. Everything seems fine so far!
 */

void sort_functions(vector<int> list) {

    Sorts demo;

    cout << "Starting Bubble Sort O(n^2)." << endl;
        auto start = high_resolution_clock::now();
            vector<int> bubble = demo.bubble_sort(list);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Bubble sort completed in: " << duration.count() << " milliseconds." << endl;

    cout << "Quick Sort O(n log(n))." << endl;
        start = high_resolution_clock::now();
            vector<int> quick = demo.quick_sort(list);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
    cout << "Quick sort completed in: " << duration.count() << " milliseconds." << endl;
}

int main() {

    int length = 10000;
    int max = 1000;

    Utilities utilitiy;
    vector<int> list = utilitiy.create_random_vector(length, max);


    sort_functions(list);

    return 1; // Ok c++, whatever you want.

}
