#include <iostream>
#include <vector>  
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void fillvector(vector<int> &, int size);
void mergesort(vector<int> &, int, int, int &);
void merge(vector<int> &, int, int, int &);
void print(const vector<int> &);

void fillvector(vector<int> &numbers, int N)
{
    numbers.clear();
    for (int i = 0; i < N; i++)
        numbers.push_back(rand() % 1000); // Fill with random values
}

void merge(vector<int> &numbers, int left, int mid, int right, int &cmpcnt)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = numbers[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = numbers[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        cmpcnt++;
        if (L[i] <= R[j]) {
            numbers[k] = L[i];
            i++;
        } else {
            numbers[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        numbers[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        numbers[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> &numbers, int left, int right, int &cmpcnt)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergesort(numbers, left, mid, cmpcnt);
        mergesort(numbers, mid + 1, right, cmpcnt);
        merge(numbers, left, mid, right, cmpcnt);
    }
}

void print(const vector<int> &numbers)
{
    for (const auto &v : numbers)
        cout << v << "\t";
    cout << endl;
}