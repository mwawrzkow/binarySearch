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
    auto start = std::chrono::high_resolution_clock::now();
    int size = atoi(argv[1]);
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
    std::sort(arr, arr + size);
    int key = atoi(argv[2]);
    int low = 0;
    int high = size - 1;
    int index = binarySearch(arr, size, key, low, high);
    if (index == -1)
    {
        printf("%d not found\n", key);
    }
    else
    {
        printf("%d found at index %d\n", key, index);
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    printf("Elapsed time: %f\n", elapsed.count());
    return 0;
}