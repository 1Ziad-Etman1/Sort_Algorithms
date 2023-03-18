#include <iostream>
#include <vector>
#include "sortlib.h"

using namespace std;

int main() 

{
    /*vector<int> sizes = {200, 500, 1000, 5000, 10000, 20000, 50000};

    for (int size : sizes) {
        int* arr = new int[size];

        // Fill array with random values
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 1000;
        }

        cout << "Before sorting: ";
        print_array(arr, size);

        // Shell sort
        sortlib::shell_sort(arr, size);
        cout << "Shell sort: ";
        print_array(arr, size);

        // Count sort
        sortlib::count_sort(arr, size);
        cout << "Count sort: ";
        print_array(arr, size);

        delete[] arr;
    }*/

    // Test sorting functions
    int arr1[] = { 10, 7, 8, 9, 1, 5 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    sortlib::shell_sort(arr1, n1);
    cout << "Shell Sorted Array:" << endl;
    sortlib::print_array(arr1, n1);

    cout<<"\n\n**********************************************\n\n";

    int arr2[] = { 10, 7, 20, 9, 3, 5 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    sortlib::count_sort(arr2, n2);
    cout << "Count Sorted Array:" << endl;
    sortlib::print_array(arr2, n2);

    cout<<"\n\n**********************************************\n\n";

    // Test sorting performance
    vector<int> sizes = {200, 500, 1000, 5000,10000,20000,50000};
    sortlib::test_sort<int>(sizes);

    return 0;
}
