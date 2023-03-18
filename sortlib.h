// sortlib.h file
#ifndef SORTLIB_H
#define SORTLIB_H


#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


namespace sortlib 
{

     // Shell sort
    template<typename T>
    void shell_sort(T arr[], int n) 
    {
        for (int gap = n/2; gap > 0; gap /= 2) 
        {
            for (int i = gap; i < n; i++) 
            {
                T temp = arr[i];
                int j = i;
                for (; j >= gap && temp < arr[j-gap]; j -= gap) 
                {
                    arr[j] = arr[j-gap];
                }
                arr[j] = temp ;
            }
        }
    }

    // Count sort
    template<typename T>
    void count_sort(T arr[], int size) 
    {
        T max_element = arr[0];
        for (int i = 1; i < size; i++) 
        {
            if (arr[i] > max_element) 
            {
                max_element = arr[i];
            }
        }

        vector<T> count(max_element + 1, 0);

        for (int i = 0; i < size; i++) 
        {
            count[arr[i]]++;
        }
        
        for (int i = 1; i <= max_element; i++) 
        {
            count[i] += count[i - 1];
        }
        
        T* output = new T[size];

         for (int i = size - 1; i >= 0; i--) 
         {
            output[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }

        for (int i = 0; i < size; i++) 
        {
            arr[i] = output[i];
        }

        delete[] output;
    }

    // Print sorted array
    template<typename T>
    void print_array(T arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

   


    // Test sorting time

   /*template<typename T>
    void test_sort(vector<int> sizes) 
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distr(1, 100000);

        ofstream data_file("data.csv");
        data_file << "Size,Shell Sort,Count Sort\n";

        //vector<int> sizes = {1000, 10000, 100000, 1000000};

        for (int size : sizes) 
        {
            T* arr = new T[size];
            for (int i = 0; i < size; i++) {
                arr[i] = distr(gen);
            }

            auto start = chrono::steady_clock::now();
            sortlib::shell_sort(arr, size);
            auto end = chrono::steady_clock::now();
            chrono::duration<double> shell_sort_time = end - start;

             //auto duration = chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

            cout << "Shell Sort:" << endl;
            cout << "Size: " << size << "\n";
            cout << "Time elapsed: " << shell_sort_time.count() << " seconds\n";
            cout<<"\n\n**********************************************\n\n";

           // sortlib::print_array(arr, size);

            start = chrono::steady_clock::now();
            sortlib::count_sort(arr, size);
            end = chrono::steady_clock::now();
            chrono::duration<double> count_sort_time = end - start;

            cout << "Count Sort:" << endl;

            cout << "Size: " << size << "\n";
            cout << "Time elapsed: " << count_sort_time.count() << " seconds\n";
            cout<<"\n\n**********************************************\n\n";


            //
            //sortlib::print_array(arr, size);

            data_file << size << "," << shell_sort_time.count() << "," << count_sort_time.count() << "\n";

            

            delete[] arr;
        }

        data_file.close();
    }*/

    // Test sorting time

/*template<typename T>
void test_sort(vector<int> sizes) 
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<T> distr(1, 100000);

    ofstream data_file("data.csv");
    data_file << "Size,Shell Sort,Count Sort\n";

    for (int size : sizes) 
    {
        T* arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = distr(gen);
        }

        auto start = chrono::steady_clock::now();
        sortlib::shell_sort(arr, size);
        auto end = chrono::steady_clock::now();
        chrono::microseconds shell_sort_time = chrono::duration_cast<chrono::microseconds>(end - start);

        cout << "Shell Sort:" << endl;
        sortlib::print_array(arr, size);

        start = chrono::steady_clock::now();
        sortlib::count_sort(arr, size);
        end = chrono::steady_clock::now();
        chrono::microseconds count_sort_time = chrono::duration_cast<chrono::microseconds>(end - start);

        cout << "Count Sort:" << endl;
        sortlib::print_array(arr, size);

        data_file << size << "," << shell_sort_time.count() << "," << count_sort_time.count() << "\n";

        delete[] arr;
    }

    data_file.close();
}*/

template<typename T>
void test_sort(vector<int> sizes)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distr(1, 100000);

    ofstream data_file("data.csv");
    data_file << "Size,Shell Sort,Count Sort\n";

    for (int size : sizes)
    {
        T* arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = distr(gen);
        }

        auto start = chrono::high_resolution_clock::now();
        sortlib::shell_sort(arr, size);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> shell_sort_time = end - start;

        cout << "Shell Sort:" << endl;
        cout << "Size: " << size << "\n";
        cout << "Time elapsed: " << shell_sort_time.count() << " microseconds\n";
        cout<<"\n\n**********************************************\n\n";

        start = chrono::high_resolution_clock::now();
        sortlib::count_sort(arr, size);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> count_sort_time = end - start;

        cout << "Count Sort:" << endl;
        cout << "Size: " << size << "\n";
        cout << "Time elapsed: " << count_sort_time.count() << " microseconds\n";
        cout<<"\n\n**********************************************\n\n";

        data_file << size << "," << shell_sort_time.count() << "," << count_sort_time.count() << "\n";

        delete[] arr;
    }

    data_file.close();
}



       
} // namespace sortlib

#endif // SORTLIB_H
