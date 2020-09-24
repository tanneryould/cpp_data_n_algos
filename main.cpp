#include <iostream>
#include <vector>
#include "algorithms.h"
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;
using Clock = high_resolution_clock;



vector<int> sort_functions(vector<int> list) {

    /* Alright, here we compare the actual runtimes of different sorting algorithms.
     * The list remains unchanged throughout the runs because the values are passed,
     * not the actual reference. There's probably some memory management issues.
     * I of course want to add more as I have more time to practice.
     *
     * Also I don't return the functions as void, because I want to have the _option_
     * to cout them. I can also check their values at the end of the run -- just to make
     * sure that they worked as intended. Everything seems fine so far!
     */

    Sorts demo;

    cout << "Starting Bubble Sort O(n^2)." << endl;
        auto start = Clock::now();
            vector<int> bubble = demo.bubble_sort(list);
        auto stop = Clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Bubble sort completed in: " << duration.count() << " milliseconds." << endl;

    cout << "Quick Sort O(n log(n))." << endl;
        start = Clock::now();
            vector<int> quick = demo.quick_sort(list);
        stop = Clock::now();
        duration = duration_cast<milliseconds>(stop - start);
    cout << "Quick sort completed in: " << duration.count() << " milliseconds." << endl;
    return quick;
}

void binary_search_with_timer(int target, vector<int> list) {

    Searches demo;

    cout << "Binary Search" << endl;
        auto start = Clock::now();
            int idx = demo.binary_search(target, list, 0, list.size());
        auto stop = Clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Found: " << target << " at index: " << idx << " in " << duration.count() << " milliseconds." << endl;

}

int main() {

    int length = 100000;
    int max = 1000;

    Utilities utilitiy;
    vector<int> list = utilitiy.create_random_vector(length, max);
    int r = 900;

    vector<int> sorted_list = sort_functions(list);
    binary_search_with_timer(r, sorted_list);

    return 1; // Ok c++, whatever you want.

}
