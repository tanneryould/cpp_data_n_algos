#include <iostream>
#include <vector>
#include "sorts.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

/* Alright, here we compare the actual runtimes of different sorting algorithms.
 * The list remains unchanged throughout the runs because the values are passed,
 * not the actual reference. There's probably some memory management issues.
 * I of course want to add more as I have more time to practice.
 */

int main() {

    int length = 50000;
    int max = 100000;
    cout << "Creating a list of " << to_string(length) << " random numbers, between 0 and " << to_string(max-1) << "." << endl;
        auto start = high_resolution_clock::now();
            vector<int> list = create_random_vector(length, max);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Completed in: " << duration.count() << " milliseconds." << endl;

    cout << "Starting Bubble Sort O(n^2)." << endl;
        start = high_resolution_clock::now();
            vector<int> bubble = bubble_sort(list);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
    cout << "Bubble sort completed in: " << duration.count() << " milliseconds." << endl;

    cout << "Starting My Recursive Quick Sort O(n log(n))." << endl;
        start = high_resolution_clock::now();
            vector<int> quick = quick_sort(list);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
    cout << "Quick sort completed in: " << duration.count() << " milliseconds." << endl;

}
