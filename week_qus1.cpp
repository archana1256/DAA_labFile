// Question: Given an array of nonnegative integers, design a linear algorithm to check whether a given key element is present in the array or not and find the total number of comparisons.

#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"enetr size of array:"<<endl;
    cin >> n;                 // size of array
    cout<<"enter elemts in array:"<<endl;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];        // array elements
    }
    cout<<"eneter elements :"<<endl;
    int key;
    cin >> key;               // key element to search

    int comparisons = 0;
    bool found = false;

    for (int i = 0; i < n; i++) {
        comparisons++;        // one comparison with key
        if (arr[i] == key) {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Present " << comparisons << endl;
    else
        cout << "Not Present " << comparisons << endl;

    return 0;
}
