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
        size--; /* When we push the highest number to the end of the vector we no longer need to search there.
                 * So really I suppose the time-complexity is O(n^2 - n), but at significantly large data sets
                 * that one less n doesn't really matter does it? (n = 1000, 1000000 vs 909000).*/
    }
    return array;
    // Clean, simple, horribly inefficient :)
}

vector<int> quick_sort(vector<int> array) {
    int len = array.size();
    if (len <= 1) {
        return array;
    }
    int idx = rand() % len;
    /* idx here is a random index from 0 to the length of the array.
     * It's random because special edge cases would make a sort with a statically defined index
     * really slow. For instance, an already sorted list pivoting around the end index would create n
     * call stacks. Which is of course not ideal.*/
    vector<int> left;
    vector<int> right;
    for (int i = 0; i < len; i++) {
        if (i == idx) {
            continue;
        }
        if (array[i] >= array[idx]) {
            right.push_back(array[i]);
        } else {
            left.push_back(array[i]);
        }
    }

    left = quick_sort(left);
    left.push_back(array[idx]);
    right = quick_sort(right);
    left.insert(left.end(), right.begin(), right.end());
    /* Ok, I really dislike this above block of code. There has to be a more elegant way to do this,
     * but if there is, I don't yet know it. I also feel like this takes up way too much memory.
     * I know there's a way to do it with an O(n) space complexity, but this is what I have thus far.
     * I really wish you could just do:
     * return quicksort(left) + mid + quicksort(right);*/
    return left;

}
