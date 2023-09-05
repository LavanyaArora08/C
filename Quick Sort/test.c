#include "Quick.c"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// function prototypes
int partition(int arr[], int low, int high, int *f);
void quicksort(int arr[], int low, int high, int *f);

// unit test functions
void test_partition() {
    int arr[] = {5, 2, 8, 3, 6, 1, 9, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int f = 0;
    int j = partition(arr, 0, n - 1, &f);
    assert(j == 4);
    for (int i = 0; i < j; i++) {
        assert(arr[i] <= arr[j]);
    }
    for (int i = j + 1; i < n; i++) {
        assert(arr[i] > arr[j]);
    }
}

void test_quicksort() {
    int arr[] = {5, 2, 8, 3, 6, 1, 9, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int f = 0;
    quicksort(arr, 0, n - 1, &f);
    for (int i = 0; i < n - 1; i++) {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_empty_array() {
    int arr[] = {};
    int n = sizeof(arr) / sizeof(arr[0]);
    int f = 0;
    quicksort(arr, 0, n - 1, &f);
    assert(n == 0);
}

void test_single_element_array() {
    int arr[] = {5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int f = 0;
    quicksort(arr, 0, n - 1, &f);
    assert(n == 1);
}

int main() {
    test_partition();
    test_quicksort();
    test_empty_array();
    test_single_element_array();
    printf("All tests passed successfully.\n");
    return 0;
}