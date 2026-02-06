/*
II.
Given a sorted array of positive integers, design an algorithm and implement
it using a program to find three indices i, j, k such that:

arr[i] + arr[j] = arr[k]

Input Format:
The first line contains number of test cases T.
For each test case:
- First line contains n (size of array)
- Second line contains space-separated sorted integers

Output Format:
For each test case, print the values of i, j, k if found
Else print "No sequence found"
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
        cout << "Enter " << n << " sorted elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        bool found = false;

        // Fix k and use two-pointer technique for i and j
        for (int k = n - 1; k >= 2 && !found; k--) {
            int i = 0;
            int j = k - 1;

            while (i < j) {
                int sum = arr[i] + arr[j];

                if (sum == arr[k]) {
                    cout << "Sequence found at indices: "
                         << i << ", " << j << ", " << k << endl;
                    found = true;
                    break;
                } 
                else if (sum < arr[k]) {
                    i++;
                } 
                else {
                    j--;
                }
            }
        }

        if (!found) {
            cout << "No sequence found" << endl;
        }
    }

    return 0;
}
