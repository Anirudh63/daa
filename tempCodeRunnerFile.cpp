#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

mt19937 rng(
    chrono::steady_clock::now().time_since_epoch().count()
);

// Partition using FIRST element as pivot
int partitionArray(vector<int>& a, int low, int high,
                   long long& comparisons) {

    int pivot = a[low];
    int i = low;

    for (int j = low + 1; j <= high; j++) {

        comparisons++;

        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[low], a[i]);

    return i;
}

// Deterministic Quick Sort
void quickSortDeterministic(vector<int>& a, int low,
                            int high, long long& comparisons) {

    if (low < high) {

        int pi = partitionArray(a, low, high, comparisons);

        quickSortDeterministic(a, low, pi - 1, comparisons);
        quickSortDeterministic(a, pi + 1, high, comparisons);
    }
}

// Randomized Quick Sort
void quickSortRandomized(vector<int>& a, int low,
                         int high, long long& comparisons) {

    if (low < high) {

        // Select random pivot
        uniform_int_distribution<int> dist(low, high);
        int randomIndex = dist(rng);

        // Move random pivot to first position
        swap(a[low], a[randomIndex]);

        int pi = partitionArray(a, low, high, comparisons);

        quickSortRandomized(a, low, pi - 1, comparisons);
        quickSortRandomized(a, pi + 1, high, comparisons);
    }
}

// Print array
void printArray(vector<int>& a) {
    for (int x : a)
        cout << x << " ";

    cout << endl;
}

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input";
        return 0;
    }

    vector<int> a(n);

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b = a;

    long long c1 = 0, c2 = 0;

    quickSortDeterministic(a, 0, n - 1, c1);
    quickSortRandomized(b, 0, n - 1, c2);

    cout << "\nDeterministic Quick Sort:\n";
    printArray(a);
    cout << "Comparisons: " << c1 << endl;

    cout << "\nRandomized Quick Sort:\n";
    printArray(b);
    cout << "Comparisons: " << c2 << endl;

    return 0;
}
