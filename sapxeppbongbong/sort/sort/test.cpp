﻿#include "pch.h"
#include <algorithm>
class ArraySorter {
private:
    int* arr;
    int size;

public:
    ArraySorter(int array[], int arraySize) : arr(array), size(arraySize) {}

    void BubbleSort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Hoán đổi giá trị của hai phần tử
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void PrintArray() {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};
TEST(ArraySorterCaseName, BubbleSortName) {
    int arr[] = { 2, 4, 0, 1, 9, 8 };
    int size = sizeof(arr) / sizeof(arr[0]);
    ArraySorter sort(arr, size);
    sort.BubbleSort();

    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[1], 1);
    EXPECT_EQ(arr[2], 2);
    EXPECT_EQ(arr[3], 4);
    EXPECT_EQ(arr[4], 8);
    EXPECT_EQ(arr[5], 9);
}