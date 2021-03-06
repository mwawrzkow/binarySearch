#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <vector>
#include <algorithm>
template <typename T>
int binarySearch(T arr[], int size, T key, int low, int high)
{   
    if (low > high)
        return -1;
    while (low <= high)
    {
        int m = (low + high) / 2;
        if (arr[m] < key)
        {
            low = m + 1;
        }
        else if (arr[m] > key)
        {
            high = m - 1;
        }
        else
        {
            return m;
        }
    }
    return -1;
}
void print_usage()
{
    printf("Usage: ./binarySearch <array_size> <key>\n");
    printf("Example: ./binarySearch 1000000 1000000\n");
}
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        print_usage();
        return -1;
    }
    int size = atoi(argv[1]);
    int *arr = new int[size];
    //output the initializing array
    printf("Initializing array:\n");
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
    int key = atoi(argv[2]);
    int low = 0;
    int high = size - 1;
    printf("Searching for %d in array:\n", key);
    auto start = std::chrono::high_resolution_clock::now();
    int index = binarySearch(arr, size, key, low, high);
    auto finish = std::chrono::high_resolution_clock::now();
    if (index == -1)
    {
        printf("%d not found\n", key);
    }
    else
    {
        printf("%d found at index %d\n", key, index);
    }
    std::vector<int> v(arr, arr + size);
    auto start_stl = std::chrono::high_resolution_clock::now();
    auto it = std::lower_bound(v.begin(), v.end(), key);
    auto finish_stl = std::chrono::high_resolution_clock::now();
    //free 
    delete[] arr;
    if (it == v.end())
    {
        printf("%d not found\n", key);
    }
    else
    {
        printf("%d found at index %d\n", key, std::distance(v.begin(), it));
    }
    
    auto start_timer = std::chrono::high_resolution_clock::now();
    auto it_binary_search = std::binary_search(v.begin(), v.end(), key);
    auto finish_timer = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::chrono::duration<double> elapsed_stl = finish_stl - start_stl;
    std::chrono::duration<double> elapsed_timer = finish_timer - start_timer;
    printf("STL Search Steps: %ld\n", std::distance(v.begin(), it));
    printf("Binary Search Time: %f\n", elapsed.count());
    printf("STL Search Time: %f\n", elapsed_stl.count());
    printf("STL- binarysearch Search Time: %f\n", elapsed_timer.count());

    return 0;
}