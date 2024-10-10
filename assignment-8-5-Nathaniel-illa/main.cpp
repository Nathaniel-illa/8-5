#include "main.hpp"

int main()
{
    int N = 1000; // You can change this to 10000 or 100000 for more extensive testing
    int cmpcnt = 0; // Comparison count for Merge Sort
    chrono::nanoseconds totalduration = chrono::nanoseconds::zero();
    vector<int> numbers;

    srand(time(0));

    // Measuring Merge Sort
    numbers.clear();
    fillvector(numbers, N);
    cout << "Unsorted array:\n";
    print(numbers);

    auto start = high_resolution_clock::now();
    mergesort(numbers, 0, numbers.size() - 1, cmpcnt);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Sorted array:\n";
    print(numbers);
    cout << "The average comparison count: " << cmpcnt << endl;
    cout << "The elapsed time (nanoseconds): " << duration.count() << endl;

    return 0;
}