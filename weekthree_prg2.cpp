/*
II.
Given an unsorted array of integers, design an algorithm and implement
a program to sort this array using selection sort. The program should
also find the number of comparisons and number of swaps required.

Input Format:
- First line contains number of test cases T.
- For each test case:
  * First line contains n (size of array)
  * Second line contains space-separated integers describing the array

Output Format:
- For each test case:
  * First line prints the sorted array
  * Second line prints total number of comparisons
  * Third line prints total number of swaps
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    while (T--) {
        int n;
        cout << "Enter size of array: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int comparisons = 0;
        int swaps = 0;

        // Selection Sort
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;

            for (int j = i + 1; j < n; j++) {
                comparisons++;
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            if (minIndex != i) {
                swap(arr[i], arr[minIndex]);
                swaps++;
            }
        }

        // Output sorted array
        cout << "Sorted array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swaps << endl;
    }

    return 0;
}
