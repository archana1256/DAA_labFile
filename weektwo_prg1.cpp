/*
I.
Given a sorted array of positive integers containing few duplicate elements,
design an algorithm and implement it using a program to find whether the given
key element is present in the array or not. If present, then also find the
number of copies of the given key.

Time Complexity: O(log n)

Input Format:
- First line contains number of test cases T.
- For each test case:
  * First line contains n (size of array)
  * Second line contains space-separated sorted integers
  * Third line contains the key element to be searched

Output Format:
- For each test case:
  * Print the key element and its number of copies if present
  * Otherwise print "Key not present"
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find first occurrence
int firstOccurrence(vector<int>& arr, int n, int key) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            ans = mid;
            high = mid - 1;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// Function to find last occurrence
int lastOccurrence(vector<int>& arr, int n, int key) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            ans = mid;
            low = mid + 1;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

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

        int key;
        cout << "Enter key element to search: ";
        cin >> key;

        int first = firstOccurrence(arr, n, key);

        if (first == -1) {
            cout << "Key not present" << endl;
        } else {
            int last = lastOccurrence(arr, n, key);
            int count = last - first + 1;
            cout << "Element " << key << " occurs " << count << " times" << endl;
        }
    }
    return 0;
}
