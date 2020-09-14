#ifndef SORTS_H
#define SORTS_H

#include <vector>

using namespace std;

vector<int> create_random_vector(int length, int max);
vector<int> bubble_sort(vector<int> array);
vector<int> quick_sort(vector<int> array);
void InternetQuickSort(int arr[], int low, int high);

#endif // SORTS_H


