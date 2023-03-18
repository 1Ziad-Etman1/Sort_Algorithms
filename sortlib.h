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

    template <class T>
    int partition (T Array[], int Start, int End)
    {
        int p = Array[Start];
        int i = Start - 1;
        int j = End + 1;

        while (true)
        {
            do
            {
                i++;
            }
            while (Array[i] < p);

            do
            {
                j--;
            }
            while (Array[j] > p);

            if (i >= j)
            {
                return j;
            }

            swap(Array[i], Array[j]);
        }
    }

    template <class T>
    void quick_sort (T Array[] , int Start , int End)
    {
        if (Start < End)
        {
            int pivot = partition (Array,Start,End);
            quick_sort (Array,Start,pivot);
            quick_sort (Array,pivot+1,End);
        }
    }

    template <class T>
    void Merge (T mainArr[], int Start, int Mid, int End)
    {
        int i, j, k;
        int Size1, Size2;
        Size1 = Mid - Start + 1;
        Size2 = End - Mid;
        T *array1 = new T[Size1];
        T *array2 = new T[Size2];

        for (i = 0; i < Size1; i++)
            array1[i] = mainArr[Start+i];
        for (j = 0; j < Size2; j++)
            array2[j]= mainArr[Mid + 1 + j];

        i = j = 0;
        k = Start;

        while (i < Size1 && j < Size2)
        {
            if (array1[i] < array2[j])
            {
                mainArr[k] = array1[i];
                i++;
            }
            else
            {
                mainArr[k] = array2[j];
                j++;
            }
            k++;
        }
        while (i < Size1)
        {
            mainArr[k] = array1[i];
            i++;
            k++;
        }
        while (j < Size2)
        {
            mainArr[k] = array2[j];
            j++;
            k++;
        }
        delete [] array1;
        delete [] array2;
    }

    template <class T>
    void merge_sort (T mainArr[], int Start, int End)
    {
        if (Start < End)
        {
            int mid = (Start + End) / 2;
            merge_sort(mainArr, Start, mid);
            merge_sort(mainArr, mid+1, End);
            Merge(mainArr, Start, mid, End);
        }
    }

    template<typename T>
    void insertion_sort(T arr[], int size)
    {
        for (int i=1,j ; i<size ;i++)
        {

            T temp = arr[i];
            for (j=i ; j>0&&temp<arr[j-1] ;j--)
            {
                arr[j]=arr[j-1];
            }
            arr[j]=temp;
        }
    }


    template<typename T>
    void selection_sort(T arr[], int size)
    {
        int index=0;
        for (int i = 0, j ; i < size ; i++)
        {
            int min = arr[i];
            index = i;
            for (j = i ; j < size ; j++)
            {
                if (arr[j]<min)
                {
                    min = arr[j];
                    index = j;
                }
            }
            if(index != i)
                swap(arr[i], arr[index]);
        }
    }


    template<typename T>
    void bubble_sort(T arr[], int size)
    {
        for (int i=0 ; i<size-1 ;i++)
        {
            for (int j=0 ; j<size-i-1 ;j++)
            {
                if (arr[j]>arr[j+1])
                {
                    swap(arr[j],arr[j+1]);
                }
            }
        }
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

        /*Shell Sort*/
        auto start = chrono::high_resolution_clock::now();
        sortlib::shell_sort(arr, size);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> shell_sort_time = end - start;

        cout << "Shell Sort:" << endl;
        cout << "Size: " << size << "\n";
        cout << "Time elapsed: " << shell_sort_time.count() << " microseconds\n";
        cout<<"\n\n**********************************************\n\n";

        /*Count Sort*/
        start = chrono::high_resolution_clock::now();
        sortlib::count_sort(arr, size);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> count_sort_time = end - start;

        cout << "Count Sort:" << endl;
        cout << "Size: " << size << "\n";
        cout << "Time elapsed: " << count_sort_time.count() << " microseconds\n";
        cout<<"\n\n**********************************************\n\n";

        /*Insertion Sort*/
        start = chrono::high_resolution_clock::now();
        sortlib::insertion_sort(arr, size);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> insertion_sort_time = end - start;

        cout << "Insertion Sort:" << endl;
        cout << "Size: " << size << "\n";
        cout << "Time elapsed: " << insertion_sort_time.count() << " microseconds\n";
        cout<<"\n\n**********************************************\n\n";

        /*Selection Sort*/
        start = chrono::high_resolution_clock::now();
        sortlib::selection_sort(arr, size);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> selection_sort_time = end - start;

        cout << "Selection Sort:" << endl;
        cout << "Size: " << size << "\n";
        cout << "Time elapsed: " << selection_sort_time.count() << " microseconds\n";
        cout<<"\n\n**********************************************\n\n";

        /*Bubble Sort*/
        start = chrono::high_resolution_clock::now();
        sortlib::bubble_sort(arr, size);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> bubble_sort_time = end - start;

        cout << "Bubble Sort:" << endl;
        cout << "Size: " << size << "\n";
        cout << "Time elapsed: " << bubble_sort_time.count() << " microseconds\n";
        cout<<"\n\n**********************************************\n\n";

        /*Merge Sort*/
        start = chrono::high_resolution_clock::now();
        sortlib::merge_sort(arr, 0, size-1);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> merge_sort_time = end - start;

        cout << "Merge Sort:" << endl;
        cout << "Size: " << size << "\n";
        cout << "Time elapsed: " << merge_sort_time.count() << " microseconds\n";
        cout<<"\n\n**********************************************\n\n";

        /*Quick Sort*/
        start = chrono::high_resolution_clock::now();
        sortlib::quick_sort(arr, 0, size-1);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> quick_sort_time = end - start;

        cout << "Quick Sort:" << endl;
        cout << "Size: " << size << "\n";
        cout << "Time elapsed: " << quick_sort_time.count() << " microseconds\n";
        cout<<"\n\n**********************************************\n\n";

        data_file << size << "," << shell_sort_time.count() << "," << count_sort_time.count() <<
        quick_sort_time.count() << "," << merge_sort_time.count() <<
        insertion_sort_time.count() << "," << selection_sort_time.count() <<
        bubble_sort_time.count() <<  "\n";



        delete[] arr;
    }

    data_file.close();
}




} // namespace sortlib

#endif // SORTLIB_H
