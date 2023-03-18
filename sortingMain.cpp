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

    int arr3[] = { 8, 7, 42, 9, 2, 65 };
    int n3 = sizeof(arr3) / sizeof(arr2[0]);
    sortlib::selection_sort(arr3, n3);
    cout << "selection Sorted Array:" << endl;
    sortlib::print_array(arr3, n3);

    cout<<"\n\n**********************************************\n\n";

    int arr4[] = { 2, 4, 64, 9, 7, 1 };
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    sortlib::insertion_sort(arr4, n4);
    cout << "insertion Sorted Array:" << endl;
    sortlib::print_array(arr4, n4);

    cout<<"\n\n**********************************************\n\n";

    int arr5[] = { 6, 2, 60, 35, 67, 3 };
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    sortlib::bubble_sort(arr5, n5);
    cout << "Bubble Sorted Array:" << endl;
    sortlib::print_array(arr5, n5);

    cout<<"\n\n**********************************************\n\n";

    int arr6[] = { 355, 6, 33, 3, 3, 9 };
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    sortlib::quick_sort(arr6, 0, n6-1);
    cout << "quick Sorted Array:" << endl;
    sortlib::print_array(arr6, n6);

    cout<<"\n\n**********************************************\n\n";

    int arr7[] = { 10, 7, 20, 9, 3, 5 };
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    sortlib::merge_sort(arr7, 0, n7-1);
    cout << "Merge Sorted Array:" << endl;
    sortlib::print_array(arr7, n7);


    cout<<"\n\n**********************************************\n\n";

    // Test sorting performance
    vector<int> sizes = {200, 500, 1000, 5000,10000,20000,50000};
    sortlib::test_sort<int>(sizes);

    return 0;
}
