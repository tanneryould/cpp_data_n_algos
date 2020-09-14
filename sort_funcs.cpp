#include "sorts.h"
#include <vector>
#include <iostream>

using namespace std;

vector<int> create_random_vector(int length, int max) {
    vector<int> vect;
    for (int i = 0; i < length; i++){
        vect.push_back(rand() % max);
    }
    return vect;
}

vector<int> bubble_sort(vector<int> array) {
    bool sorted = false;
    int size = array.size();
    int temp;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < size-1; i++) {
            if (array[i] > array[i+1]) {
                sorted = false;
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
        size--;
    }
    return array;
}

vector<int> quick_sort(vector<int> array) {
    int len = array.size();
    if (len <= 1) {
        return array;
    }
    int mid = rand() % len;
    vector<int> left;
    vector<int> right;
    for (int i = 0; i < len; i++) {
        if (i == mid) {
            continue;
        }
        if (array[i] >= array[mid]) {
            right.push_back(array[i]);
        } else {
            left.push_back(array[i]);
        }
    }

    left = quick_sort(left);
    left.push_back(array[mid]);
    right = quick_sort(right);
    left.insert(left.end(), right.begin(), right.end());
    return left;

}
