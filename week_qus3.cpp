// Question: Given an already sorted array of positive integers, design an algorithm using Jump Search to find whether a given key element is present in the array or not and find the total number of comparisons.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;                          // number of test cases

    while (T--) {
        int n;
        cin >> n;                      // size of array

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];             // sorted array elements
        }

        int key;
        cin >> key;                    // key element to search

        int comparisons = 0;
        bool found = false;

        int step = sqrt(n);
        int prev = 0;

        // Jumping phase
        while (prev < n && arr[min(step, n) - 1] < key) {
            comparisons++;
            prev = step;
            step += sqrt(n);
            if (prev >= n)
                break;
        }

        // Linear search in the block
        for (int i = prev; i < min(step, n); i++) {
            comparisons++;
            if (arr[i] == key) {
                found = true;
                break;
            }
        }

        if (found)
            cout << "Present " << comparisons << endl;
        else
            cout << "Not Present " << comparisons << endl;
    }

    return 0;
}
