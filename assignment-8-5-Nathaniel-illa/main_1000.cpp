#include "main.hpp"

int main()
{
    int N = 1000;
    double totalswapcnt = 0;
    chrono::nanoseconds totalduration = chrono::nanoseconds::zero();
    chrono::nanoseconds duration = chrono::nanoseconds::zero();
    vector<int> numbers;

    srand(time(0));

    // Merge Sort
    for (int i = 0; i < 1000; i++)
    {
        int cmpcnt = 0; // Reset comparison count for each sort
        numbers.clear();
        fillvector(numbers, N);
        auto start = high_resolution_clock::now();
        mergesort(numbers, 0, numbers.size() - 1, cmpcnt);
        auto stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        totalswapcnt += cmpcnt; // Add to total comparison count
        totalduration += duration; // Add to total duration
    }

    double averageSwapCount = totalswapcnt / 1000.0;
    duration = duration_cast<nanoseconds>(totalduration / 1000.0);

    cout << "The average comparison count: " << averageSwapCount << endl;
    cout << "The elapsed time (nanoseconds): " << duration.count() << endl;

    return 0;
}