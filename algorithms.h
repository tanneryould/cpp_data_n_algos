#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Utilities {
private:
    long timestamp;
    string func_name = "";
public:
    vector<int> create_random_vector(int length, int max);
    void start(string name="Function");
    void stop();
};

class Sorts {
    public:
        vector<int> bubble_sort(vector<int> array);
        vector<int> quick_sort(vector<int> array);
};

class Searches {
    public:
        int linear_search(int item, vector<int> list);
        int binary_search(int item, vector<int> array, int left, int right);
};

#endif // ALGORITHMS_H
